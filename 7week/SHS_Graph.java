
public class Graph {
	node head_node = null;
	node tail_node = null;
	boolean create_new_node = false;

	class node {
		char name;
		node next_node = null;
		connect_node head_conn_node = null;
		connect_node tail_conn_node = null;
		boolean passed = false;

		node(char name) {
			this.name = name;
		}
	}

	class connect_node {

		node node_adr;
		connect_node next_conn_node = null;
		int weight;

		connect_node(node node_adr, int weight) {
			this.node_adr = node_adr;
			this.weight = weight;
		}

	}

	class path_info {
		int weights = -1;
		node_stack node_stack_head = null;

		path_info(node_stack n_stack) {

			node_stack_head = n_stack;
		}

		path_info(int weight) {
			this.weights = weight;
		}

		void push(node node) {
			node_stack new_stack_node = new node_stack(node);
			new_stack_node.next_node_stack = this.node_stack_head;
			this.node_stack_head = new_stack_node;
		}
	}

	class node_stack {
		node node;
		node_stack next_node_stack = null;

		node_stack(node node) {
			this.node = node;
		}
	}

	 void find_shortest_path(char node1, char node2) {

		node tmp_node = this.head_node;
		
		while(tmp_node.name != node1) {			
			tmp_node = tmp_node.next_node;
			if(tmp_node==null) {			
				System.out.println("NOT Exist node!");
				return;				
			}
		}
	
		path_info shortest_path_info = search_path(tmp_node,node2,0);
		
		System.out.println("shortest path weight : "+shortest_path_info.weights);
		
		node_stack tmp_n_stack = shortest_path_info.node_stack_head;	
		while(tmp_n_stack!=null) {
			System.out.print(tmp_n_stack.node.name);
			tmp_n_stack = tmp_n_stack.next_node_stack;
			if(tmp_n_stack!=null)
			System.out.print("->");
		}
		System.out.println();
	}

	 
	path_info search_path(node while_node, char node2, int weight) {

		if (while_node.name == node2) {
			node_stack new_node_stack = new node_stack(while_node);
			path_info ret_path_info = new path_info(new_node_stack);
			ret_path_info.weights = weight;
			return ret_path_info;
		}

		while_node.passed = true;

		path_info ret_path_info = new path_info(-1);
		int shortest_weight = -1;

		connect_node tmp_node = while_node.head_conn_node;
		while (tmp_node != null) {

			if (tmp_node.node_adr.passed) {
				tmp_node = tmp_node.next_conn_node;
				continue;
			}

			path_info sub_path_info = search_path(tmp_node.node_adr, node2, tmp_node.weight);

			if (sub_path_info.weights != -1) {
				
			if (shortest_weight > sub_path_info.weights || shortest_weight == -1) {
					shortest_weight = sub_path_info.weights;
					ret_path_info = sub_path_info;
					}

			}

			tmp_node = tmp_node.next_conn_node;
		}

		while_node.passed = false;
		
		if (shortest_weight == -1)
			return ret_path_info;

		else {
			ret_path_info.weights += weight;
			ret_path_info.push(while_node);
			return ret_path_info;
		}

	}

	node create_node(char name) {
		if (this.head_node == null) {
			this.head_node = new node(name);
			this.tail_node = this.head_node;
			return this.head_node;
		}

		node tmp_node = this.head_node;

		while (tmp_node != null) {
			if (tmp_node.name == name)
				return tmp_node;

			tmp_node = tmp_node.next_node;
		}

		this.tail_node.next_node = new node(name);
		this.tail_node = this.tail_node.next_node;
		create_new_node = true;
		return this.tail_node;
	}

	void create_conn_node(boolean new_node, node origin_node, node dest_node, int weight) {
		if (new_node) {// create new conn node
			if (origin_node.head_conn_node == null) {
				origin_node.head_conn_node = new connect_node(dest_node, weight);
				origin_node.tail_conn_node = origin_node.head_conn_node;
			}

			else {
				origin_node.tail_conn_node.next_conn_node = new connect_node(dest_node, weight);
				origin_node.tail_conn_node = origin_node.tail_conn_node.next_conn_node;
			}
		}

		else { // update weight
			connect_node conn_node = origin_node.head_conn_node;

			while (conn_node != null && conn_node.node_adr != dest_node) {
				conn_node = conn_node.next_conn_node;
			}

			if (conn_node == null) {
				this.create_new_node = true;
				create_conn_node(this.create_new_node, origin_node, dest_node, weight);
			}

			else
				conn_node.weight = weight;
		}

	}

	void connect_node(char node1, char node2, int weight) {
		if (node1 == node2)
			return;
		if (weight < 1) {
			System.out.println("weight should be bigger than 0!");
			return;
		}
		
		node node_1 = create_node(node1);
		node node_2 = create_node(node2);
		create_conn_node(this.create_new_node, node_1, node_2, weight);
		create_conn_node(this.create_new_node, node_2, node_1, weight);
		this.create_new_node = false;

	}

	void print_graph() {
		node tmp_node = this.head_node;
		while (tmp_node != null) {
			System.out.print(tmp_node.name + " : ");
			connect_node tmp_conn_node = tmp_node.head_conn_node;
			while (tmp_conn_node != null) {
				System.out.print(tmp_conn_node.node_adr.name + "-" + tmp_conn_node.weight + " ");
				tmp_conn_node = tmp_conn_node.next_conn_node;
			}
			System.out.println();
			tmp_node = tmp_node.next_node;
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Graph gp = new Graph();

		gp.connect_node('a', 'b', 1);

		gp.connect_node('b', 'c', 4);
		gp.connect_node('c', 'a', 5);
		gp.connect_node('a', 'b', 10);
		gp.connect_node('a', 'e', 500);	
		gp.connect_node('a', 'e', 5);
		gp.connect_node('e', 'b', 5);
		gp.print_graph();
		gp.find_shortest_path('a','b');
		gp.connect_node('e', 'g', 1);
		gp.connect_node('g', 'b', 1);
		gp.find_shortest_path('a','b');
	}

}
