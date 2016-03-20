#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void insertionSort(int a[],int n){
  int key,j;

  for(int i=1;i<n;i++){
    key = a[i];
    j = i-1;
    while(j>=0 && a[j] <= key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = key;

  }
}

void printArray(int arr[],int n){
  for(int i=0;i<n;i++)
        cout << arr[i] << " ";
  cout << endl;
}

int main(){
	int a[] = {6,2,1,3,5,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "before sorting ..." << endl;
	printArray(a,n);
	insertionSort(a,n);
	cout << "after sorting ..." << endl;
	printArray(a,n);

}
