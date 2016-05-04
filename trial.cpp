#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100;
bool neighbors(int i,int n);
void printVector( int n);

vector <int> input,prev;

void flip(int n){

	//cout << "inside flip" << endl;

	vector <bool> temp;
	for(int i=0;i<n;i++){
		//cout << "i : " << i << endl;
		temp.push_back(neighbors(i,n));
	}
	for(int i=0;i<n;i++){
		if(temp[i] && input[i] == 0)
			input[i] = 1;
		if( !temp[i] && input[i] == 1)
			input[i] = 0;
	}

}

void flip2(int n,int m){

	vector <int> tmp;


	int flag = 0;
	for(int cnt=1;cnt<=m;cnt++){


		if( input[1] == 1 )
			tmp.push_back(1);
		else
			tmp.push_back(0);

		for(int i=1;i<n-1;i++){
			if( input[i-1] == 1 && input[i+1] == 1) 
				tmp.push_back(1);
			else
				tmp.push_back(0);

		}
		if ( input[input.size()-2] == 1)
			tmp.push_back(1);
		else
			tmp.push_back(0);
		if(input == tmp){
			flag = 1;
			printVector(n);
			break;
		}
		if(tmp == prev){
			flag =0;
			int count = m-cnt;
			if( count % 2 == 0){
				input = tmp;
			}
			break;
		}
		prev = input;
		input = tmp;
		tmp.clear();
	}
	if( flag == 0){
		printVector(n);
	}

}

bool neighbors(int i,int n){

	if(i == 0){
		return input[1] == 1;
	}
	else if( i == n-1) {
		return input[n-2] == 1;
	}
	else{
		return (input[i-1] == 1 && input[i+1] == 1);
	}
}

void printVector( int n){
	for(int i=0;i<n;i++){
		cout << input[i] << " " ;
	}
	cout << endl;
}


int main(void){
	int t;
	cin >> t;
	int n,m;
	while(t--){
		cin >> n >> m;
		int temp;
		for(int i=0;i<n;i++){
			cin >> temp;
			input.push_back(temp);
		}
			
		flip2(n,m);
		input.clear();
		prev.clear();
	}
}
