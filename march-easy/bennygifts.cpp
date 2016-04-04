#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <utility>
#define MAX 10007
#define MOD 1000007
using namespace std;

int main(void){

	string s1;
	set < pair<int,int> > visited;
	int X=0,Y=0,negX,negY;
	long long ans=0;
	cin >> s1;
	visited.insert(make_pair(1,1));
	for(int i=0;i<s1.size();i++){
		if(s1[i] == 'L')
			Y=Y-1;
		if(s1[i] == 'R')
			Y=Y+1;
		if(s1[i] == 'U')
			X=X-1;
		if(s1[i] == 'D')
			X=X+1;
		if (visited.find(make_pair(X,Y)) != visited.end()){
			ans++;
		}
		visited.insert(make_pair(X,Y));
	}
	cout << ans << endl;
}
