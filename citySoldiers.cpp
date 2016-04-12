#include <iostream>
#include <set>
#include <vector>
#include <utility>
#define MAX 100007
#define mp make_pair
#define PII pair<int,int>
using namespace std;

int parent[MAX];
int size[MAX];

multiset <PII> sizes;

void init(int N){
        for(int i=1; i<=N; i++) {
                parent[i]=i;
                size[i] = 1;
                sizes.insert(mp(i,1));
        }
}
void optimizeIO()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
}

int ancestor(int num){

        if(parent[num] != num)
                parent[num] = ancestor(parent[num]);
        return parent[num];
}

void swap(int a,int b){
        int temp = size[a];
        size[a] = size[b];
        size[b] = temp;
}

void mergeSet(int a,int b){

        a = ancestor(a);
        b = ancestor(b);
        if (a == b)
                return;

        //sizes.erase(sizes.find(mp(a,size[a])));
        //sizes.erase(sizes.find(mp(b,size[b])));

        size[b] += size[a];
        parent[a] = b;

        //sizes.insert(mp(b,size[b]));
}

void changeGroup(int a,int N){
        int temp = ancestor(a);
        parent[temp] = parent[a] = a;
}


int main(void)
{

        optimizeIO();

        int N,Q,count = 0;
        cin >> N >> Q;
        //cout << "Q :" << Q << endl;
        init(N);
        while(Q--) {
                int q,a,b;
                cin >> q;
                if (q==1) {
                        cin >> a >> b;
                        mergeSet(a,b);
                }
                else if (q==2) {
                        cin >> a;
                        changeGroup(a,N);
                }
                else if(q==3) {
                        cin >> a;
                        cout << ancestor(a) << endl;
                        //cout << count << endl;
                        //count++;
                }
        }

}
