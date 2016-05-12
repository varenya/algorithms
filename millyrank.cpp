#include <iostream>
#include <algorithm>
#include <stdio.h>
#define ll long long
using namespace std;
int main(void){
	int T;
	cin >> T;
	while(T--){
		ll N,X,Y;
		cin >> N >> X >> Y;
		ll count=0;
		ll start = max(X+1,N-Y);
		count = N-start+1;
		cout << count << endl;
	}
}
