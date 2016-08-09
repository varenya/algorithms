#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
#define ll long long
#define mp make_pair
#define pll pair<ll,ll>

vector < pair<ll,ll> > RH;

int N;
bool comp(pair <ll,ll> a,pair <ll,ll> b){
		return a.first * a.second > b.first * b.second;
}

void printVector(vector <pll> input){
	vector <pll>::iterator it;
	for(it=input.begin();it!=input.end();it++){
		cout << "Radius " <<  it->first << " Height " << it->second << " ";
	}
	cout << endl;
}


ll maxn[229];

int main(void){
	int T;
	cin >> T;
	while(T--){

		RH.clear();
		cin >> N;
		ll temp1,temp2;

		for(int i=0;i<N;i++){
			cin >> temp1 >> temp2;
			RH.push_back( mp(temp1,temp2) );
		}

		sort(RH.begin(),RH.end(),comp);


		ll result = RH[0].first;

		for(int i=0;i<N;i++)
			maxn[i] = RH[i].first;

		for(int i=1;i<N;i++){
			for(int j=0;j<i;j++){
				if( RH[j].first > RH[i].first &&  RH[j].second > RH[i].second ){
					maxn[i] = max( maxn[i], maxn[j]+RH[i].first );
				}
			}
		}

		for(int i=1;i<N;i++){
			result = max(result,maxn[i]);
		}

		//printVector(RH);
		cout << result << endl;
	}
}
