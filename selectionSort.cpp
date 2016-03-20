#include <iostream>
using namespace std;


void printArray(int a[],int n){
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}
void selectionSort(int a[],int n){
  for(int i=0;i<n-1;i++){
    int min = a[i],temp;
    for(int j=i+1;j<n;j++){
      if(a[j] < min){
        min = a[j];
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
    printArray(a,n);
  }
}

int main(){

	int a[] = {6,2,1,3,5,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "before sorting ..." << endl;
	printArray(a,n);
	selectionSort(a,n);
	cout << "after sorting ..." << endl;
	printArray(a,n);
}
