#include <queue>
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
int main(void){

	int T,N,K;
	cin >> T;

	while(T--){
		priority_queue <ll> pq;
		ll temp,ans = 0,max;
		cin >> N >> K;
		for(int i=0;i<N;i++){
			cin >> temp;
			pq.push(temp);
		}
		while(K--){

			max = pq.top();
			pq.pop();
			ans += max;
			pq.push(ceil(max/2));
		}
		cout << ans << endl;
	}
}
