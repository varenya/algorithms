#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int lim = 1e3 + 1;
const int maxn = 1e3;
const int maxk = 1e3;
const int LL mod = 1e9 + 7;
vector<LL> E(lim);
vector<int> parent(lim);
int ancestor(int a)
{
								if (a != parent[a])
																parent[a] = ancestor(parent[a]);
								return parent[a];
}
void merge(int a, int b)
{
								a = ancestor(a);
								b = ancestor(b);
								if (a != b)
																parent[a] = b;
}
int main()
{
								int n;
								scanf("%d", &n);
								assert(1 <= n and n <= maxn);
								for (int i = 1; i <= n; i++)
																scanf("%lld", &E[i]);
								for (int i = 1; i <= n; i++)
																parent[i] = i;
								int k;
								scanf("%d", &k);
								assert(1 <= k and k <= maxk);
								for (int i = 1; i <= k; i++)
								{
																int city1, city2;
																scanf("%d%d", &city1, &city2);
																merge(city1, city2);
								}
								for (int i = 1; i <= n; i++)
																parent[i] = ancestor(i);
								map<int, multiset<int> > mp;
								for (int i = 1; i <= n; i++)
																mp[parent[i]].insert(E[i]);
								LL ans = 1;
								for (auto foo: mp)
								{
																LL cnt = 1;
																int low = *(foo.second.begin());
																foo.second.erase(foo.second.begin());
																for (auto bar: foo.second)
																{
																								if (bar != low)
																																break;
																								cnt++;
																}
																ans = (ans * cnt) % mod;
								}
								printf("%lld\n", ans);
								return 0;
}
