#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void){

	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int left=0,right=0;
		for(int i=0;i<s.size();i++){
			if( s[i] == '(') right++;
			else{
				if(right > 0)
					right--;
				else
					left++;
			}
		}
		//cout << "left : " << left << endl;
		//cout << "right : " << right << endl;

		for(int i=0;i<left;i++) s = '('+ s;
		for(int i=0;i<right;i++) s = s + ')';
		cout << s << endl;
	}
}
