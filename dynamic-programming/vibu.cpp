#include <iostream>
#include <vector>
#define ll long long
using namespace std;
const ll MAX = 1e6+5;
const ll MOD = 1e9+7;
ll arr[MAX];
int main(void){
	int T;
	cin >> T;
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2;i<=MAX;i++){
		arr[i] = (i-1)* arr[i-2];
		arr[i] += arr[i-1];
		arr[i] %= MOD;
	}
	while(T--){
		ll N;
		cin >> N;
		cout << arr[N] << endl;
	}
	return 0;
}
