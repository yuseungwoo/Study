#include <iostream>
#define null 0
 
using namespace std;
 
template <typename T>
class Tree;
 
template <typename T>
class TreeNode {
    friend class Tree<T>;
private:
    T data;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(T data = 0, TreeNode* left = null, TreeNode* right = null) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
 
template <typename T>
class Tree {
private:
    TreeNode<T>* root;
public:
    Tree(T data = 0) {
        root = new TreeNode<T>(data);
    }
    // Tree 만들기
    /*
                 4
             2       5
           1   3   6   7   
                     
    */
    void buildTree() {
        root->left = new TreeNode<T>(2, new TreeNode<T>(1), new TreeNode<T>(3));
        root->right = new TreeNode<T>(5, new TreeNode<T>(6), new TreeNode<T>(7));
    }
 
    TreeNode<T>* getRoot() {
        return root;
    }
 
    void visit(TreeNode<T>* current) {
        cout << current->data << " ";
    }
 
    // 전위 순회 Current - Left - Right
    void preorder(TreeNode<T>* current) {
        if (current != null) {
            visit(current);
            preorder(current->left);
            preorder(current->right);
        }
    }
 
    // 중위 순회 Left - Current - Right
    void inorder(TreeNode<T>* current) {
        if (current != null) {
            inorder(current->left);
            visit(current);
            inorder(current->right);
        }
    }
 
    // 후위 순회 Left - Right - Current
    void postorder(TreeNode<T>* current) {
        if (current != null) {
            postorder(current->left);
            postorder(current->right);
            visit(current);
        }
    }
};
 
int main() {
    Tree<int> tree(4);
    tree.buildTree();
    cout << "Preorder >> ";
    tree.preorder(tree.getRoot());
    cout << endl;
 
    cout << "Inorder >> ";
    tree.inorder(tree.getRoot());
    cout << endl;
 
    cout << "Postorder >> ";
    tree.postorder(tree.getRoot());
    cout << endl;
}


