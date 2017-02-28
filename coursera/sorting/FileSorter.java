import java.io.File;
import edu.princeton.cs.algs4.StdOut;
public class FileSorter {
public static void main(String[] args){
        File directory = new File(args[0]);
        File[] files = directory.listFiles();
        Merge.sort(files);
        for(int i=0; i<files.length; i++)
                StdOut.println(files[i]);
        Integer[] test = {4,3,2,1,0,5};
        Merge.sort(test);
        for(int i=0; i<test.length; i++)
                StdOut.println(test[i]);
}
}
