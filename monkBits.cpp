
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long
#define mp make_pair
using namespace std;

struct number {
	int index;
	ll count;
	ll num;
};

ll countOnes(ll num){
	ll count = 0;
	while(num){
		num = num & (num-1);
		count ++;
	}
	return count;
}

bool comp(number a,number b){
	if(a.count == b.count)
		return a.index < b.index;
	else
		return a.count < b.count;
}

int main(void){

	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int index = 0;
		vector <number> input;
		while(N--){
			ll temp,count;
			cin >> temp;
			count = countOnes(temp);
			number count_struct;
			count_struct.num = temp;
			count_struct.count = count;
			count_struct.index = index;
			input.push_back(count_struct);
			index++;
		}
		sort(input.begin(),input.end(),comp);
		vector <number>::iterator it;
		for(it=input.begin();it!=input.end();it++){
			cout << it->num << " " ;
			//cout  << " " << it->second << " ";
		}
		cout << endl;
	}
}
