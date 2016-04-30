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


double max_probability(int turns,int totalPoints);

double max_probability(int turns,int totalPoints){

	if ( totalPoints > W) totalPoints = W;
	if ( vis[turns][totalPoints] != -1){

	        //cout << "turns : " << turns << " totalPoints : " <<  totalPoints << endl;
		//cout << "dynamic !" << endl;
		//cout << dp[turns][totalPoints] << endl;

		return dp[turns][totalPoints];

	}
	if( turns == 0)
		if ( totalPoints == W ) return 1.0;
		else return 0.0;
	}
	double first = P1* max_probability(turns-1,X+totalPoints)+ (1.0-P1)* max_probability(turns-1,totalPoints);
	double second = P2* max_probability(turns-1,Y+totalPoints)+ (1.0-P2)* max_probability(turns-1,totalPoints);
	vis[turns][totalPoints] = 1;
	dp[turns][totalPoints] = max(first,second);
	//cout << "frist : " << first << endl;
	//cout << "second : " << second << endl;
	return dp[turns][totalPoints];
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
		double ans = max_probability(N,0) * 100;
		printf("%.6f\n",ans);

	}
}
