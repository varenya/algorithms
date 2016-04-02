#include <iostream>
using namespace std;

void printArray(int a[],int n);

int left(int i){

	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int parent(int i){
	return i/2;
}

void swap(int a[],int first,int second){
	int temp;
	temp = a[first];
	a[first] = a[second];
	a[second] = temp;
}



void maxHeapify(int a[],int i,int heap_size){

	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l<heap_size && a[l] > a[i]){
		largest = l;
	}
	if(r<heap_size && a[r] > a[largest]){
		largest = r;
	}
	if (largest !=i){
		swap(a,i,largest);
		maxHeapify(a,largest,heap_size);
	}

}

void buildMaxHeap(int a[],int n){
	int heap_size = n;
	for(int i=n/2;i>=0;i--)
		maxHeapify(a,i,n);
}

void heapSort(int a[],int n){
	buildMaxHeap(a,n);
	//printArray(a,n);
	int size = n;
	for(int i=n-1;i>=1;i--){
		swap(a,0,i);
		size -= 1;
		maxHeapify(a,0,size);
	//	printArray(a,n);
	}
}

void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout << a[i] << " ";
	}
	cout << endl;
}



int main(void){

	int a[] = {4,1,3,2,16,9,10,14,8,7};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "before " << endl;
	printArray(a,n);
	heapSort(a,n);
	cout << "after " << endl;
	printArray(a,n);



}
