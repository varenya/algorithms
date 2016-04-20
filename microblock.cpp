#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stdio.h>
#include <string>
#define ll long long
#define MAX 100007
using namespace std;
vector <string> army;
bool cmp(string a,string b){
	return (a+b) > (b+a);
}

int main(void){
	int N;
	string temp;
	cin >> N;
	while(N--){
		cin >> temp;
		army.push_back(temp);
	}
	sort(army.begin(),army.end(),cmp);
//	cout << "sorted!" << endl;
	vector <string>::iterator it;
	for(it=army.begin();it!=army.end();it++){
		cout << *it;
	}
	return 0;
}
