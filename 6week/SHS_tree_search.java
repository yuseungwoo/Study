import java.util.ArrayList;

public class tree_search {
	node root = null;

	class node {
		int element;
		node left = null;
		node right = null;

		node(int element) {
			this.element = element;
		}
	}

	void add_node(int[] elements) {

		for (int i = 0; i < elements.length; i++) {
			node new_node = new node(elements[i]);
			node new_node_adr = this.root;

			if (i == 0) {
				this.root = new_node;
				continue;
			}

			while (new_node_adr != null) {

				if (new_node_adr.element > elements[i]) {

					if (new_node_adr.left == null)
						new_node_adr.left = new_node;

					new_node_adr = new_node_adr.left;
				}

				else if (new_node_adr.element < elements[i]) {

					if (new_node_adr.right == null)
						new_node_adr.right = new_node;

					new_node_adr = new_node_adr.right;
				}

				else
					break;
			}

		}

	}

	boolean search_num(int element) {
		node tmp_node = this.root;

		while (tmp_node != null) {
			System.out.println("dis element : " + tmp_node.element);
			
			if (tmp_node.element > element)
				tmp_node = tmp_node.left;

			else if (tmp_node.element < element)
				tmp_node = tmp_node.right;
			else
				return true;
		}

		return false;
	}

	void print_tree() {
		ArrayList<node> node_arr = new ArrayList<node>();
		node tmp_node = this.root;
		int list_index = 0, last_list_index = 1, count = 0;
		node_arr.add(tmp_node);
		System.out.println("root " + node_arr.get(0).element + "\n");

		while (!node_arr.isEmpty()) {

			while (count != last_list_index) {

				if (node_arr.get(0).left != null) {
					System.out.print("L" + node_arr.get(0).left.element);
					node_arr.add(node_arr.get(0).left);
					list_index++;
				} else
					System.out.print(" ");

				System.out.print("   ");

				if (node_arr.get(0).right != null) {
					System.out.print("R" + node_arr.get(0).right.element);
					node_arr.add(node_arr.get(0).right);
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
/*
	public static void main(String[] args) {
		tree_search ts = new tree_search();
		int[] arr = { 5, 8, 4, 3, 13, 7, 55, 1, 3, 10 };
		ts.add_node(arr);
		ts.print_tree();
		System.out.println(ts.search_num(56));
	}
	*/
}
