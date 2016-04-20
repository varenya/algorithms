#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#define MAX 105
using namespace std;

bool vis[MAX];
vector <int> adj[MAX];
int level[MAX];

void initialize(){
        for(int i=0; i<MAX; i++) {
		adj[i].clear();
                vis[i] = false;
        }
}
int bfs(int s,priority_queue < int,vector<int>,greater<int> > cost1,priority_queue < int,vector<int>,greater<int> > cost2){

	queue <int> q;
	q.push(s);
	level[s] = 0;
	int ans = 0;
	int temp;
	vis[s] = true;
	bool even = false;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		for(int i=0; i<adj[v].size(); i++) {

			if(!vis[adj[v][i]]) {
				level[adj[v][i]] = level[v]+1;
				q.push(adj[v][i]);
				vis[adj[v][i]] = true;

				if(!even){
					temp = cost1.top();
					cost1.pop();
					cost2.push(temp);
				}
				else{
					temp = cost2.top();
					cost2.pop();
					cost1.push(temp);
				}
				cout << "temp " << temp << endl;
				ans += temp;
			}
		}
		if ( (level[v]+1) % 2 == 0)
			even = !even;
	}
	return ans;

}


int main(void){
	int t;
	cin >> t;
	while(t--){
		int nodes,edges,x,y,connectedComp = 0;
		cin  >> nodes;
		priority_queue < int,vector<int>,greater<int> > cost1;
		priority_queue < int,vector<int>,greater<int> > cost2;
		for(int i=1;i<nodes;i++){
			int temp;
			cin >> temp;
			cost1.push(temp);
		}
		edges = nodes-1;
		initialize();
		for(int i=0; i<edges; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		//cout << "before initialize" << endl;
		int result=bfs(1,cost1,cost2);
		/*
		cout << "node" << " " << "level" << endl;
		for(int i=1;i<=nodes;i++){
			cout << i << " " << level[i] << endl;
		}
		*/
		cout << result << endl;
	}
}
