#include <iostream>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;

void printVector(vector <ll> input){
	vector <ll>::iterator it;
	for(it = input.begin();it!=input.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main(void){
	int T;
	cin >> T;
	ll N,K,P,temp;
	while(T--){
		vector <ll> input;
		scanf("%lld %lld %lld",&N,&K,&P);
		for(int i=1;i<=N;i++)
			input.push_back(i);
		vector <ll>::iterator it;
		while(K--){
			scanf("%lld",&temp);
			it = lower_bound(input.begin(),input.end(),temp);
			input.erase(it);
		}
	//	cout << "After" << endl;
	//	printVector(input);
	//	cout << "Before" << endl;
		if(input.size() >= P)
			cout << input[P-1] << endl;
		else
			cout << -1 << endl;
	}
}
