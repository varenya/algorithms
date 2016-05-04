#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <utility>
#define ll long long
#define mk make_pair
#define pll pair <ll,ll> 

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;

using namespace std;

void printVector(vector <ll> heights){

	vector <ll>::iterator it;
	for(it=heights.begin();it!=heights.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}
vector <ll> input;

int lower(int value){
	//vector <ll>::iterator it;
	for(int i=0;i<input.size();i++){
		if( input[i] >= value)
			return i+1;
	}
	return -1;
}

int main(void){
	int N,Q;
	cin >> N >> Q;
	ll temp;
	while(N--){
		cin >> temp;
		input.push_back(temp);
	}
	int operation,x,y,v;
	vector <ll>::iterator it;
	while(Q--){
		cin >> operation;
		if( operation == 0){
			cin >> x >> y;
			input[x-1] = y;
		}
		else{
			cin >> v;
			cout << lower(v) << endl;
		}

	}
	
	return 0;
}
