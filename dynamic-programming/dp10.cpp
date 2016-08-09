#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int primes[] = {2,3,5,7};

bool possible = false;

const ll MAX = 1e6;

ll dp[MAX];

ll minPrimes(ll num){

	//cout << " Num : " << num << endl;
	if ( num < 0 ){
		return 1e6;
	}
	else if ( num == 0 ){
		possible = true;
		return 0;
	}
	else if(dp[num] != -1){
		return dp[num];
	}
	else{
		ll  ans = 1e6;
		for(int i=0;i<4;i++){
			ans = min( ans,1 + minPrimes(num-primes[i]) );
		}
		dp[num] = ans;
		return dp[num];
	}
}


int main(void){

	int T;
	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		possible = false;
		ll N;
		cin >> N;
		ll ans = minPrimes(N);
		if ( possible )
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
}
