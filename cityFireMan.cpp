#include <iostream>
#include <set>
#include <map>
#include <climits>
#define ll long long
#define MAX 1001
#define MOD 1000000007
using namespace std;

int E[MAX];
int parent[MAX];


int ancestor(int a){

        if ( parent[a] != a) {
                a = ancestor(parent[a]);
        }
        return parent[a];
}

void merge(int a,int b){
        a = ancestor(a);
        b = ancestor(b);
        if(a != b)
                parent[a] = b;
}

int main(void){
        int N;
        cin >> N;
        for(int i=1; i<=N; i++) {
                cin >> E[i];
        }
        for(int i=1; i<=N; i++)
                parent[i] = i;
        int K;
        cin >> K;
        for(int i=0; i<K; i++) {
                int city1,city2;
                cin >> city1 >> city2;
                merge(city1,city2);
        }

        for(int i=1; i<=N; i++)
                parent[i] = ancestor(i);
        map <int,multiset<int> > mp;
        for(int i=1; i<=N; i++) {
                mp[parent[i]].insert(E[i]);
        }
        ll ans = 1;
        for(auto foo:mp) {

                ll cnt = 1;
                int low = *(foo.second.begin());
                foo.second.erase(foo.second.begin());
                for(auto bar : foo.second) {
                        if(bar!=low)
                                break;
                        cnt++;
                }
                ans = (ans * cnt) % MOD;
        }

        cout << ans%MOD << endl;
        return 0;
}
