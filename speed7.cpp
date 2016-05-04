#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
int main(void){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector <ll> speeds(N);
		for(int i=0;i<N;i++){
			cin >> speeds[i];
		}
		ll count=1;
		for(int i=1;i<N;i++){
			if(speeds[i] <= speeds[i-1])
				count ++;
			else
				speeds[i] = speeds[i-1];
		}
		cout << count << endl;
	}
}
