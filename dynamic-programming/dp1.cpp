#include <iostream>
#include <stdio.h>
#include <map>
#include <cstring>
using namespace std;
#define ll long long

const ll MOD = 1e9 + 7;

const int MAX = 1e5+5;

ll fact[MAX];


ll factorial(ll n){
	if(n==0){
		return 1;
	}
	else if(fact[n] != -1){
		return fact[n];
	}
	else{
		fact[n] = n*factorial(n-1);
		return fact[n];
	}

}

int main(void){
	int T,N;
	scanf("%d",&T);
	memset(fact,-1,sizeof(fact));
	while(T--){
		scanf("%d",&N);
		printf("%lld\n",factorial(N));
	}
}
