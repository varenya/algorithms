#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

const int MAX = 1e5+7;
int credit[MAX];
int dp[MAX];

int main(void){

	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> credit[i];
		dp[i] = 1;
	}
	//memset( dp,1,sizeof(dp) );

	for(int i=1;i<N-1;i++){
		if ( credit[i] > credit[i-1] )
			dp[i] = dp[i-1] + 1;
		else if ( credit[i] > credit[i+1] )
			dp[i] = dp[i] + dp[i+1] + 1;
	}

	if( credit[N-1] > credit[N-2] )
		dp[N-1] = dp[N-2]+1;

	ll ans = 0;
	for(int i=0;i<N;i++)
		ans += dp[i];

	cout << ans << endl;
}
