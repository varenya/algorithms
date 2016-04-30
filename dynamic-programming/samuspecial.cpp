#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define ll long long
#define mp make_pair
#define pii pair <int,int>
using namespace std;

int gcd(int A, int B) {
    if(B==0)
        return A;
    else
        return gcd(B, A % B);
}

int const MAX = 1e4; 
map <pii,bool>  coprime;

int sum_of_digits(ll num){
	int sum = 0;
	while(num){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
int sum_of_squares(ll num){
	int sum = 0,temp = 0;
	while(num){
		temp = num %10; 
		sum += temp * temp;
		num /= 10;
	}
	return sum;
}

ll special_coprimes(ll L,ll R){

	ll count = 0;
	int sum,sumSquares;
	//cout << " L :" << L << " R " << R << endl;
	for(ll num=L;num<=R;num++){
		sum = sum_of_digits(num);
		sumSquares = sum_of_squares(num);
	//	cout << "sum " << sum << " sumSquares : " << sumSquares << endl;
		/*
		if(gcd(sum,sumSquares) == 1)
			count++;
			*/
		if(coprime[mp(sum,sumSquares)])
			count++;
		
	}
	return count;
}

int main(void){

	int sum,sumSquares;
	for(ll num=1;num<=MAX;num++){
		sum = sum_of_digits(num);
		sumSquares = sum_of_squares(num);
		//cout << "num :" << num << endl;
		//cout << "sum :" << sum << endl;
		//cout << "sumSquare :" << sumSquares << endl;
		bool temp = ( gcd(sum,sumSquares) == 1 );
		coprime[mp(sum,sumSquares)] = temp;
		coprime[mp(sumSquares,sum)] = temp;
	}
	//cout << "After Loop" << endl;
	int T;
	ll L,R;
	cin >> T;
	while(T--){
		cin >> L >> R;
		cout << special_coprimes(L,R) << endl;
		
	}
}
