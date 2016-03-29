#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
#define MAX 1000007

ll arr[MAX];

int main(void){

	ll N,Q;
	cin >> N >> Q;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	vector <ll> v (arr,arr+N);
	sort (v.begin(),v.end());
	while(Q--){
		ll X;
		cin >> X;
		if( binary_search(v.begin(),v.end(),X)  )
				cout << "YES" << endl;
		else
			        cout << "NO" << endl;
	}
}
