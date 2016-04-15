#include <iostream>
#include <set>
#include <algorithm>
#define ll long long
#define MAX 100000
ll a[MAX];

using namespace std;

void initialize(ll N){
	for(int i=1;i<=N;i++)
		a[i] = 1;
}

int main(void){
	int T;
	cin >> T;
	ll N,K,P,temp;
	while(T--){
		cin >> N >> K >> P;
		initialize(N);
		while(K--){
			cin >> temp;
			a[temp]--;
			N--;
		}
		if( P <= N){
			if( a[P]!=0 )
				cout << P << endl;
			else 
				cout << P+1 << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}
