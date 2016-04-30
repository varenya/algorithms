#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<limits.h>
#include<stack>
#include<stdio.h>
#include<queue>
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007 // 10**9 + 7
#define INF 1e9
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a),0,sizeof(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, b, a) for (int i = b; i > a; i--)
#define all(v) v.begin(), v.end()
#define GETCHAR getchar_unlocked
#define pi(n) printf("%d\n",n)
#define pll(n) printf("%lld\n",n)
#define rk() int t; scanf("%d",&t); while(t--)
using namespace std;
const double pi = acos(-1.0);
//freopen("in","r",stdin);
//freopen("out","w",stdout);
//snprintf(buff, sizeof(buff), "%d", a);
const int er[8] = {-1,-1,0,1,1,1,0,-1};
const int ec[8] = {0,1,1,1,0,-1,-1,-1};
const int fr[4] = {-1,1,0,0};
const int fc[4] = {0,0,1,-1};
typedef unsigned long long ull;
typedef long long ll;
typedef long l;
typedef pair<int,int> pii;
typedef vector<int> vec;
typedef vector<pii> vpii;
ll po(ll a,ll p)

{ll ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p=p>>1;}return ret%mod;}

int f(string start, string finish){ 

	vector<string> q; 
	set<string>seen; 
	q.push_back(start); 
	seen.insert(start); 
	int n=0; 
	int ret=1000000000; 
	while(!q.empty()){ 
		vector<string> q2; 
		while(!q.empty()){ 
			string s = q.back(); 
			q.pop_back(); 
			int cur=n; 
			cout << "n : " << n << endl;
			for(int i=0; i<s.size(); i++){
				cout << "s[i] : " << s[i] << endl;
				cout << "finish[i] : " << finish[i] << endl;
				cout << "diff : "  << finish[i] - s[i] << endl;
				cur+=abs(s[i]-finish[i]); 
			}
			if(cur<ret)ret=cur; 

			cout << "current " << cur << endl;

			for(int i=0; i<s.size();i++){
				for(int j=i+1; j<s.size(); j++){ 
					swap(s[i],s[j]); 
					if(!seen.count(s)){
						cout << "permuation : " << s << endl;
						q2.push_back(s); 
						seen.insert(s);
					} 
					swap(s[i],s[j]); 
				} 
			}
		} 
		q=q2; 
		n++; 
	} 
	return ret; 
} 
int main(){
	//freopen("10.txt","r",stdin);
	//freopen("10out.txt","w",stdout);
	rk(){
		string a,b;
		cin>>a>>b;
		int ans=f(a,b);
		cout<<ans<<endl;
	}
	return 0;
}

