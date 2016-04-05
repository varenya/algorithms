#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#define MAX 100007
int arr[MAX];
int size[MAX];
using namespace std;


void initialize(int N){
	for(int i=0;i<=N;i++){
		arr[i] = i;
		size[i] = 1;
	}
}


int root(int i){
	while( arr[i] != i){
		i = arr[i];
	}
	return i;
}

bool find(int A,int B){
	return root(A) == root(B);
}

void union_set(int N,int A,int B){

	int root_A = root(A);
	int root_B = root(B);
	if ( size[root_A] < size[root_B]){
		arr[root_A] = arr[root_B];
		size[root_B] += size[root_A];
	}
	else{
		arr[root_B] = arr[root_A];
		size[root_A] += size[root_B];
	}

}

void printArray(int N){
	for(int i=0;i<N;i++)
		cout << arr[i] << " ";
	cout << endl;
}



int main(void){

	memset(arr,0,sizeof arr);
	set <int> unique;
	int N,K;	
	cin >> N >> K;
	initialize(N);
	while(K--){
		int i,j;
		cin >> i >> j;
		//cout << i << j << endl;
		union_set(N,i,j);
	}
//	printArray(N);

	int count = 0;
	
	for(int i=1;i<=N;i++){
		if(root(i) == i)
			count ++;
	}

	cout << count << endl;
}
