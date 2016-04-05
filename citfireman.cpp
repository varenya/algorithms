#include<iostream>
#include <list>
using namespace std;
long long V;
long long *e;
long long cnt,ans;
long long m;
list<long long> *adj;
bool *visited;

void init(long long n)
{
	adj = new list<long long>[n];
	visited = new bool[n];
	e=new long long[n];
	for(long long i = 0; i < n; i++)
		visited[i] = false;
}

void addEdge(long long v, long long w)
{
	adj[v].push_back(w);
}

void DFSUtil(long long v, bool visited[])
{
	visited[v] = true;
	if(m>e[v])
		m=e[v];
	else
	{
		if(m==e[v])
			cnt++;
	}
	list<long long>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			DFSUtil(*i, visited);
}


int main()
{
	long long n;
	cin>>n;
	init(n);
	ans=1;
	for(long long i=0;i<n;i++)
		cin>>e[i];
	long long k;
	cin>>k;
	long long a,b;
	while(k--)
	{
		cin>>a;
		cin>>b;
		addEdge(a-1,b-1);
		addEdge(b-1,a-1);
	}
	for(long long i=0;i<n;i++)
	{
		m=10000;
		cnt=1;
		DFSUtil(i,visited);
		cnt=cnt%1000000007;
		ans=ans*cnt;
	}
	cout<<ans%1000000007<<endl;
	return 0;
}
