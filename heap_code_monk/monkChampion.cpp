#include <iostream>
#include <queue>
#define ll long long
using namespace std;

ll maxProfit(priority_queue <ll> q,ll N){
	ll sum = 0;
	while(N--){

		if(!q.empty()){

			ll max_item = q.top();
			q.pop();
			sum += max_item;
			max_item--;
			q.push(max_item);
		}
	}
	return sum;
}

int main(void){

	ll M,N;
	cin >> M >> N;
	priority_queue <ll>  q;
	while(M--){
		ll temp;
		cin >> temp;
		q.push(temp);
	}
	cout << maxProfit(q,N) << endl;
}
