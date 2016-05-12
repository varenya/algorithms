#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
#define mp make_pair
#define pll pair <ll,ll>
using namespace std;

void printVector ( vector <ll>  input){
	for(int i=0;i<input.size();i++){
		cout << input[i] << " " ;
	}
	cout << endl;
}
int main(void){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector <ll> start;
		vector <ll> finish;
		ll first,second;
		for(int i=0;i<N;i++){
			cin >> first >> second;
			start.push_back(first);
			finish.push_back(second);
		}
		sort(start.begin(),start.end());
		sort(finish.begin(),finish.end());
		printVector(start);
		printVector(finish);
		ll result = 1,temp=1;
		int i=1,j=0;
		while(i < N && j < N){
			if(start[i] < finish[j]){
				temp++;
				i++;
				if(temp > result)
					result = temp;
			}
			else{
				temp--;
				j++;
			}
		}
		cout << result << endl;
	}
}
