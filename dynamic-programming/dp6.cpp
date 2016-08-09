#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define ll long long

const int MAX = 1e4+5;
int N;

ll judges[MAX];

ll dp[MAX];

ll getMax(int i){
	if( i >= N){
		return 0;
	}
	else if(dp[i] != -1){
		return dp[i];
	}
	else{
		dp[i] = max(judges[i] + getMax(i+2),getMax(i+1));
		return dp[i];
	}
}


int main(void){
	int T;
	cin >> T;
	for(int tc=1;tc<=T;tc++){
		memset(dp,-1,sizeof(dp));
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> judges[i];
		}


		cout << "Case " << tc << ": " << getMax(0) << endl;

	}
}
