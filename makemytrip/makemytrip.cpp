#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <utility>
#define ll long long
#define mp make_pair
#define pll pair <ll,ll> 

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;


ll count_substring(string s,ll N,char X,char Y){
	ll inc = 0;
	ll count = 0;
	for(int i=0;i<N;i++){
		if( s[i] == X)inc++;
		if( s[i] == Y) count += inc;
	}
	return count;
}


int main(void){
	ll N;
	cin >> N;
	string s1;
	cin >> s1;
	map <char,ll> freq;
	for(char ch='a';ch <='z';ch++){
		freq[ch] = 0;
	}
	for(int i=0;i<s1.size();i++){
		freq[s1[i]]++;
	}
	int Q;
	cin >> Q;
	char X,Y;
	while(Q--){
		cin >> X >> Y;
		ll result;
		if ( X!=Y ){
			cout << freq[X] * freq[Y] << endl;
		}
		else
		{
			cout << freq[X] * freq[X]/2 << endl;
		}

	}
	return 0;
}

