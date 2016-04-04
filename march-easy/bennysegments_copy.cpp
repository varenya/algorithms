#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
#define mp make_pair
using namespace std;

bool comp(pair <ll,ll> a,pair <ll,ll> b){
	if ( a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int distance(pair <ll,ll> point){
	return point.second - point.first;
}


int main(void){

	int T;
	cin >> T;
	while(T--){
		vector < pair <ll,ll> > points;
		int N,L;
		cin >> N >> L;
		ll Xl,Xr;
		while(N--){
			cin >> Xl >> Xr;
			points.push_back(mp(Xl,Xr));
		}
		sort(points.begin(),points.end(),comp);
		int result  = distance(points[0]);
		bool sum = false;
		int i = 0;
		for(int j=1;j<points.size();j++){

			cout << result << endl;

			if(result == L){
				sum = true;
				break;
			}
			else if(points[j].first == points[i].second){
				result += distance(points[i]);
				i++;
			}
			else if(points[j].first >= points[i].first && points[j].first <= points[i].second){
				result += max(points[i].second,points[j].second) - min(points[i].first,points[j].first);
			}
			
		}
		if (sum)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}

