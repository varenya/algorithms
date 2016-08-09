#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define ll long long

map <char,int> freq;

bool isBalanced(string s1){

	map <char,int>::iterator it;

	for(int i=0;i<s1.size();i++){
		freq[s1[i]]++;
	}

	for(it=freq.begin();it!=freq.end();it++){
		if( it->second % 2 != 0){
			return false;
		}
	}
	return true;
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		freq.clear();
		string s1;
		cin >> s1;
		if( isBalanced(s1) ){
			cout << 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}
