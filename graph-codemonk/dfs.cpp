#include <iostream>
#include <vector>
#include <stack>
#define MAX 10
using namespace std;

vector <int> adj[10];
int visited[MAX];
stack <int> nodes;

void dfs_iterative(int start){
        nodes.push(start);
        visited[start] = true;
        while(!nodes.empty()) {
                int v = nodes.top();
                // cout << "v " << v << endl;
                nodes.pop();
                for(int i=0; i<adj[v].size(); i++) {
                        if(!visited[adj[v][i]]) {
                                // cout << "univisited" << adj[v][i] << endl;
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
        for(int i=1; i<=nodes; i++) {
                if(!visited[i]) {
                        dfs_iterative(i);
                        connectedComp++;
                }
        }
        cout << "connected components " << connectedComp << endl;
}
