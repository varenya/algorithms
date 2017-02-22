import java.util.NoSuchElementException;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdOut;
import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item>{
private Item[] a;
private int size;
public RandomizedQueue(){
        this.a = (Item[]) new Object[2];
        this.size = 0;
}

public boolean isEmpty(){
        return this.size == 0;
}
public int size(){
        return this.size;
}

private void resize(int capacity){
        assert capacity >= this.size;
        Item[] temp = (Item []) new Object[capacity];
        for(int i=0; i<this.size; i++) {
                temp[i] = this.a[i];
        }
        this.a = temp;
}

public void enqueue(Item item){
        if(item == null) {
                throw new NullPointerException("Adding null is not supported");
        }
        if(this.size == this.a.length) this.resize(2*a.length);
        this.a[this.size] = item;
        this.size += 1;
}
public Item dequeue(){
        if(this.isEmpty()) throw new NoSuchElementException("Queue is empty!");
        int index = StdRandom.uniform(this.size);
        Item elem = this.a[index];
        if( index == this.size-1) {
                this.a[index] = null;
        }
        else{
                this.a[index] = this.a[this.size-1];
                this.a[this.size-1] = null;
        }
        if(this.size > 0 && this.size == this.a.length/4) this.resize(this.a.length/2);
        this.size -= 1;
        return elem;
}

public Item sample(){
        if(this.isEmpty()) throw new NoSuchElementException("Queue is empty!");
        int index = StdRandom.uniform(this.size);
        Item item = this.a[index];
        return item;
}
public Iterator<Item> iterator(){
        return new QueueIterator();
}

private class QueueIterator implements Iterator<Item>{
  private int N = size;
  private Item[] copy = (Item[])new Object[size];
  public QueueIterator(){
    for(int i=0;i<size;i++)
    copy[i] = a[i];

  }

  public boolean hasNext(){
    return this.N != 0;
  }
  public void remove(){
    throw new UnsupportedOperationException("Remove is not supported");
  }
  public Item next(){
    if(!hasNext()) throw new NoSuchElementException("Queue is empty");
    int i = StdRandom.uniform(this.N);
    if(i == N-1){
      this.N -= 1;
      return copy[i];
    }
    else{
      Item item = copy[i];
      copy[i] = copy[this.N-1];
      copy[this.N-1] = item;
      this.N -= 1;
      return item;
    }
  }
}

public static void main(String[] args){
        RandomizedQueue<Integer> rqueue = new RandomizedQueue<Integer>();
        for(int i=1; i<=10; i++) {
                rqueue.enqueue(i);
        }
        for(Integer q:rqueue )
                StdOut.println(q);
        StdOut.println("Before");
        // while(!rqueue.isEmpty()) {
        //         StdOut.println(rqueue.dequeue());
        // }
        StdOut.println("Done");
        for(Integer q:rqueue )
                StdOut.println(q);
}
}
