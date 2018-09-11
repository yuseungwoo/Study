package fly;

public class stack {

	node pop_node;

	class node {
		int element;
		node next = null;
	}

	void set_pop_node(node push_node) {
		if (this.pop_node == null)
			this.pop_node = push_node;
		else {
			push_node.next = this.pop_node;
			this.pop_node = push_node;
		}
	}

	void push(int element) {
		node push_node = new node();
		push_node.element = element;
		set_pop_node(push_node);
	}

	int pop() {
		int ret = pop_node.element;
		this.pop_node = this.pop_node.next;
		return ret;
	}

	void print_all() {
		node tmp_node = this.pop_node;
		while (tmp_node != null) {
			System.out.println(tmp_node.element);
			tmp_node = tmp_node.next;
		}
	}
	/*
	public static void main(String[] args) {
		stack stack = new stack();
		int count = 0;
		while(count != 10) {
		stack.push(count);
		count++;
		}
		stack.print_all();
		count = 0;
		while(count != 10) {
		System.out.println("pop! :"+stack.pop());
		count ++;
		}
		stack.push(100);
		stack.print_all();
	}
	*/
}
