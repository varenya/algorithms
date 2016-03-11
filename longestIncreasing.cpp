#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[],int n);

int _lis(int arr[],int n,int& max_ref)
{


	cout << "n :" << n << " max ref : " << max_ref << endl;
	printArray(arr,n);

	if(n == 1)
		return 1;

	int res,max_end_here = 1;

	for(int i=1;i<n;i++){
		res = _lis(arr,i,max_ref);
		cout << "Inside Loop" << endl;
		cout << arr[i-1] << " " << arr[n-1] << " i " << i << " n " << n << " res : " << res << " max_end_here :" << max_end_here << endl;
		if(arr[i-1] < arr[n-1] && res+1 > max_end_here)
			max_end_here = res+1;
	}

	if(max_ref < max_end_here)
		max_ref = max_end_here;

	return max_end_here;

}

void printArray(int arr[],int n){
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
}

int lis(int arr [],int n){

	int max = 1;
	_lis(arr,n,max);
	return max;
}



int main()
{

	int arr[] = {1,10,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << lis(arr,n) << endl;
}
