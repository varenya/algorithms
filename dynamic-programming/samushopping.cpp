#include <iostream>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;
const int MAX = 1e5+7;
ll dp[MAX][3];
ll input[MAX][3];

int main(void){
	int T,N;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				cin >> input[i][j];	
			}
		}

		for(int j=0;j<3;j++){
			dp[0][j] = input[0][j];
		}
		for(int i=1;i<N;i++){
			ll temp =LONG_MAX;
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if( k != j){
						temp = min(temp,input[i][j]+dp[i-1][k]);
						//cout << "temp " << temp << endl;
						//cout << "input " << input[i][j] << endl;
						//cout << "prev " << dp[i-1][j] << endl;
					}
					dp[i][j] = temp;
				}
			}
		}
		/*
		cout << endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<3;j++){
				cout << dp[i][j] << " " ;	
			}
			cout << endl;
		}
		*/
		ll ans = dp[N-1][0];
		for(int j=1;j<3;j++){
			ans = min(ans,dp[N-1][j]);
		}
		cout << ans << endl;

	}
}
