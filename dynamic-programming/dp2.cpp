#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int type,L,R;
vector <ll> A,B;

ll sumArrays(bool start,int i){
	if( i > R){
		return 0;
	}
	else if(start){
		return A[i-1] + sumArrays(!start,i+1);
	}
	else {
		return B[i-1] + sumArrays(!start,i+1);
	}
}

int main(void){

	int N,Q;
	cin >> N >> Q;
	ll temp;
	A.clear();
	B.clear();
	for(int i=0;i<N;i++){
		cin >> temp;
		A.push_back(temp);
	}
	for(int i=0;i<N;i++){
		cin >> temp;
		B.push_back(temp);
	}

	while(Q--){

		cin >> type >> L >> R;
		if(type == 1){

			cout << sumArrays(true,L) << endl;

		}
		else{
			cout << sumArrays(false,L) << endl;
		}

	}

}
