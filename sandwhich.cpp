#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int main(void){
	int T;
	ll N,P;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&N,&P);
		while(P--){
			if ( !(N & 1) ){
				N = N >> 1;
				N ++;
			}
			else{
				N = N >> 1;
				N += 2;
			}
		}
		cout << N << endl;
	}
}
