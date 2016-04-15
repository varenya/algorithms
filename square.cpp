#include <iostream>
#include <vector>
#include <algorithm>
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
	vector <ll> input;
	vector <ll> sums;
	while(T--){
		ll temp;
		cin >> temp;
		input.push_back(temp);
	}
	ll sum = 0;
	for(int i=0;i<input.size();i++){
		sum += input[i];
		sums.push_back(sum);
	}
	//cout << "Sums :" << endl;
	//printVector(sums);
	//cout << "Answers : " << endl;
	ll Q,target;
	cin >> Q;
	vector <ll>::iterator it;
	//cout << "Answers Again: " << endl;
	while(Q--){
		cin >> target;
		it = lower_bound(sums.begin(),sums.end(),target);
		if(it != sums.end())
			cout << it-sums.begin()+1<< endl;
		else
			cout << -1 << endl;
	}

}
