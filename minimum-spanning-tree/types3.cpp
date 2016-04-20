#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define MAX 100005
#define pii pair <int,int>
#define ll long long
using namespace std;
int id[MAX],nodes,edges;

set < pair<int,int> > men_min;
set < pair<int,int> > women_min;


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
ll kruskal(pair < ll,pair <int,int> > p[],bool men){
        int x,y;
        ll cost,minimumCost=0;
        for(int i=0; i<edges; i++) {
                x = p[i].second.first;
                y = p[i].second.second;
                cost = p[i].first;
		if (men && (cost == 1 || cost == 3)){
			if(root(x) != root(y)) {
				cout << "cost :" << cost << endl;
				minimumCost += cost;
				men_min.insert(make_pair(x,y));
				union1 (x,y);
			}
		}
		else if(!men && (cost == 2 || cost == 3) ){
			if(root(x) != root(y)) {
				cout << "cost :" << cost << endl;
				minimumCost += cost;
				women_min.insert(make_pair(x,y));
				union1 (x,y);
			}
		}

        }
        return minimumCost;

}

void printVector (vector <pii> input){
	vector <pii>::iterator it;
	cout << "Printing Vector ....."<<endl;
	for(it=input.begin();it!=input.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}
void printSet (set <pii> input){
	set <pii>::iterator it;
	cout << "Printing set ....."<<endl;
	for(it=input.begin();it!=input.end();it++){
		cout << it->first << " " << it->second << endl;
	}
	cout << endl;
}


int main(void){
	pair < ll, pair<int,int> > p[MAX];
	set <pii> edgev;
	int x,y,weight;
	cin >> nodes >> edges;
	initialize();
	for(int i=0; i<edges; i++) {
		cin >> x >> y >> weight;
		p[i] = make_pair(weight,make_pair(x,y));
		edgev.insert(make_pair(x,y));

	}
	sort(p,p+edges);
	for(int i=0; i<edges; i++) {
		cout << "weight : " << p[i].first << endl;
		cout << "a : " << p[i].second.first << endl;
		cout << "b : " << p[i].second.second << endl;
	}
	ll minimumCostMen = kruskal(p,true);
	initialize();
	ll minimumCostWomen = kruskal(p,false);
	vector <pii> men_diff;
	vector <pii> women_diff;
	set <pii> soln;

	vector <pii>::iterator it;
	set <pii>::iterator found;
	set <pii>::iterator found2;

	printSet(men_min);
	printSet(women_min);
	cout << "edges" << endl;
	printSet(edgev);

	cout << "first" << endl;
	it = set_difference(edgev.begin(),edgev.end(),men_min.begin(),men_min.end(),men_diff.begin());
	men_diff.resize(it-men_diff.begin());

	cout << "end" << endl;
	it = set_difference(edgev.begin(),edgev.end(),women_min.begin(),women_min.end(),women_diff.begin());
        women_diff.resize(it-women_diff.begin());

	printVector(men_diff);
	printVector(women_diff);

	for(it = men_diff.begin();it!=men_diff.end();it++){
		found = women_min.find(*it);
		found2 = soln.find(*it);
		if( found != women_min.end() && found2 == soln.end())
			soln.insert(*found);
	}
	for(it = women_diff.begin();it!= women_diff.end();it++){
		found = men_min.find(*it);
		found2 = soln.find(*it);
		if( found != men_min.end() && found2 == soln.end())
			soln.insert(*found);
	}


	cout << soln.size() << endl;
	return 0;
}
