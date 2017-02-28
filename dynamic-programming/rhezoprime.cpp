#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 1e5;

bool prime[MAX];
int primePre[MAX+7];

vector<int> primes;
// vector<int> primePre;

void SieveOfEratosthenes(ll n) {

  prime[1] = false;
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * 2; i <= n; i += p)
      prime[i] = false;
    }
  }

  for (int p = 2; p <= n; p++) {
    if (prime[p])
    primes.push_back(p);
  }

  int currentMax = 0;
  primePre[1] = 0;
  for (int i = 2; i <= n; i++) {
    // cout << currentMax << "currentMax" << endl;
    if (prime[i]) {
      primePre[i] = i;
      currentMax = i;
    } else {
      primePre[i] = currentMax;
    }
  }
}
void printVector(vector<int> input, int n) {
  vector<int>::iterator it;
  for (int i=0;i<n;i++) {
    cout << input[i] << " " << i << endl;
  }
  cout << endl;
}
void printLong(vector<ll> input, int n) {
  for (int i = 0; i < n; i++) {
    cout << input[i] << " ";
  }
  cout << endl;
}


ll calculateMax(vector<ll> points, int max_prime, int index, int count) {
	if (index > points.size()-1 || count > max_prime-1) {
		return 0;
	} else {
		return max(points[index] +
				calculateMax(points, max_prime, index + 1, count + 1),
				calculateMax(points, max_prime, index + 1, 0));
	}
}

int main(void) {

	memset(prime, true, sizeof(prime));
	SieveOfEratosthenes(MAX);
	// for(int i=2;i<MAX;i++){
	//         cout << primePre[i] << " " << i << endl;
	// }
	int N;
	ll temp;
	cin >> N;
	//cout << "max_prime" << primePre[N];
	vector<ll> points;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		points.push_back(temp);
	}
	vector<ll> sums;
	ll sum = 0;
	for(int i=0;i<N;i++){
		sum += points[i];
		cout << "sum" << sum << endl;
		sums.push_back(sum);
	}
	ll current_sum = 0;
	int max_prime = primePre[N];
	ll max_sum = 0;
	if( max_prime >1 ){
		max_sum = sums[max_prime-1];
		for(int i=1;i<=N-max_prime;i++){
			current_sum = sums[i+max_prime-1] - sums[i-1];
			max_sum = max(max_sum,current_sum);
		}
	}

	//cout << "max_prime" << max_prime << endl;
	cout << max_sum << endl;
}
