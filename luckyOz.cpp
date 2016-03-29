#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100000
using namespace std;
//void printArray(int* matrix,int N);


int main(void){

	int T;
	cin >> T;
	while(T--){
		string temp;
		cin >> temp;
		int N = temp.size();
		int i=0,j=N-1;
		int res = 0;
		while(i<j){
			while( (i<j) && (temp[i] !='R') ){
				i++;
			}
			while( (j>i) && (temp[j] !='K') ){
				j--;
			}
			if(i < j){
				res += 2;
			}
			i++;
			j--;
		}

		cout << res << endl;

	}
}

/*

void printArray(int* matrix,int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << matrix[i][j] << " " ;
		}
		cout << endl;
	}
}
*/
