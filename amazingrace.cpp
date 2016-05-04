#include <iostream>
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define mp make_pair;
using namespace std;

bool cmp( pair <int,int> a, pair<int,int> b){
	if ( a.first * a.second == b.first * b.second){
		return a.second < b.second;
	}
	return a.first*a.second < b.first*b.second;
}

ll mod = 1e9+7;

void printVector ( vector < pair<int,int> > input ){
	for(int i=0;i<input.size();i++){
		cout << "X : " << input[i].first << " P : " << input[i].second << " PX : " << input[i].first * input[i].second << endl;

	}
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		int n,t;
		vector < pair<int,int> > xp;
		cin >> n;
		vector <ll> heights(n+1);
		t = n;
		for(int i=1;i<=n;i++)
			cin >> heights[i];

		vector <int> left(n+1);
		vector <int> right(n+1);

		stack <int> first;
		stack <int> last;


		left[1] = 0;
		first.push(1);
		for(int i=1;i<heights.size();i++){
			while(!first.empty() && heights[i] > heights[first.top()])
				first.pop();
			if( !first.empty() ) left[i] = i-first.top();
			else left[i] = i-1;

			first.push(i);
		}
		//cout << "before right " << endl;
		right[n]=0;
		last.push(n);
		for(int i=n-1;i>=0;i--){
			while(!last.empty() && heights[i] > heights[last.top()])
				last.pop();
			if( !last.empty() )right[i] = last.top()-i;
			else right[i] = n-i;

			last.push(i);
		}
		
		int max_index = -1;
		int maxp = -1;
		for(int i=1;i<=n;i++){
			//cout << "height[i] : " << heights[i] << " " ;
			//cout << "i : " << i << " " ;
			//cout << "left : " << left[i];
			//cout << " right : " << right[i] << endl;
			//cout << "PX : " << (i+1) * (left[i]+right[i]) << endl;
			ll sum = left[i] + right[i];
			sum = ( (sum % mod) * i) % mod;
			if ( sum > maxp){
				maxp = sum;
				max_index = i;
			}
		}

		//printVector(xp);


		//cout << "input : " << endl;
		//for(int i=0;i<heights.size();i++){
		//	cout << heights[i] << " " ;
		//}
		//cout << "ans:" << endl;

		cout << max_index << endl;

	}
}
