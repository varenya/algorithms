#include <iostream>
#include <queue>
#include <vector>
#define ll long long
using namespace std;

int count_one (int n)
{
	int count = 0;
	while( n )
	{
		n = n&(n-1);
		count++;
	}
	return count;
}


int main(void){

	int T;
	cin >> T;
	while(T--){
		priority_queue <int> q;
		int N,K;
		cin >> N >> K;
		int temp,ones;
		for(int i=0;i<N;i++){
			cin >> temp;
			ones = count_one(temp);
			q.push(ones);
		}
		ll ans = 0;
		while(K--){
			ans += q.top();
			q.pop();
		}

		cout << ans << endl;

	}
}
