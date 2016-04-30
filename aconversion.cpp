#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;


int min_diff(string start,string finish){

	vector <string> q;
	set <string> seen;
	q.pb(start);
	int ret = 1e9;
	int n = 0;
	int curr;
	while(!q.empty()){
		vector <string> q2;
		while(!q.empty()){

			string s = q.back();
			q.pop_back();
			curr = n;
			for(int i=0;i<s.size();i++){
				curr += abs(s[i]-finish[i]);
			}
			if ( curr < ret) ret = curr;
			for(int i=0;i<s.size();i++){
				for(int j=i+1;j<s.size();j++){
					swap(s[i],s[j]);
					if( !seen.count(s)){
						q2.pb(s);
						seen.insert(s);
					}
					swap(s[i],s[j]);
				}
			}

		}
		q = q2;
		n++;
	}
	return ret;
}

int main(void){

	int T;
	cin >> T;
	string a,b;
	while(T--){
		cin >> a >> b;
		cout << min_diff(a,b) << endl;
	}
}
