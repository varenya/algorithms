#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define MAX 100007
ll A[MAX];
ll B[MAX];
bool myfunc(ll a,ll b){
	return (b > a);
}

int main(void){

	int T,N;
	cin >> T;
	while(T--){
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> A[i];
		for(int j=0;j<N;j++)
			cin >> B[j];

		ll maxValue = 0,it=0,diff;
		vector <ll> v (A,A+N);
		vector <ll>::iterator i;
		for(int j=N-1;j>=0;j--){
			if(j >= it){
				i = lower_bound(v.begin(),v.end(),B[j],myfunc);
				it = i-v.begin();
				cout << "Iterator" << it << endl;
				cout << "j "<< j <<endl;
				cout << B[j] << " " << A[it] << endl;
				diff = j - it;
				maxValue = max(maxValue,diff);
			}
		}

		cout << maxValue << endl;

	}


}
