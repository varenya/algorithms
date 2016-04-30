#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int X,Y,N,W;
double P1,P2;
double dp[1005][1005];
int vis[1005][1005];


double max_probability(int idx,int totalPoints){

	if ( totalPoints > W) totalPoints = W;
	if ( vis[idx][totalPoints] != -1){

	        //cout << "idx : " << idx << " totalPoints : " <<  totalPoints << endl;
		//cout << "dynamic !" << endl;
		//cout << dp[idx][totalPoints] << endl;

		return dp[idx][totalPoints];

	}
	if( idx == N){
		if ( totalPoints == W ) return 1.0;
		else return 0.0;
	}
	double first = -1 ,second = -1;
	first = P1* max_probability(idx+1,X+totalPoints)+ (1.0-P1)* max_probability(idx+1,totalPoints);
	second = P2* max_probability(idx+1,Y+totalPoints)+ (1.0-P2)* max_probability(idx+1,totalPoints);
	vis[idx][totalPoints] = 1;
	dp[idx][totalPoints] = max(first,second);
	//cout << "frist : " << first << endl;
	//cout << "second : " << second << endl;
	return dp[idx][totalPoints];
}

int main(void){
	int T;
	cin >> T;
	while(T--){

		memset(vis,-1,sizeof vis);
		cin >> X >> Y >> N >> W >> P1 >> P2;
		//cout << "P1  :" << P1 << endl;
		P1 = (double)P1/(double)100.0;
		P2 = (double)P2/(double)100.0;
		double ans = max_probability(0,0) * 100;
		printf("%.6f\n",ans);

	}
}
