#include <iostream>
using namespace std;


int* mergeSort(int a[],int low,int high){

	if ( low == high)
		return a[low];

	int mid = (low+high)/2;

	int a_left[mid-low+1] = mergeSort(a,low,mid);
	int a_right[high-mid] = mergeSort(a,mid+1,high);

	int merge[high-low+1] = merge(a_left,a_right);

	return merge;

}
