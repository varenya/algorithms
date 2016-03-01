#include <iostream>
#include <algorithm>

using namespace std;

void insertionSort(int *,int n);
void printArray(int *,int);

int main(){

	int a[] = {6,2,1,3,5,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "before sorting ..." << endl;
	printArray(a,n);
	insertionSort(a,n);
	cout << "after sorting ..." << endl;
	printArray(a,n);
}


void insertionSort(int a[],int n){

	for(int j=1;j<n;j++){

		int key = a[j];
		int i = j-1;
		while( i >= 0 && key <= a[i] ){
			a[i+1] = a[i];
			a[i] = key;
			i--;
		}
	}

}

void printArray(int a[],int n){
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}
