#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string findValue(map <string,int> marks,int value);
bool myfunction(int i,int j){
	return (i > j);
}

int main(void){
	int N;
	cin >> N;
	map <string,int> mark_map;
	vector <int> marks;
	while(N--){
		string name;
		int mark;
		cin >> name >> mark;
		mark_map[name] = mark;
		marks.push_back(mark);
	}
	sort(marks.begin(),marks.end(),myfunction);
	vector <int>::iterator it;
	for(it = marks.begin();it != marks.end();++it){
		cout << findValue(mark_map,*it) << " " << *it << endl;
	}
	return 0;
}

string findValue(map <string,int> marks,int value){
	string result;	
	map<string,int> :: iterator it;
	for(it = marks.begin();it!=marks.end();++it){
		if(it->second == value){
			marks.erase(it);
			result = it->first;
		}
	}
	return result;

}
