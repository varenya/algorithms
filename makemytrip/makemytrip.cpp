#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <set>
#include <vector>
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
	int Q;
	cin >> Q;
	char X,Y;
	while(Q--){
		cin >> X >> Y;
		ll result;
		if ( X!=Y )
			result = count_substring(s1,N,X,Y) + count_substring(s1,N,Y,X);
		else
			result = count_substring(s1,N,X,Y);

		cout << result << endl;
	}
	return 0;
}

