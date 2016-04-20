#include <iostream>
#define ll long long
using namespace std;


ll count_ones(ll n){

	ll count = 0;
	while(n){
		n = n & (n-1);
		count++;
	}
	return count;
}

int main(void){

	int T;
	cin >> T;
	ll P,M;
	while(T--){
		cin >> P >> M;
		cout << count_ones(P ^ M) << endl;
	}
}
