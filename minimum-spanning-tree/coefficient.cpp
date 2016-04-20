#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define MAX 100005
#define ll long long
using namespace std;
int id[MAX],nodes,edges;

const int MOD = 1e9+7;


void initialize(){
        for(int i=0; i<MAX; i++)
                id[i] = i;
}

int root(int a){
        while(id[a]!=a) {

                id[a] = id[id[a]];
                a = id[a];

        }
        return a;
}

void union1 (int a,int b){
        a = root(a);
        b = root(b);
        if(a!=b)
                id[a] = id[b];
}
ll kruskal(pair < ll,pair <int,int> > p[]){
        int x,y;
        ll cost,minimumCost=1;
        for(int i=0; i<edges; i++) {
                x = p[i].second.first;
                y = p[i].second.second;
                cost = p[i].first;
                if(root(x) != root(y)) {
                        //cout << "cost :" << cost << endl;
                        minimumCost *= cost % MOD;
                        union1 (x,y);
                }

        }
        return minimumCost % MOD;

}

int main(void){
	int T;
	cin >> T;
	while(T--){
		pair < ll, pair<int,int> > p[MAX];
		int x,y,weight;
		cin >> nodes >> edges;
		initialize();
		for(int i=0; i<edges; i++) {
			cin >> x >> y >> weight;
			p[i] = make_pair(weight,make_pair(x,y));

		}
		sort(p,p+edges);
		/*
		for(int i=0; i<edges; i++) {
			cout << "weight : " << p[i].first << endl;
			cout << "a : " << p[i].second.first << endl;
			cout << "b : " << p[i].second.second << endl;
		}
		*/
		ll minimumCost = kruskal(p);
		cout << minimumCost << endl;
	}
        return 0;
}
