import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item>{
private class Node {
      Item item;
      Node next;
      Node prev;
}
private Node first,last;
private int count;

public Deque(){
        this.first = null;
        this.last = null;
        this.count = 0;
}

public boolean isEmpty(){
        return this.first == null && this.last == null;
}

public int size(){
        return this.count;
}
public void addFirst(Item item){
        if(item == null) {
                throw new NullPointerException("Adding null is not supported");
        }
        Node oldfirst = this.first;
        this.first = new Node();
        this.first.item = item;
        if(this.last == null) this.last = this.first;
        else{
                this.first.next = oldfirst;
                oldfirst.prev = this.first;
        }
        this.count += 1;
}

public void addLast(Item item){
        if(item == null) {
                throw new NullPointerException("Adding null is not supported");
        }
        Node oldlast = this.last;
        this.last = new Node();
        this.last.item = item;
        if(this.first == null) this.first = this.last;
        else {
                oldlast.next = this.last;
                this.last.prev = oldlast;
        }
        this.count += 1;
}

public Item removeFirst(){
        if(this.isEmpty()) {
                throw new NoSuchElementException("Queue is empty!");
        }
        Item item = this.first.item;
        if(this.first == this.last)
                this.last = null;
        this.first = this.first.next;
        if(this.first!=null)
                this.first.prev = null;
        this.count -= 1;
        return item;
}

public Item removeLast(){
        if(this.isEmpty()) {
                throw new NoSuchElementException("Queue is empty!");
        }
        Item item = this.last.item;
        this.last = this.last.prev;
        if(this.last!=null)
                this.last.next = null;
        this.count -= 1;
        return item;
}

public Iterator<Item> iterator(){
        return new ListIterator();
}

private class ListIterator implements Iterator<Item> {
        private Node current = first;
        public boolean hasNext(){
                return current!= null;
        }
        public Item next(){
                if (!hasNext()) throw new NoSuchElementException();
                Item item = current.item;
                current = current.next;
                return item;
        }
        public void remove(){
                throw new UnsupportedOperationException("remove is not supported");
        }
}

public static void main(String[] args){
        Deque<Integer> deque = new Deque<Integer>();
        for(int i=1; i<=5; i++)
                deque.addFirst(i);
        for(Integer q: deque)
                StdOut.println(q);
}

}
