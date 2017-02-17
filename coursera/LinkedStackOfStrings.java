import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;

public class LinkedStackOfStrings {
private Node first = null;
private class Node {
String item;
Node next;
}

public boolean isEmpty(){
        return first == null;
}
public void push(String pushItem){
        Node oldfirst = this.first;
        this.first = new Node();
        this.first.item = pushItem;
        this.first.next = oldfirst;
}
public String pop(){
        String item = this.first.item;
        this.first = this.first.next;
        return item;
}

public static void main(String[] args){
        LinkedStackOfStrings stack = new LinkedStackOfStrings();
        while(!StdIn.isEmpty()) {
                String s = StdIn.readString();
                // StdOut.println("Input String: " + s);
                if(s.equals("-"))
                        StdOut.println(stack.pop());
                else
                        stack.push(s);

        }
      }
}
