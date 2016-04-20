#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h>
#define ll long long
#define MAX 100007
using namespace std;
ll army[MAX];

int main(void){
	int T;
	cin >> T;
	ll N,E,V;
	while(T--){
		scanf("%lld %lld %lld",&N,&E,&V);
		for(int i=0;i<N;i++)
		{
			scanf("%lld",&army[i]);
		}
		ll count = 0;
		ll energy = E;
		ll temp;
		for(int i=0;i<N;i++){
			if( energy > army[i] ){
				energy -= army[i];
			}
			else{
				temp = (army[i]-energy)/V;
				energy += temp * V;
				if ( energy > army[i] )
					count += temp;
				else{
					energy += V;
					count += temp+1;
				}
				energy -= army[i];
			}
		}
		cout << count << endl;
	}
	return 0;

}
