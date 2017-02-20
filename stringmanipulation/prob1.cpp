#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool mycomp(char a,char b){
	return a > b ;
}

int main(){
	int N,M,T;
	string s;
	cin >> T;
	while(T--){
			cin >> s >> N >> M;
			sort(s.begin()+N,s.begin()+M+1, mycomp);
			cout << s << endl;
	}

}
