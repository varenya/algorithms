import edu.princeton.cs.algs4.WeightedQuickUnionUF;
import java.lang.IllegalArgumentException;
import edu.princeton.cs.algs4.*;
import java.lang.Math.*;

public class Percolation {

private boolean[][] grid;
private WeightedQuickUnionUF uf;
private int N;
private int numberOfOpen;
private int satellite1;
private int satellite2;

public Percolation(int N){

        if(N <= 0) {
                throw new IllegalArgumentException("number of grid cell cannot be less than or equal to zero");
        }

        this.N = N;
        this.numberOfOpen = 0;
        // Adding 2 so as to avoid many boundary checks
        grid = new boolean[N+2][N+2];
        this.uf = new WeightedQuickUnionUF(N*N+3);
        this.satellite1 = 0;
        this.satellite2 = N*N + 1;
        // Connecting all top cells to a satellite to have easier check if system percolates
        for(int j=1; j<=N; j++)
                this.uf.union(this.satellite1,j);
        // Similar to above but for bottom row
        for(int j=N*(N-1)+1; j<=N*N; j++)
                this.uf.union(this.satellite2,j);

        // Setting all the grid values to false initially
        for(int i=0; i<=N; i++) {
                for(int j=0; j<=N; j++) {
                        grid[i][j] = false;
                }
        }
}

private boolean inRange(int index){
        return index >= 1 && index <= this.N;
}
private int getIndex(int row,int col){
        return row * this.N + col - this.N;
}

public void open(int row, int col){
        // StdOut.printf("row %d , col %d",row,col);
        // StdOut.println();
        if( !inRange(row) && !inRange(col) ) {
                throw new java.lang.IndexOutOfBoundsException("row and column cannot be more than N and less than 1");
        }
        int left = 0, right = 0, top = 0,bottom = 0;
        int current = getIndex(row,col);
        if(this.N == 1){
            this.grid[row][col] = true;
        }
        else{
                top = getIndex(row-1,col);
                bottom = getIndex(row+1,col);
                left = getIndex(row,col-1);
                right = getIndex(row,col+1);
                if( isOpen(row-1,col) )
                        this.uf.union(current,top);
                if( isOpen(row+1,col) )
                        this.uf.union(current,bottom);
                if( isOpen(row,col-1) )
                        this.uf.union(current,left);
                if( isOpen(row,col+1) )
                        this.uf.union(current,right);
        }
        this.numberOfOpen += 1;
        this.grid[row][col] = true;
}

public boolean isOpen(int row,int col){
        // StdOut.printf("row %d , col %d \n",row,col);
        if( !inRange(row) && !inRange(col) && this.N!=1) {
                throw new java.lang.IndexOutOfBoundsException("row and column cannot be more than N and less than 1");
        }
        return this.grid[row][col];
}

public boolean isFull(int row,int col){
        if( !inRange(row) && !inRange(col) ) {
                throw new java.lang.IndexOutOfBoundsException("row and column cannot be more than N and less than 1");
        }
        int current = getIndex(row,col);
        return this.uf.connected(this.satellite1,current);
}

public int numberOfOpenSites(){
        return this.numberOfOpen;
}

public boolean percolates(){
        if(this.N == 1) {
                return this.grid[1][1];
        }
        return this.uf.connected(this.satellite1,this.satellite2);
}

public static void main(String[] args){
        int N = StdIn.readInt();
        Percolation perc = new Percolation(N);
        while(!StdIn.isEmpty()) {
                int row = StdIn.readInt();
                int col = StdIn.readInt();
                perc.open(row,col);
        }

        if(perc.percolates()) {
                StdOut.println("System Percolates!");
        }
        else{
                StdOut.println("System doesnt percolate!");
        }
}

}
