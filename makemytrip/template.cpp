#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>
#include <set>
#include <vector>
#include <utility>
#define ll long long
#define mp make_pair
#define pll pair <ll,ll> 

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;

char X,Y;

set <pll> seen;
void printVector(vector <ll> heights){

	vector <ll>::iterator it;
	for(it=heights.begin();it!=heights.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

ll substrings(string a,ll N){
	cout << "inside method! " << a << N << endl;
	ll i=0,j=N-1;
	ll count = 0;
	while( i <= j){
		cout << i << " " <<  j << " " << count << endl;
		if( (a[i] == X && a[j] == Y) || ( a[i] == Y && a[j] == X) ){
			i++;
			j--;
			count++;
		}
		else if( a[i] == Y || a[i] == X){
			j--;
		}
		else if( a[j] == X || a[j] == Y){
			i++;
		}
		else{
			i++;
			j--;
		}
	}

	return count;

}

ll count_substrings(string a,int i,int j){

	cout << "i : " << i << "j : " << j << endl;
	cout << "first :" << a[i] << " second : " << a[j] << endl;

	if ( i >= j){
		return 0;
	}
	if( (a[i] == X && a[j] == Y) || ( a[i] == Y && a[j] == X) ){
		if(!seen.count(mp(i,j))){
			seen.insert(mp(i,j));
			return 1 + count_substrings(a,i+1,j) + count_substrings(a,i,j-1);
		}
	}
	else if( a[i] == Y || a[i] == X){
		return count_substrings(a,i,j-1);
	}
	else if( a[j] == X || a[j] == Y){
		return count_substrings(a,i+1,j);
	}
	else{
		return count_substrings(a,i+1,j-1);
	}
}
int count_substring(string s)
{
	int inc = 0;
	int substring_count = 0;

	for(int i = 0;i < s.length();i++)
	{
		cout << "s[i] : " << s[i] << endl;
		if(s[i] == X) inc++;
		if(s[i] == Y) substring_count += inc;
	}
	return substring_count;
}

ll countSubstring(string s,int N){
	ll count = 0;
	for(int i=0;i<N;i++){
		if(s[i] == X || s[i] == Y){

			for(int j=i+1;j<N;j++){
				if( s[i] == X && s[j] == Y)
					count++;
				if( s[i] == Y && s[j] == X)
					count++;
			}
		}
	}
	return count;
}

int main(void){
	ll N;
	cin >> N;
	string s1;
	cin >> s1;
	int Q;
	cin >> Q;
	while(Q--){
		cin >> X >> Y;
		cout << count_substring(s1) << endl;

	}
	return 0;
}
