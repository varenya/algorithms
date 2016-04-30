#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(void){

	ll N;
	cin >> N;
	ll sum = 0,temp,j=1;
	ll last_j = 1;
	vector <ll> arr;
	for(ll i=1;i<=N;i++){
		cin >> temp;
		arr.push_back(temp);
		//cout << "input : " << temp << endl;
		//cout << "j " << j << endl;
		//cout << "sum " << sum << endl;
	}
	sort(arr.begin(),arr.end());
	for(ll i=0;i<arr.size();i++){
		temp = arr[i];
		while(j*j < temp){
			sum += j*j;
			j++;

		}
		sum += (j*j - temp);
		//cout << "added :" << (j*j - temp) << endl;
		j++;
	}
	cout << sum << endl;
}
