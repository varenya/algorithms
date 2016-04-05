#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
#define MAX 100007
#define ll long long
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
void printVector(vector <ll> input){

	vector <ll>::iterator it;
	for(it = input.begin();it!=input.end();it++)
		cout << *it << " ";
	cout << endl;
}

int getDifference(int N){

	ll diff = 0;
	vector <ll> unique;
	for(int i=1;i<=N;i++){

		ll count = 0;
		for(int j=1;j<=N;j++){
			if(root(j) == i)
				count ++;
		}
		if (count)
			unique.push_back(count);
	}
	if ( unique.size() !=0){
		sort(unique.begin(),unique.end());
		//cout << "Vector " << endl;
		//printVector(unique);
		diff = unique.back()-unique.front();
	}
	return diff;
}



int main(void){

	memset(arr,0,sizeof arr);
	int N,Q;	
	cin >> N >> Q;
	initialize(N);
	while(Q--){
		int i,j;
		cin >> i >> j;
		//cout << i << j << endl;
		union_set(N,i,j);
		cout << getDifference(N) << endl;
	}
//	printArray(N);

	

}
