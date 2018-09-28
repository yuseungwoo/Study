#include <iostream>

using namespace std;

class Node{
	
public:
	
	int data;
	Node *left;
	Node *right;
	
	Node(int _data){
		data=_data;
		left=NULL;
		right=NULL;	
	}
	
};

class BST{
	
public:	
	
	Node *root=NULL;
	
	int N_insert(int _data){
		
		Node *newNode = new Node(_data);
		
		if(root==NULL){
			
			root=newNode;
			return 1;
		}		
		else if(root!=NULL){
	
			Node *ptree=root;
			
			while(ptree!=NULL){
			
				if(newNode->data < ptree->data){ //작을때
					if(ptree->left == NULL) {
						ptree->left=newNode;
						break;
					}
					ptree=ptree->left;
				}
				else if(newNode->data > ptree->data){ //클때
					if(ptree->right == NULL){ 
					   ptree->right=newNode;
						break;
					}
					ptree=ptree->right;
				}
				else{ //같을때 
					cout << "data가 존재합니다" << endl;
					break;
				}
				
			}
			
			return 1;
		}
		else{
			//예외처리.
			cout << "insert 알 수 없는 오류 발생" << endl;
			return -1;
		}
				
	}//insert 끝
	
	void inorderRecursivePrint(Node *node)
	{
  	 	if (node != NULL)
  	 	{
		   	
		   cout << node->data << endl;  
  	  	  	inorderRecursivePrint(node->left); //Left Child가 없을때까지 최대한 왼쪽으로 탐색한다.
  	  	  	//cout << node->data << endl;      //출력한다.   
  	  	  	inorderRecursivePrint(node->right);//그 다음 Right Child를 탐색한다.
  		 }
	}
	
	void inorderPrint()
	{
   	cout << "INORDER" << endl;
   	inorderRecursivePrint(root);
	}
	
	
	
	/*
	int N_delete(int _data){
		
		Node *ptree=root;
		
		if(ptree==NULL){
			cout << "트리가 비었습니다" << endl;
			return 1;
		}
		else if(ptree != NULL){
			
			while(ptree->data != _data){
				if( _data < ptree->data ){ //작을때
					
					ptree=ptree->left;
				}
				else if( _data > ptree->data ){ //클때
					
					ptree=ptree->right;
				}
				else if( _data = ptree->data ) //같을때 
					cout << "data 삭제 중 >> "<< _data << endl; 					if(ptree->left==NULL && ptree->right==NULL){
						delete ptree;
					}
					else if(ptree->left!=NULL && ptree->right==NULL){
						ptree-
					}
					else if(ptree->left==NULL && ptree->right!=NULL){
						
					}
					else if(ptree->left!=NULL && ptree->right=!=NULL){}
				}
				
			}
			return 1;
		}
		else{
			
			cout << "delete 알 수 없는 오류가 발생" << endl;
			return -1;
		}
	}
	*/
	
};


int main(){
	
	BST buf;
	
	cout << buf.N_insert(4) << endl;
	cout << buf.N_insert(2) << endl;
	cout << buf.N_insert(1) << endl;
	cout << buf.N_insert(3) << endl;
	cout << buf.N_insert(6) << endl;
	cout << buf.N_insert(5) << endl;
	cout << buf.N_insert(7) << endl;
	
	buf.inorderPrint(); 
	return 0;
}
