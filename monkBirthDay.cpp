#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(void){
	int T,N;
	cin >> T;
	while(T--){
		cin >> N;
		set <string> monk;
		set <string>::iterator it;
		string temp;
		for(int i=0;i<N;i++){
			cin >> temp;
			monk.insert(temp);
		}
		for(it = monk.begin();it!=monk.end();++it){
			cout << *it << endl;
		}
	}
	return 0;
}
