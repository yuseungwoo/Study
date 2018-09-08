package fly;


public class queue {
	node tail_queue=null;
	node head_queue=null;

	class node {
		int element;
		node next = null;
		
		node(int element){
			this.element = element;
		}
	}

	void enqueue(int element) {
		node new_queue_node = new node(element);
if(this.head_queue == null) {
	this.head_queue = new_queue_node;
	this.tail_queue = this.head_queue;
}
else {
	this.tail_queue.next = new_queue_node;
	this.tail_queue = new_queue_node;
}
	}

	int dequeue() {
		int ret = this.head_queue.element;
		this.head_queue = this.head_queue.next;
		
		if(this.head_queue == null)
			this.tail_queue = null;
		
		return ret;
	}
	void print_all() {
		node tmp_node = this.head_queue;
		while (tmp_node != null) {
			System.out.println(tmp_node.element);
			tmp_node = tmp_node.next;
		}
	}
	/*
	public static void main(String[] args) {
		Queue que  = new Queue();
		int count = 0;
		while(count != 10) {
		que.enqueue(count);
		count ++;
		}
        que.print_all();
        count = 0;
        while(count != 10) {
    		System.out.println("deQueue! : "+que.dequeue());
    		count ++;
    		}
        que.print_all();
        que.enqueue(100);
        que.print_all();
        System.out.println("deQueue! : "+que.dequeue());
        que.print_all();
	}
	*/
}
