#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1e5;
int primes[MAX];

void find_primes(){

	memset(primes,1,sizeof primes);
	for(int p=2;p*p<=MAX;p++){
		if(primes[p]){
			for(int i=2*p;i<=MAX;i+=p){
				primes[i] = 0;
			}
		}
	}
}

vector <int> digits;

void convertToDigits(int num){
	int temp;
	while(num){
		temp = num % 10;
		digits.push_back(temp);
		num = num/10;
	}
}

void printArray(vector <int> input){
	for(int i=0;i<input.size();i++){
		cout << input[i] << " " ;
	}
	cout << endl;
}

int main(void){

	int T;
	cin >> T;
	find_primes();
	while(T--){
		int L,R;
		cin >> L >> R;
		digits.clear();
		vector <int> freq(R-L+1,0);
		for(int i=L;i<=R;i++){
			if(primes[i]){
				cout << "prime : " << i << endl;
				convertToDigits(i);
			}
		}

		for(int i=0;i<digits.size();i++){
			freq[digits[i]]++; 
		}
		cout << "print Array : " << endl;
		printArray(digits);
		printArray(freq);

		int result=0;

		for(int i=1;i<freq.size();i++){
			if( freq[result] <= freq[i] )
				result = i;
		}

		cout << result << endl;

	}
}
