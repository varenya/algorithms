#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool flag = false;

int pages(int num){

	//cout << "Num : " << num << endl;
	if( num < 0){
		return 0;
	}
	else if(num == 0){
		flag = true;
		return 0;
	}
	else{
		return min( 1+ pages(num-12) , 1+pages(num-10) );
	}
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		flag = false;
		int n;
		cin >> n;
		int ret = pages(n);
		
		if(flag)
			cout << ret << endl;
		else
			cout << -1 << endl;

	}
}
