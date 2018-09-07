

public class linked_list {
	node head_node = null;
	node tail_node = null;
	int list_length = 0;

	class node {
		int element;
		node next;
	}

	void set_head_node(node head_node) {
		this.head_node = head_node;
		if (head_node == null)
			set_tail_node(null);
		if (this.list_length == 0)
			set_tail_node(head_node);
	}

	void set_tail_node(node tail_node) {
		this.tail_node = tail_node;
	}

	void add_node(int element) {
		node tmp_node = this.head_node;

		if (this.head_node == null) {
			set_head_node(new node());
			set_tail_node(this.head_node);
			this.head_node.element = element;
			this.head_node.next = null;
		}

		else {
			while (tmp_node.next != null) {
			tmp_node = tmp_node.next;				
			}
			
			tmp_node.next = new node();
			set_tail_node(tmp_node.next);
			tmp_node.next.element = element;
			tmp_node.next.next = null;
		}
		
		this.list_length++;
	}

	
	void add_node_tail(int element) {

		if (this.head_node == null) {
			set_head_node(new node());
			set_tail_node(this.head_node);
			this.head_node.next = null;
			this.head_node.element = element;
			return;
		}

		this.tail_node.next = new node();
		set_tail_node(this.tail_node.next);
		this.tail_node.element = element;
		this.tail_node.next = null;

		this.list_length++;
	}

	boolean add_node_num(int num, int element) {
		if (num > this.list_length)
			return false;

		node tmp_node = this.head_node, new_node;
		int tmp_length = 0;

		new_node = new node();
		new_node.element = element;

		if (num == 0) {
			new_node.next = this.head_node;
			set_head_node(new_node);

		}

		else {
			while (tmp_length != num - 1) {
				tmp_node = tmp_node.next;
				tmp_length++;
			}

			new_node.next = tmp_node.next;
			tmp_node.next = new_node;

			if (num == this.list_length)
				set_tail_node(new_node);
		}

		this.list_length++;
		return true;
	}

	boolean del_node(node del_node) {
		node tmp_node = this.head_node;

		if (tmp_node == null)
			return false;

		if (del_node == this.head_node)
			set_head_node(this.head_node.next);

		else {
			while (tmp_node.next != del_node || tmp_node.next == null) {
				tmp_node = tmp_node.next;
			}

			if (tmp_node.next == null)
				return false;

			if (tmp_node.next == this.tail_node)
				set_tail_node(tmp_node);

			tmp_node.next = tmp_node.next.next;
		}

		this.list_length--;
		return true;
	}

	
	boolean del_node(int num) {

		if (num > this.list_length - 1 || this.list_length == 0)
			return false;

		if (num == 0) {
			set_head_node(this.head_node.next);
			this.list_length--;
			return true;
		}

		node tmp_node = this.head_node;
		int tmp_length = 0;

		while (num - 1 != tmp_length) {
			tmp_node = tmp_node.next;
			tmp_length++;
		}

		if ( tmp_node.next.next == null)
			set_tail_node(tmp_node);

		tmp_node.next = tmp_node.next.next;

		this.list_length--;
		return true;
	}

	void print_all() {
		node tmp_node = this.head_node;
		while (tmp_node != null) {
			System.out.print(tmp_node.element + "  ");
			tmp_node = tmp_node.next;
		}
		System.out.println();
	}

	void print_node(int num) {
		node tmp_node = this.head_node;
		int tmp_length = 0;
		if (num > this.list_length) {
			System.out.println("Unexpected list num..");
			return;
		}
		while (tmp_length != num) {
			tmp_node = tmp_node.next;
			tmp_length++;
		}
		System.out.println("list[" + num + "] :" + tmp_node.element);
	}

	public static void main(String[] args) {
		linked_list L_l = new linked_list();
		// System.out.println("add_node null head ");
		L_l.add_node(1);
		L_l.add_node(22);
		L_l.add_node(33);
		if (!L_l.add_node_num(0, 2))
			System.out.println("fail add");
		if (!L_l.add_node_num(2, 3))
			System.out.println("fail add");
		if (!L_l.add_node_num(10, 100))
			System.out.println("fail add");
		L_l.add_node_tail(4);
		L_l.print_all();
		
		if(!L_l.del_node(1))
			System.out.println("fail del");
		if(!L_l.del_node(2))
			System.out.println("fail del");
		if(!L_l.del_node(10))
			System.out.println("fail del");
		L_l.print_all();
		L_l.print_node(2);
	}
}
