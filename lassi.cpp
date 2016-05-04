#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 1e5+7;
ll cost[MAX];
ll dp[MAX];
int L;

ll max_profit(int litres){
	dp[0] = 0;
	for(int j=1;j<=litres;j++){
		ll q = -100;
		for(int i=1;i<=j;i++){
			q = max(q,cost[i]+dp[j-i]);
		}
		dp[j] = q;
	}
	return dp[litres];
}

int main(void){
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
		memset(cost,0,sizeof cost);
		memset(dp,-1,sizeof dp);
		cin >> L;
		for(int i=1;i<=L;i++){
			cin >> cost[i];
		}
		cout << max_profit(L) << endl;
	}
}
