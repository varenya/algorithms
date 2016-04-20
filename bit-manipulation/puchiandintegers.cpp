#include <iostream>
#include <bits/stdc++.h>
int main(void){
	int T;
	cin >> T;
	while(T--){
		int N,temp;
		cin >> N;
		vector <int> A;
		vector <int> P;
		for(int i=0;i<N;i++){
			cin >> temp;
			A.push_back(temp);
		}
		for(int i=0;i<N;i++){
			cin >> temp;
			P.push_back(temp);
		}

		for(int i=0;i < (1 << N);i++){
			for(int j=0;j<N;j++){
				if(i & (1 << j)){



				}
			}
		}
	}
}
