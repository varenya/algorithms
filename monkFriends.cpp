#include <iostream>
#include <set>
#define ll long long
using namespace std;
#define MAX 100007
ll arr[MAX];

int main(void){
	int T;
	cin >> T;
	int N,M;
	cin >> N >>  M;
	//cout << "N : " << N << "M :" << M << endl;
	while(T--){

		cout << T << "TestCase" << endl;
		set <ll> firstN;
		set <ll>::iterator it;
		ll temp;
		for(int i=0;i<N;i++){
			cin >> temp;
			firstN.insert(temp);
		}

		for(int i=0;i<M;i++)
			cin >> arr[i];

		for(int i=0;i<M;i++){

			it = firstN.find(arr[i]);

			if(it == firstN.end()){

				cout << "NO" << endl;
				firstN.insert(arr[i]);

			}
			else{
				cout << "YES" << endl;
			}
		}
	}


}
