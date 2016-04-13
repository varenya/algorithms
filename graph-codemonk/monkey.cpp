#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 100007
#define ll long long
using namespace std;
bool visited[MAX];
ll A[MAX];

ll dfs_iterative(vector <int> edges[],int start){
        ll result = A[start];
        stack <int> nodes;
        nodes.push(start);
        visited[start] = true;
        while(!nodes.empty()) {
                int v = nodes.top();
                // cout << "v " << v << endl;
                nodes.pop();
                for(int i=0; i<edges[v].size(); i++) {
                        if(!visited[edges[v][i]]) {
                               // cout << "group" << edges[v][i] << endl;
                                nodes.push(edges[v][i]);
                                result += A[edges[v][i]];
                                visited[edges[v][i]] = true;
                        }
                }
        }
        return result;
}

int main(void)
{

        int T;
        cin >> T;
        while(T--) {
                memset(visited,false,sizeof visited);
                vector <int> edges[MAX];
                int N,M;
                cin >> N >> M;
                while(M--) {
                        int x,y;
                        cin >> x >> y;
                        edges[x].push_back(y);
                        edges[y].push_back(x);
                }
                for(int i=1; i<=N; i++)
                        cin >> A[i];
                ll ans = 0;
                for(int i=1; i<=N; i++) {
                        if(!visited[i]) {
                                ans = max(dfs_iterative(edges,i),ans);
                        }
                }
                cout << ans << endl;
        }

}
