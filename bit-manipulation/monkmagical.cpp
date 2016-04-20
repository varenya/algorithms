#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int GCD(int A, int B) {
	if(B==0)
		return A;
	else
		return GCD(B, A % B);
}
int main(void){
	int T,N,M,K,temp;
	cin >> T;
	while(T--){
		cin >> N >> M >> K;
		vector <int> X;
		vector <int> C;
		vector <int> Z;
		map <int,bool> used;
		priority_queue <int> sums;
		for(int i=0;i<N;i++){
			cin >> temp;
			X.push_back(temp);
		}
		for(int i=0;i<M;i++){
			cin >> temp;
			C.push_back(temp);
		}
		for(int i=0;i<M;i++){
			cin >> temp;
			Z.push_back(temp);
		}
		
		for(int i=0;i<X.size();i++){
			ll sum = 0;
			for(int j=0;j<C.size();j++){
				bool isThere = ( used.find(j)!=used.end() ) && (used[j]);
				if( GCD(X[i],C[j]) != 1 && !isThere){

					sum += Z[j];
					used[j] = true;
				}
			}
			sums.push(sum);
		}
		ll sum = 0;
		while(K--){

			sum += sums.top();
			sums.pop();
		}
		cout << sum << endl;

	}
}
