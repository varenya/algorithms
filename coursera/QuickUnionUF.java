public class QuickUnionUF {
private int[] id;
private int[] sz;

public QuickUnionUF(int N){
        id = new int[N];

        for(int i=0; i<N; i++) {
                id[i] = i;
                sz[i] = 1;
        }
}

private int root(int i){
        while(i != id[i]) {
                // Setting each node to its grandparent there by compressing the patht o half!
                id[i] = id[id[i]];
                i = id[i];
        }
        return i;
}

public boolean connected(int p, int q){
        int rootp = root(p);
        int rootq = root(q);
        return rootp == rootq;
}

public void union(int p,int q){
        int i = root(p);
        int j = root(q);
        if( i == j ) return;
        // This is weighted Union compare the sizes of the components before setting the parent here by keeping the height to atmost logN
        if ( sz[i] > sz[j] ) {
                id[j] = i;
                sz[j] += sz[i];
        }
        else{
                id[i] = j;
                sz[i] += sz[j];
        }
}

}
