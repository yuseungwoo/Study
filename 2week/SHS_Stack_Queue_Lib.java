package fly;

import java.util.Stack;
import sun.misc.Queue;
//import java.util.Queue;   with Linked_list

public class Stack_Queue_Lib {

	public static void main(String[] args) {
		Stack stack = new Stack();

		stack.push(new Integer(4321));
		stack.push(new String("Push"));
		stack.push("stack");
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		System.out.println(stack.pop());
		// System.out.println(stack.pop()); EmptyStackException
		System.out.println("\n");
		
		Queue que = new Queue();

		que.enqueue(new Integer(1234));
		que.enqueue(new String("enqueue"));
		que.enqueue("queue");
		try {
			System.out.println(que.dequeue());
			System.out.println(que.dequeue());
			System.out.println(que.dequeue());
			//System.out.println(que.dequeue());
			
		} catch (InterruptedException e) {
			System.out.println("exception..");
			e.printStackTrace();
		}
	}

}
