#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#define ll long long
using namespace std;

map <char,int> freq;
map <char,int> weight;

void initialize(){

        for(char i='a'; i<='z'; i++) {
                freq[i] = 0;
        }
}

int main(void)
{
	int T;
	cin >> T;
	while(T--) {
		initialize();
		string s;
		//set <char> set_char;
		cin >> s;
		float result;
		map <char,int>::iterator it;
		for(char i='a'; i<='z'; i++) {
			int temp;
			cin >> temp;
			weight[i] = temp;
		}
		for(int i=0; i<s.size(); i++) {
			it = freq.find(s[i]);
			if(it!=freq.end())
				freq[s[i]] += 1;
			else
				freq[s[i]] = 1;
		}

		ll prod = 0;
		ll tw = 0;
		for(int i=0; i<s.size(); i++) {
			prod = prod + (freq[s[i]]*weight[s[i]]);

		}
		prod = 0;
		for(it=weight.begin();it!=weight.end();it++)
		{
			//cout << " char :" << it->first << " weight : " << it->second << " frequency :" << freq[it->first] << endl;
			prod = prod + (freq[it->first]*it->second);
		}
		// map <char,int>::iterator it;
		//prod = 0;
		for(it=freq.begin();it!=freq.end();it++){
			if (it->second !=0)
				tw += weight[it->first];
			//prod += it->second * weight[it->first];
		}

		//cout << "tw " << tw << endl;
		//cout << "prod " << prod << endl;

		ll tl = s.size();
		//cout << "tl " << tl << endl;
		result = (10 * prod) / float(tl * tw);
		//cout << "result " << endl;
		printf("%.2f\n",result);
	}
}

