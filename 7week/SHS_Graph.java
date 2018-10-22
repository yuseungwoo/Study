
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

		node node_adr ;
		connect_node next_conn_node = null;
		int weight;

		connect_node(node node_adr, int weight) {
			this.node_adr = node_adr;
			this.weight = weight;
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
			
			while ( conn_node != null && conn_node.node_adr!=dest_node ) {
				conn_node = conn_node.next_conn_node;				
			}
			
			if(conn_node==null) {
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
		node node_1 = create_node(node1);
		node node_2 = create_node(node2);
		create_conn_node(this.create_new_node, node_1, node_2, weight);
		create_conn_node(this.create_new_node, node_2, node_1, weight);
		this.create_new_node = false;

	}
	/*
	 * void find_shortest(char node1, char node2) { node tmp_node = head_node; node
	 * node_1 = null, node_2 = null; while(node_1!=null || node_2!=null) {
	 * if(tmp_node)
	 * 
	 * if(tmp_node==null) { System.out.println("Not exist Node!"); return; } }
	 */

	void print_graph() {
		node tmp_node = this.head_node;
		while (tmp_node != null) {
			System.out.print(tmp_node.name+" : ");
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

		gp.connect_node('b', 'c', 3);
		gp.connect_node('a', 'c', 5);
		gp.print_graph();
		gp.connect_node('a', 'b', 3);
		gp.connect_node('a', 'e', 100);
		gp.connect_node('a', 'e', 15);
		gp.print_graph();
	}

}
