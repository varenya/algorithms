#include <iostream>
#define MAX 1000007
long long freq[MAX] = {0};
long long arr[MAX] = {0};
long long arr_copy[MAX] = {0};
using namespace std;

void printArray(long long a[],int N);
void merge(long long a[],int low,int mid,int high);
void mergeSort(long long a[],int low,int high){
  if (low < high){
    int mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    // cout << "printArray" << endl;
    // printArray(a,high-low+1);
    merge(a,low,mid,high);
  }
}


void merge(long long a[],int low,int mid,int high){
  int i=0,j=0,k=0;
  int n1 = mid-low+1;
  int n2 = high - mid;
  long long L[n1],R[n2];
  for(i=low;i<=mid;i++)
  {
    L[k] = a[i];
    k++;
  }
  k = 0;
  for(j=mid+1;j<=high;j++)
  {
    R[k] = a[j];
    k++;
  }
  // cout << "Left" << endl;
  // printArray(L,n1);
  // cout << "Right" << endl;
  // printArray(R,n2);
  i=0,j=0,k=low;
  while(i < n1 && j < n2){
    if(L[i] <= R[j])
    {
      // cout << "Inside" << endl;
      a[k] = L[i];
      k++;
      i++;
    }
    else
    {
      // cout << "outside" << endl;
      a[k] = R[j];
      for(int t=i;t<n1;t++)
      {
        // cout << "frequency" << endl;
        // cout << L[t] << endl;
        freq[L[t]-1] += 1;
      }
      k++;
      j++;
    }
  }

  if (i!=n1){

    while (i < n1) {
      a[k] = L[i];
      k++;
      i++;
    }

  }
  if(j!=n2){
    while (j < n2) {
      a[k] = R[j];
      k++;
      j++;
    }

  }
}

void printArray(long long a[],int N){
  for (int i = 0; i < N; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

int main(void){
  int T,N;
  cin >> T;
  for(int c=0;c<T;c++){
    for(int i=0;i<MAX;i++)
          freq[i] = 0;
    cin >> N;
    for(int i=0;i<N;i++){
      cin >> arr[i];
      arr_copy[i] = arr[i];
    }
    // printArray(arr,N);
    // printArray(arr_copy,N);
    if(N!=1){
      mergeSort(arr,0,N-1);
      // cout << "sortedArray" << endl;
      // printArray(arr,N);
      for(int i=0;i<N;i++)
        cout << freq[arr_copy[i]-1] << " ";
      cout << endl;
    }
    else{
      cout << "0" << endl;
    }
  }
}
