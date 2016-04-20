#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
#define pii pair <int,int>
#define mp make_pair

using namespace std;


int main(void){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector <int> L;
		vector <int> R;
		int temp;
		for(int i=0;i<N;i++){
			cin >> temp;
			L.push_back(temp);
		}
		for(int i=0;i<N;i++){
			cin >> temp;
			R.push_back(temp);
		}
		int max_index = 0;
		int max_value = L[0] * R[0];
		for(int i=1;i<N;i++){
			if(L[i] * R[i] > max_value){
				max_index = i;
				max_value = L[i] * R[i];
			}
			else if(L[i] * R[i] == max_value && R[max_index] < R[i] ){
				max_index = i;
			}
		}

		cout << max_index+1 << endl;

	}
}
