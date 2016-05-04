#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

bool isNiche(string s){


	stack <char> arch;
	arch.push(s[0]);
	for(int i=1;i<s.size();i++){

		if (!arch.empty() &&  s[i] == arch.top()){
			arch.pop();
		}
		else{
			arch.push(s[i]);
		}
	}
	return arch.empty();
}


int main(void){

	int M;
	cin >> M;
	int count = 0;
	while(M--){
		string input;
		cin >> input;
		if( isNiche(input) ) count++;
	}
	cout << count << endl;
}

