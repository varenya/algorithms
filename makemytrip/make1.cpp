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

char X,Y;

set <pll> seen;
ll countSubstring(string s,int N){
	ll count = 0;
	for(int i=0;i<N;i++){
		if(s[i] == X || s[i] == Y){

			for(int j=i+1;j<N;j++){

				if(X == Y & s[j] == X){
					count ++;
				}
				else if( s[i] == X && s[j] == Y)
					count++;
				else if( s[i] == Y && s[j] == X)
					count++;
			}
		}
	}
	return count;
}

ll count_Substring(string s,int N){
	ll count = 0;
	ll mid = (N-1)/2;
	int i=0;
	int j = N-1;
	ll countX = 0;
	ll countY = 0;
	while(i < j){
		if( s[i] == X || s[i] == Y)

			countX ++;
		if( s[j] == X || s[j] == Y)
			countY ++;
		i++;
		j--;

	}
	return countX+countY;
}

int main(void){
	ll N;
	cin >> N;
	string s1;
	cin >> s1;
	int Q;
	cin >> Q;
	while(Q--){
		cin >> X >> Y;
		cout << count_Substring(s1,N) << endl;

	}
	return 0;
}

