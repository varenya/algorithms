#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

bool subset[2007][2007];

bool isSubSetSum(vector <ll> input,ll sum){

	int n =input.size();
	cout << "vector size " << n << endl;

	for(int i=0;i<=n;i++)
		subset[0][i] = true;

	for(int i=1;i<=sum;i++)
		subset[i][0] = false;

	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			subset[i][j] = subset[i][j-1];
			if(i>=input[j-1])
				subset[i][j] = subset[i][j] || subset[i-input[j-1]][j-1];
		}
	}

/*
	for(int i=0;i<sum;i++){
		for(int j=0;j<n;j++){
			cout << subset[i][j] << " ";
		}
		cout << endl;
	}
	*/
	
	return subset[sum][n];

}



void printArray(vector <ll> input){
	sort(input.begin(),input.end());
	vector <ll>::iterator it;
	for(it = input.begin();it!=input.end();it++)
		cout << *it << " ";
	cout << endl;
}

int main(void){
	ll ans,N,L;
	int T;
	cin >> T;
	while(T--){
		vector <ll> distances;
		cin >> N >> L;
		ll Xl,Xr,diff;
		cout << "Testcase " << endl;
		cout << "N " << N << endl;
		while(N--){
			cin >> Xl >> Xr;
			cout << "Xl " << Xl << "Xr : " << Xr << endl;
			diff = Xr-Xl;
			distances.push_back(diff);
		}
		cout << "L : " << L << endl;
		//cout << "N : " << N << endl;
		printArray(distances);
		if(isSubSetSum(distances,L))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		
	}
}
