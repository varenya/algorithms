#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX 105
using namespace std;

bool vis[MAX];
vector <int> adj[MAX];
int level[MAX];

void initialize(){
        for(int i=0; i<MAX; i++) {
                vis[i] = false;
        }
}
void bfs(int s){

        queue <int> q;
        q.push(s);
        level[s] = 0;
        vis[s] = true;
        while(!q.empty())
        {
                int v = q.front();
                q.pop();
                for(int i=0; i<adj[v].size(); i++) {
                        if(!vis[adj[v][i]]) {
                                q.push(adj[v][i]);
                                vis[adj[v][i]] = true;
                                level[adj[v][i]] = level[v]+1;
                        }
                }
        }

}


int main(void){
	int t;
        int nodes,edges,x,y,connectedComp = 0;
        cin  >> nodes;
        cin >> edges;
        for(int i=0; i<edges; i++) {
                cin >> x >> y;
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        //cout << "before initialize" << endl;
        initialize();
        bfs(1);
        cout << "node" << " " << "level" << endl;
        for(int i=1;i<=nodes;i++){
                cout << i << " " << level[i] << endl;
        }
}
