#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int lis(int arr[],int n){

	int * lis = (int *) malloc(sizeof(int) * n);

	for(int i=0;i<n;i++)
		lis[i]=1;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i] && lis[j]+1 > lis[i]) {
				lis[i] = lis[j] +1;
			}

		}
	}
	int max = lis[0];
	for(int i=1;i<n;i++)
	{
		if(max < lis[i])
			max = lis[i];
	}
	free(lis);
	return max;
}

int main(void){
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr)/sizeof(arr[0]);
	printf("Length of LIS is %d\n", lis( arr, n ) );
	return 0;
}
