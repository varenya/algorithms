import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdIn;

public class Permutation {
        public static void main(String[] args){
                int k = Integer.parseInt(args[0]);
                RandomizedQueue<String> rqueue = new RandomizedQueue<String>();
                while(!StdIn.isEmpty()) {
                        String input = StdIn.readString();
                        rqueue.enqueue(input);
                }
                while(k > 0) {
                        StdOut.println(rqueue.dequeue());
                        k--;
                }
        }
}
