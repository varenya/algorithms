#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 1e5 + 5;

ll H[MAX];
int N;
ll K;

ll result;

ll maxHeight(int i){
	if( i > N){
		return 0;
	}
	else if(H[i] <= K ){
		result =  max( H[i] + maxHeight(i+1) , maxHeight(i+1) );
		return result;
	}
	else{
		result = 0;
		return maxHeight(i+1);
	}
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		cin >> N >> K;
		for(int i=0;i<N;i++){
			cin >> H[i];
		}

		cout << " N : " << N << " K : " << K << endl;

		for(int i=0;i<N;i++){
			cout << H[i] << " " ;
		}
		cout << endl;

		ll ans = -100;
		ll temp = 0;
		cout << "Start " << endl;
		for(int i=0;i<N;i++){
			if( H[i] <= K) {
				cout << H[i] << " ";
				temp += H[i];
			}
			else{
				ans = max(ans,temp);
				cout << endl << "Ans : " << ans << endl;
				temp = 0;
			}
		}
		
		ans = max(ans,temp);

		cout << "result " << endl;

		if ( ans > 0 )
			cout << ans << endl;
		else
			cout << temp << endl;
	}
}
