#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long
bool jack;
const int MAX = 1e5 + 5;
ll memo[MAX];
ll numOfSteps(int num){

	if(num < 0){
		return 0;
	}
	else if(memo[num]!=-1){
		return memo[num];
	}
	else{
		if(jack){
			//cout << "Jack" << endl;
			memo[num] =  numOfSteps(num-1) + numOfSteps(num-2) + numOfSteps(num-3);
			return memo[num];
		}
		else{
			//cout << "Jill " << num << endl;
			memo[num] =  numOfSteps(num-1) + numOfSteps(num-2);
			return memo[num];
		}
	}
}
int main(void){

	int N;
	cin >> N;

	if( N < 1){
		cout << "ERROR" << endl;
		return 0;
	}

	memset(memo,-1,sizeof(memo));
	memo[0] = 1;
	jack = true;
	cout << "Jack-" << numOfSteps(N) << endl;
	memset(memo,-1,sizeof(memo));
	jack = false;
	memo[0] = 1;
	cout << "Jill-" << numOfSteps(N) << endl;
	//printf("Jack-%lld\n",numOfSteps(N));
}
