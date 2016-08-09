#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
const int MAX = 1e5+5;
ll A[MAX];

ll dp[MAX];
int N,K;

ll maxSum(int i){
	if(i > N){
		return 0;
	}
	else if(dp[i] != -1){
		return dp[i];
	}
	else {
		cout << i << " " << endl;
		dp[i] = max( maxSum(i+1) ,A[i]+maxSum(i+K+1) );
		return dp[i];
	}
}
int main(void){

	int T;
	cin >> T;
        //int right[MAX];
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> N >> K;
		ll temp;
		for(int i=1;i<=N;i++){
			cin >> A[i];
		}
		ll result = maxSum(1);

		cout << result << endl;

	}
}

