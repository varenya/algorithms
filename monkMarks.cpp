#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

bool myfunction(pair<string,int> p1,pair<string,int> p2){
	if (p1.second == p2.second){
		return p1.first < p2.first;
	}
	return  (p1.second > p2.second);
}
bool stringcomparison(pair<string,int> p1,pair<string,int> p2){
	return (p1.first < p2.first);
}



int main(void)
{
	int N;
	cin >> N;
	vector < pair<string,int> > marks;
	vector < pair<string,int> >::iterator it;
	while(N--)
	{
		string name;
		int mark;
		pair <string,int> mark_pair;
		cin >> name >> mark;
		mark_pair = make_pair(name,mark);
		//cout << "Name " << mark_pair.first << "Marks " << mark_pair.second << endl;
		marks.push_back(mark_pair);
	}
	sort(marks.begin(),marks.end(),myfunction);
	//cout << "Output" << endl;
	for(it=marks.begin();it!=marks.end();it++){
		cout << it->first << " " << it->second << endl;
	}

}
