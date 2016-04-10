#include <iostream>
#include <vector>
#include <set>
#define ll long long
using namespace std;
bool iscontinuous(vector<ll> indexes){
	for(int i=1;i<indexes.size();i++){
		if( (indexes[i] - indexes[i-1]) != 1)
			return false;
	}
	return true;
}

void printVector(vector <ll> heights){
		vector <ll>::iterator it;
		for(it=heights.begin();it!=heights.end();it++){
			cout << *it << " ";
		}
		cout << endl;
}
int main(void){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector <ll> heights;
		vector <ll> startindex;
		set <ll> endindex;
		int temp = N;
		while(N--){

			int temp;
			cin >> temp;
			heights.push_back(temp);
		}
		int begin = -1;
		int end = -1;
		int count = 0;
		for(int i=1;i<heights.size();i++){

			if(heights[i] < heights[i-1]){
				begin = i-1;
				startindex.push_back(begin);
			}
		}
		//cout << "heights " << startindex.size() << "N " << temp << endl;

		//cout << "Heights ....."<< endl;

		//printVector(startindex);

		bool  isgreater = (heights[startindex.front()-1] < heights[startindex.back()+1]);

		//cout << "first " << heights[startindex.front()-1] << "second " << heights[startindex.back()+1] << endl;
		
		if( startindex.size() == temp-1){
			cout << startindex.front()+1 << " " << startindex.back()+2 << endl;
		}

		else if(!startindex.empty() && iscontinuous(startindex) && isgreater){
			cout << startindex.front()+1 << " " << startindex.back()+2 << endl;
		}
		else{
			cout << -1 << " " << -1 << endl;
		}

	}
}
