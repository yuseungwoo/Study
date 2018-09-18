import java.util.ArrayList;

public class Tree {
	node root = null;

	class node {
		int element;
		node left = null;
		node right = null;

		node(int element) {
			this.element = element;
		}
	}

	void add_node(int element) {
		node new_node = new node(element);
		node new_node_adr = this.root;

		if (this.root == null) {
			this.root = new_node;
			return;
		}

		while (new_node_adr != null) {

			if (new_node_adr.element > element) {

				if (new_node_adr.left == null)
					new_node_adr.left = new_node;

				new_node_adr = new_node_adr.left;
			}

			else if (new_node_adr.element < element) {

				if (new_node_adr.right == null)
					new_node_adr.right = new_node;

				new_node_adr = new_node_adr.right;
			}

			else
				return;
		}

	}

	void delete_node(int element) {
		node del_node = this.root;
		node del_top_node = this.root;

		while (del_node != null) {

			if (del_node.element > element) {
				del_top_node = del_node;
				del_node = del_node.left;

			}

			else if (del_node.element < element) {
				del_top_node = del_node;
				del_node = del_node.right;
			}

			else {

				if (del_node.left == null) {

					if (del_top_node.left == del_node)
						del_top_node.left = del_node.right;
					else if (del_top_node.right == del_node)
						del_top_node.right = del_node.right;
					break;
				}

				else {

					node find_smaller_node = del_node.left;
					while (find_smaller_node.right != null) {
						find_smaller_node = find_smaller_node.right;
					}

					find_smaller_node.right = del_node.right;

					if (del_top_node.left == del_node)
						del_top_node.left = del_node.left;
					else if (del_top_node.right == del_node)
						del_top_node.right = del_node.left;
					break;
				}
			}
		}
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
					System.out.print("аб" + node_arr.get(0).left.element);
					node_arr.add(node_arr.get(0).left);
					list_index++;
				} else
					System.out.print(" ");

				System.out.print("   ");

				if (node_arr.get(0).right != null) {
					System.out.print("©Л" + node_arr.get(0).right.element);
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

	public static void main(String[] args) {
		Tree tree = new Tree();
		tree.add_node(10);

		tree.add_node(101);
		tree.add_node(99);
		tree.add_node(102);
		tree.add_node(3);
		tree.add_node(2);
		tree.add_node(1);
		tree.add_node(5);
		tree.add_node(4);
		tree.delete_node(5);
		tree.print_tree();
	}
}
