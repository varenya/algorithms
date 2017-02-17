import edu.princeton.cs.algs4.StdOut;
public class Queue<Item> {
  private Stack<Item> inbox = new Stack<Item>();
  private Stack<Item> outbox = new Stack<Item>();
  private class Node{
        Item item;
        Node next;
  }

  public void enqueue(Item item){
    this.inbox.push(item);
  }

  public Item dequeue(){
    if(outbox.isEmpty()){
        while(!inbox.isEmpty()){
            outbox.push(inbox.pop());
        }
    }
    return outbox.pop();
  }

  public boolean isEmpty(){
    return this.inbox.isEmpty() && this.outbox.isEmpty();
  }

  public static void main(String[] args){
      Queue<Integer> queue = new Queue<Integer>();
      queue.enqueue(1);
      queue.enqueue(2);
      queue.enqueue(3);
      queue.enqueue(4);
      while(!queue.isEmpty()){
          StdOut.println(queue.dequeue());
      }

  }



}
