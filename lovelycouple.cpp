#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstring>
#include <map>
#define ll long long
using namespace std;

const int MAX = 1e4;

bool prime[MAX];
ll factorCount[MAX];

void SieveOfEratosthenes(ll n)
{
	//Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.

	prime[1] = false;

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	
	for (int p=2; p<=n; p++){
		if (prime[p])
			cout << p << " ";
	}
	   
}


ll primeFactors(ll n)
{
	// Print the number of 2s that divide n
	ll count = 0;
	while (n%2 == 0)
	{
		//printf("%d ", 2);
		n = n/2;
		count++;

	}

	// n must be odd at this point. So we can skip one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i+2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			//printf("%d ", i);
			n = n/i;
			count++;
		}
	}

	// This condition is to handle the case whien n is a prime number
	// greater than 2
	if (n > 2)
		count++;

	return count;
}

ll gcd(ll a, ll b) {
	    return b == 0 ? a : gcd(b, a % b);
}

int main(void){

	memset(prime, true, sizeof(prime));
	SieveOfEratosthenes(MAX);
	int T;
	cin >> T;
	while(T--){
		ll A,B;
		cin >> A >> B;
		ll lcm = A*B/gcd(A,B);
		//cout << "lcm : " << lcm << endl;
		ll count = factorCount[lcm];
		//cout << "count : " << count << endl;
		if( prime[count])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
