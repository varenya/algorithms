#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll L;
vector <ll> upper;
vector <ll> lower;

ll timeTaken(int index){
	cout << "index : " << index << " Lower : " << lower[index] << " Upper : " << upper[index] << endl;
	ll maxRope = max(lower[index],upper[index]);
	if ( index >= L-1 ){
		return 0;
	}

	else if( maxRope > 0){
		lower[index]--;
		upper[index]--;
		return 1 + timeTaken(index) + timeTaken(index+1);
	}
	else {
		return 0;
	}
}


int main(void){
	int T;
	cin >> T;
	while(T--){
		cin >> L;
		ll temp;
		for(int i=1;i<L;i++){
			cin >> temp;
			upper.push_back(temp);
		}
		for(int i=1;i<L;i++){
			cin >> temp;
			lower.push_back(temp);
		}
		cout << timeTaken(0) << endl;
	}
}
