#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#define MAX 10005
#define ll long long
using namespace std;
typedef pair <ll,int>  PII;
bool marked[MAX];
vector <PII> adj[MAX];

ll prim(int x){

        priority_queue < PII, vector<PII>, greater<PII> > Q;
        int y;
        ll minimumCost = 0;
        PII p;
        Q.push(make_pair(0,x));
        while(!Q.empty()) {

                p = Q.top();
                Q.pop();
                x = p.second;
                if ( marked[x] == true)
                        continue;
                minimumCost += p.first;
                marked[x] = true;
                for(int i=0; i<adj[x].size(); i++) {
                        y= adj[x][i].second;
                        if(!marked[y])
                                Q.push(adj[x][i]);

                }
        }

        return minimumCost;
}

int main(void){

        int nodes,edges,x,y;
        ll weight,minimumCost;
        cin >> nodes >> edges;
        for(int i=0; i<edges; i++) {
                cin >> x >> y >> weight;
                adj[x].push_back(make_pair(weight,y));
                adj[y].push_back(make_pair(weight,x));
        }
        minimumCost = prim(1);
        cout << minimumCost << endl;
        return 0;
}
