#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int maxq = 1e5;
const int lim = 1e5 + 1;
struct cmp
{
	bool operator() (const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second < b.second;
	}
};
int n, q;
vector<int> parent(lim);
vector<int> size(lim);
multiset<pair<int, int>, cmp> S;
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		size[i] = 1;
		S.insert(make_pair(i, 1));
	}
}
int ancestor(int a)
{
	if (parent[a] != a)
		parent[a] = ancestor(parent[a]);
	return parent[a];
}

void printVector(multiset < pair<int,int> , cmp> input){
	multiset < pair<int,int> , cmp> :: iterator it;
	for(it = input.begin();it!=input.end();it++)
		cout << it->first << " " << it->second << " ";
	cout << endl;
}

void merge(int a, int b)
{
	a = ancestor(a);
	b = ancestor(b);
	if (a == b)
		return;
	if (size[b] > size[a])
		swap(a, b);
	//cout << "before " << endl;
	//printVector(S);
	S.erase(S.find(make_pair(a, size[a])));
	S.erase(S.find(make_pair(b, size[b])));
	//cout << "after " << endl;
	//printVector(S);
	size[a] += size[b];
	parent[b] = a;
	S.insert(make_pair(a, size[a]));
}
int main()
{
	scanf("%d%d", &n, &q);
	assert(1 <= n and n <= maxn);
	assert(1 <= q and q <= maxq);
	init(n);
	for (int i = 0; i < q; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		assert(1 <= a and a <= n);
		assert(1 <= b and b <= n);
		merge(a, b);
		int large = (*(S.rbegin())).second;
		int small = (*(S.begin())).second;
		printf("%d\n", large - small);
	}
	return 0;
}
