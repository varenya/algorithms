#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void){
	int n;
	cin >> n;
	int sum = 0;
	int temp;
	stack <int> sums;
	while(n--){
		cin >> temp;
		if(temp!=0){
			sums.push(temp);
		}
		else{
			sums.pop();
		}
	}
	
	while(!sums.empty()){
		sum += sums.top();
		sums.pop();
	}
	cout << sum << endl;
}
