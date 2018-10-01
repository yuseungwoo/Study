import java.util.*;


public class PQ_Heap {

	class Node {
		int rank;
		Node top_node;
		Node left_node = null;
		Node right_node = null;

		Node(Node top_node, int rank) {
			this.top_node = top_node;
			this.rank = rank;
		}
	}

	Node root_node = null;
	int node_arr_index = 0;
	boolean exist_left_node = false;
	ArrayList<Node> Layer_arr = new ArrayList<Node>();

	void add_node(int rank) {

		if (this.root_node == null) { // exist nothing
			this.root_node = new Node(null,rank);
			Layer_arr.add(this.root_node);
			return;
		}

		if (!exist_left_node) {
			Layer_arr.get(node_arr_index).left_node = new Node(Layer_arr.get(node_arr_index),rank);
			add_process(Layer_arr.get(node_arr_index).left_node);
		}

		else {
			Layer_arr.get(node_arr_index).right_node = new Node(Layer_arr.get(node_arr_index),rank);
			add_process(Layer_arr.get(node_arr_index).right_node);

			node_arr_index++;

			if (node_arr_index == this.Layer_arr.size())
				next_Layer_arr();

		}

		exist_left_node = !exist_left_node;
	}

	void add_process(Node last_node) {
		Node tmp_node = last_node;
		while (tmp_node.top_node != null) {

			if (tmp_node.rank < tmp_node.top_node.rank) {

				int tmp_rank = tmp_node.top_node.rank;
				tmp_node.top_node.rank = tmp_node.rank;
				tmp_node.rank = tmp_rank;

				tmp_node = tmp_node.top_node;
			} else
				break;
		}
	}

	void next_Layer_arr() {
		int current_layer_size = this.Layer_arr.size(), count = 0;
		while (count != current_layer_size) {

			this.Layer_arr.add(this.Layer_arr.get(0).left_node);
			this.Layer_arr.add(this.Layer_arr.get(0).right_node);
			this.Layer_arr.remove(0);

			count++;
		}
		this.node_arr_index = 0;

	}

	int del_node() {
		if(this.root_node == null)
			return -1;
		
		int last_rank = 0, ret = this.root_node.rank;
			
		if (!this.exist_left_node) { // exist all or first node in new Layer

			if (this.Layer_arr.size() == 1) { // only exist root node
				this.root_node = null;
				this.Layer_arr.clear();
				//System.out.println("Arr size after clear :" + this.Layer_arr.size());		
				return ret;
			}

			
			if (this.node_arr_index == 0) // first node in new Layer
				previus_Layer_arr();


			else
				this.node_arr_index--;
			

			last_rank = this.Layer_arr.get(node_arr_index).right_node.rank;
			this.Layer_arr.get(node_arr_index).right_node = null;

		}

		else {// exist only left
			last_rank = this.Layer_arr.get(node_arr_index).left_node.rank;
			this.Layer_arr.get(node_arr_index).left_node = null;
		}

		exist_left_node = !exist_left_node;
		del_process(last_rank);
		return ret;
	}

	void del_process(int last_rank) {
		Node tmp_node = this.root_node;
		int tmp_rank = 0;
		this.root_node.rank = last_rank;
		while (tmp_node != null) {

			if (tmp_node.left_node == null) // not exist
				break;

			else if (tmp_node.right_node != null) { // exist all node
				
				if (tmp_node.left_node.rank < tmp_node.right_node.rank)
					tmp_node = tmp_node.left_node;
				
				else
					tmp_node = tmp_node.right_node;

			}

			else // exist only left
				tmp_node = tmp_node.left_node;

			
			if (tmp_node.top_node.rank > tmp_node.rank) {
				tmp_rank = tmp_node.rank;
				tmp_node.rank = tmp_node.top_node.rank;
				tmp_node.top_node.rank = tmp_rank;
			}

			else
				break;
		}
	}

	void previus_Layer_arr() {
		
		int current_layer_size = this.Layer_arr.size() >> 1, count = 0;

		while (count != current_layer_size) {

			this.Layer_arr.add(this.Layer_arr.get(0).top_node);
			this.Layer_arr.remove(0);
			this.Layer_arr.remove(0);
			count++;
		}
		
		this.node_arr_index = this.Layer_arr.size() - 1;

	}
	
	void print_tree() {
		ArrayList<Node> node_arr = new ArrayList<Node>();
		Node tmp_node = this.root_node;
		int list_index = 0, last_list_index = 1, count = 0;
		node_arr.add(tmp_node);
		System.out.println("root " + node_arr.get(0).rank + "\n");

		while (!node_arr.isEmpty()) {

			while (count != last_list_index) {

				if (node_arr.get(0).left_node != null) {
					System.out.print(node_arr.get(0).left_node.rank);
					node_arr.add(node_arr.get(0).left_node);
					list_index++;
				} else
					System.out.print(" ");

				System.out.print("   ");

				if (node_arr.get(0).right_node != null) {
					System.out.print(node_arr.get(0).right_node.rank);
					node_arr.add(node_arr.get(0).right_node);
					list_index++;
				} else
					System.out.print(" ");

				node_arr.remove(0);
				count++;
				System.out.print(" ");
			}
			last_list_index = list_index;
			list_index = 0;
			count = 0;
			System.out.println("\n");
		}

	}
	
	public static void main(String[] args) {
		PQ_Heap pq_heap = new PQ_Heap();
		
		pq_heap.add_node(1);
		System.out.println("pop : "+pq_heap.del_node());
		pq_heap.add_node(1);
		pq_heap.add_node(10);
		pq_heap.add_node(3);

		pq_heap.add_node(5);

		pq_heap.add_node(4);

		pq_heap.add_node(11);
		pq_heap.add_node(7);
		pq_heap.add_node(2);
		pq_heap.print_tree();
		System.out.println("pop : "+pq_heap.del_node());
		pq_heap.print_tree();
		pq_heap.add_node(100);
		pq_heap.print_tree();
		
		System.out.println("pop : "+pq_heap.del_node());
		pq_heap.print_tree();
		pq_heap.add_node(700);
		pq_heap.print_tree();
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		System.out.println("pop : "+pq_heap.del_node());
		pq_heap.add_node(100);
		pq_heap.add_node(1);
		pq_heap.print_tree();
	}
	
}
