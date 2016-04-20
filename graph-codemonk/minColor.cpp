#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <map>
#define MAX 10
#define ll long long
#define mp make_pair
const int MOD = 1e9 +7;
using namespace std;

vector <ll> adj[10];
int visited[MAX];
stack <ll> nodes;
map < pair <ll,ll> , ll > max_weight;

void dfs_iterative(ll start, map < pair<ll,ll> , ll > weights){
        nodes.push(start);
        visited[start] = true;
	ll total = 0;
        while(!nodes.empty()) {
                int v = nodes.top();
                nodes.pop();
                for(int i=0; i<adj[v].size(); i++) {
                        if(!visited[adj[v][i]]) {

				if ( start < adj[v][i] ){
					max_weight[mp(start,adj[v][i])] = max( max_weight[mp(start,v)] , weights[mp(v,adj[v][i])] );

				}
                                nodes.push(adj[v][i]);
                                visited[adj[v][i]] = true;
                        }
                }
        }
}

void dfs(int s) {
        visited[s] = true;
        for(int i = 0; i < adj[s].size(); ++i)    {
                if(visited[adj[s][i]] == false)
                        dfs(adj[s][i]);
        }
}

void initialize(){
        for(int i=0; i<MAX; i++) {
                visited[i] = false;
        }
}

int main(void){
	int T;
	cin >> T;
	while(T--){
		map < pair<ll,ll> ,ll> weights;
		max_weight.clear();
		ll nodes,edges,x,y,connectedComp = 0,weight;
		cin  >> nodes;
		edges = nodes-1;
		for(int i=0; i<edges; i++) {
			cin >> x >> y >> weight;
			adj[x].push_back(y);
			adj[y].push_back(x);
			weights.insert(mp(mp(x,y),weight));
			weights.insert(mp(mp(y,x),weight));
		}
		//cout << "before initialize" << endl;
		for(int i=1;i<=nodes;i++){
				initialize();
				dfs_iterative(i,weights);
		}
		map < pair <ll,ll> , ll >::iterator it;
		ll ans = 0;
		for(it = max_weight.begin();it!=max_weight.end();it++){
			//cout << it->first.first << " " << it->first.second << " weight " << it->second << endl;
			if ( it->first.first < it->first.second){
				ans = (ans + it->second) % MOD;
			}
		}
		cout << ans << endl;
		
	}
}
