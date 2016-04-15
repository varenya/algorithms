#include <iostream>
#define MAX 5005
int id[MAX];
int nodes[MAX];

using namespace std;

void initialize(){
        for(int i=0; i<MAX; i++)
                id[i] = i;
}

int root(int x){
        if(id[x]!=x) {
                x = root(id[x]);
        }
        return id[x];
}
void union1(int a,int b){
        a = root(a);
        b = root(b);
        id[a] = id[b];
}


int main(void){

        int T,N,M;
        cin >> T;
        while(T--) {
                initialize();
                cin >> N >> M;
                int x,y;
                for(int i=0; i<M; i++) {
                        cin >> x >> y;
                        union1(x,y);
                }
                for(int i=1; i<N; i++)
                        cin >> nodes[i];
                for(int i=1; i<N; i++)
                        cout << nodes[i] << " " << root(nodes[i]) << endl;
                cout << endl;
                bool ans = true;
                for(int i=1; i<N; i++) {
                        for(int j=1; j<N; j++) {
                                if(i!=j && root(nodes[i]) == root(nodes[j]))
                                {

                                        ans = false;
                                        break;
                                }
                        }
                }
                if(ans)
                      cout << "YES" << endl;
                else
                      cout << "NO" << endl;
        }
}
