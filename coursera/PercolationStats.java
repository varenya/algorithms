import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdOut;
import java.lang.Math;

public class PercolationStats {

private int N;
private int T;
private double[] trialResults;
private Percolation perc;

public PercolationStats(int number,int trials){
        if( number <=0 || trials <= 0){
          throw new java.lang.IllegalArgumentException("Arguments cannot be less than zero");
        }
        this.N = number;
        this.T = trials;
        this.trialResults = new double[trials];
        for(int t=0; t<trials; t++) {
                Percolation perc = new Percolation(number);
                double size = number * number;
                while(!perc.percolates()) {
                  int row = StdRandom.uniform(1,number+1);
                  int col = StdRandom.uniform(1,number+1);
                  perc.open(row,col);
                }
                this.trialResults[t] = perc.numberOfOpenSites()/size;
        }
}

public double mean(){
        return StdStats.mean(this.trialResults);
}

public double stddev(){
        return StdStats.stddev(this.trialResults);
}

public double confidenceLo(){
        double result = mean() - (1.96*stddev())/Math.sqrt(this.T);
        return result;
}

public double confidenceHi(){
        double result = mean() + (1.96*stddev())/Math.sqrt(this.T);
        return result;
}

public static void main(String[] args){
        int number = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        PercolationStats percStats = new PercolationStats(number,trials);

        StdOut.println("mean                     = "+percStats.mean());
        StdOut.println("stddev                   = "+percStats.stddev());
        StdOut.println("95%% confidence interval = ["+percStats.confidenceLo()+ "," + percStats.confidenceHi()+ "]");

}

}
