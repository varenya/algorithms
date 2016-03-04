#include <iostream>
#include <algorithm>

using namespace std;


int _lis(int arr[],int n,int& max_ref)
{



	if(n == 1)
		return 1;

	int res,max_end_here = 1;

	for(int i=1;i<n;i++){
		res = _lis(arr,i,max_ref);
		if(arr[i-1] < arr[n-1] && res+1 > max_end_here)
			max_end_here = res+1;
	}

	if(max_ref < max_end_here)
		max_ref = max_end_here;

	return max_end_here;

}

int lis(int arr [],int n){

	int max = 1;
	_lis(arr,n,max);
	return max;
}



int main(){

	int arr[] = {1,10,3,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << lis(arr,n) << endl;
}
