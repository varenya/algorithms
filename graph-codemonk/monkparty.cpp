#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <cstring>
#include <climits>
#define MAX 100007
#define ll long long
using namespace std;
bool visited[MAX];
stack <int> nodes;

ll dfs_iterative(set <int> edges[],int start){
        ll result = 0;
        nodes.push(start);
        visited[start] = true;
        while(!nodes.empty()) {
                int v = nodes.top();
                // cout << "v " << v << endl;
                nodes.pop();
                set <int>::iterator it;
                for(it=edges[v].begin();it!=edges[v].end();it++)
                {
                        if(!visited[*it]) {
                               // cout << "group" << *it << endl;
                                nodes.push(*it);
                                result++;
                                visited[*it] = true;
                        }
                }
        }
        return result;
}

int main(void)
{

        memset(visited,false,sizeof visited);
        set <int> edges[MAX];
        int N,M;
        cin >> N >> M;
        while(M--) {
                int x,y;
                cin >> x >> y;
                edges[x].insert(y);
        }
        ll ans = INT_MAX;
        for(int i=1; i<=N; i++) {
                if(!visited[i]) {
                        ll temp = dfs_iterative(edges,i);
                        //cout << temp << endl;
                        ans = min(temp,ans);
                }
        }
        cout << ans << endl;

}
