import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;

public class Stack<Item> implements Iterable<Item>{
  private Node first;
  private Stack<Item> maxStack = new Stack<Item>();
  private class Node {
      Item item;
      Node next;
  }

  public Item pop(){
          Item item = first.item;
          first = first.next;
          return item;
  }
  public boolean isEmpty(){
          return first == null;
  }

  public void push(Item item){
          Node oldfirst = first;
          this.first = new Node();
          first.next = oldfirst;
          first.item = item;

  }

  public Iterator<Item> iterator(){
    return new ListIterator();
  }

  private class ListIterator implements Iterator<Item>
  {
      private Node current = first;
      public boolean hasNext(){ return current!= null; };
      public void remove(){}
      public Item next(){
        Item item = current.item;
        current = current.next;
        return item;
      }
  }
  public static void main(String[] args){
          Stack<String> stack = new Stack<String>();
          stack.push("hello");
          stack.push("world");
          for(String s: stack){
            StdOut.println(s);
          }
  }

}
