#include <bits/stdc++.h>
using namespace std;
vector < vector < int > > graph;
int ans = 999999, cnt, n, d, a, b;
bool visited[1000];
void traverse(int a) {
								visited[a] = true;
								for(int i=0; i<graph[a].size(); i++) {
																if(visited[graph[a][i]]==false) {
																								cnt++;
																								traverse(graph[a][i]);
																}
								}
}
int main() {
								graph.clear();
								scanf("%d%d",&n,&d);
								graph.resize(n);
								for(int i=0; i<d; i++) {
																scanf("%d%d",&a,&b);
																graph[a-1].push_back(b-1);
								}
								for(int i=0; i<n; i++) {
																for(int j=0; j<1001; j++)
																								visited[j]=false;
																cnt =1;
																	traverse(i);
																ans = min(cnt,ans);
								}
								printf("%d\n",ans);
								return 0;
}
