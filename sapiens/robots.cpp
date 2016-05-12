#include <iostream>
#define ll long long
using namespace std;
const ll MOD = 1e9+7;
int main(void){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		ll result=1;
		int temp;
		for(int i=0;i<N;i++){
			cin >> temp;
			result = (result * (temp-i))%MOD;
		}
		cout << result % MOD << endl;

	}
}
