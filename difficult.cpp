#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <string>
#define ll long long
using namespace std;


struct cmp
{
	bool operator() (const pair<char, ll>& a, const pair<char, ll>& b)
	{
		if( a.second == b.second){
			return a.first > b.first;
		}
		return a.second < b.second;
	}
};


map <char,ll> frequency;
set < pair<char,ll> , cmp > result;
void initialize(){
	for(char i='a';i<='z';i++)
		frequency[i] = 0;
}

void getFrequency(string input){
	for(int i=0;i<input.size();i++){
		frequency[input[i]] += 1 ;
	}
	map < char,ll>::iterator it;
	for(it = frequency.begin();it!=frequency.end();it++){
		result.insert(make_pair(it->first,it->second));
	}
}

int main(void){

	int T;
	cin >> T;
	while(T--){
		string input;
		cin >> input;
		initialize();
		result.clear();
		getFrequency(input);
		set < pair<char,ll> , cmp >::iterator it;
		for(it=result.begin();it!=result.end();++it){

				cout << it->first << " ";
		}
		cout << endl;
	}


}

