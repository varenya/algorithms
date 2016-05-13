#include <bits/stdc++.h>
/* 
 *  Always code as if the guy who ends up maintaining your code will be a violent psychopath who knows where you live.
 *   - Rick Osborne
 *     */
using namespace std;
typedef pair <int,int> PII;
typedef vector <int> VI; 
typedef vector < PII > VPII;

void printVector(VPII segm){

		cout << " print vector : " << endl;

		for(int i=0;i<segm.size();i++){

			cout << segm[i].first << " " << segm[i].second << " " << endl;

		}
}


int main()
{
	int tc;
	scanf("%d",&tc);
	while (tc--)
	{
		int m, n;
		scanf("%d %d",&m, &n);
		VPII segm;
		for(int i=0;i<n;i++)
		{
			int st, en;
			scanf("%d %d",&st, &en);
			if(st<=en)
			{
				segm.push_back(make_pair(st,en));
				segm.push_back(make_pair(st+m,en+m));
			}
			else
				segm.push_back(make_pair(st,en+m));
		}

		printVector(segm);


		if(n>m)
		{
			puts("NO");
			continue;
		}
		sort(segm.begin(),segm.end());

		cout << "After Sorting " << endl;

		printVector(segm);

		int T=0;
		int i=0;
		set < PII > que;
		bool ok = true;
		while(true)
		{
			if(que.empty())
			{
				if(i==segm.size())
					break;
				else
					T = segm[i].first;
			}

			while(i<segm.size() && segm[i].first==T)
			{
				que.insert(make_pair(segm[i].second,i));
				i++;
			}

			int ind = que.begin()->second;
			que.erase(que.begin());

			if(!(T>=segm[ind].first && T<=segm[ind].second))
			{
				ok = false;
				break;
			}
			T++;
		}
		puts(ok?"YES":"NO");
	}
}
