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
		   	
		   cout << node->data << " ";  
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
	
	
	int N_delete(int _data){
		
		Node *ptree=root;
		Node *prev=NULL;
		int prev_stat=-1;
		
		if(ptree==NULL){
			cout << "트리가 비었습니다" << endl;
			return 1;
		}
		else if(ptree != NULL){
			
			while(ptree!=NULL){
			
				if(_data < ptree->data){ //작을때
					prev=ptree;
					ptree=ptree->left;
					prev_stat=0;
				}
				else if(_data > ptree->data){ //클때
					prev=ptree;
					ptree=ptree->right;
					prev_stat=1;
				}
				else if(_data == ptree->data){ //같을때 
					cout << endl;
					cout << "data >> "<< _data << " 삭제중" << endl;
					
					if(ptree->left==NULL && ptree->right==NULL){
						delete ptree;
						ptree=NULL;
						if(prev_stat==0) prev->left=NULL;
						else if(prev_stat==1) prev->right=NULL;
						
					}
					else if(ptree->left!=NULL && ptree->right==NULL){
						if(prev_stat==0){
							prev->left=ptree->left;
							delete ptree;
							ptree=NULL;
						}
						else if(prev_stat==1)
						{
							prev->right=ptree->left;
							delete ptree;
							ptree=NULL;
						} 	
					}
					else if(ptree->left==NULL && ptree->right!=NULL){
						if(prev_stat==0){
							prev->left=ptree->right;
							delete ptree;
							ptree=NULL;
						}
						else if(prev_stat==1)
						{
							prev->right=ptree->right;
							delete ptree;
							ptree=NULL;
						} 	
					}
					else if(ptree->left!=NULL && ptree->right!=NULL){
						Node *sub_ptree=ptree->right;
						Node *sub_prev=ptree;
						
						if(sub_ptree->left==NULL){
							ptree->data=sub_ptree->data;
							ptree->right=NULL;
							delete sub_ptree;
						}
						else{
							while(sub_ptree->left!=NULL){ 
									sub_prev=sub_ptree;
									sub_ptree=sub_ptree->left;
							}
							ptree->data=sub_ptree->data;
							sub_prev->left=NULL;
							delete sub_ptree;
						}
					}	
				}
				else{
					cout << "data >> "<< _data << " 발견하지 못했습니다" << endl;
					break;
				}
				
			}
			
			return 1;
		}
		else{
			
			cout << "delete 알 수 없는 오류가 발생" << endl;
			return -1;
		}
	}
	
	
};


int main(){
	
	BST buf;
	
	buf.N_insert(4);
	buf.N_insert(2);
	buf.N_insert(1);
	buf.N_insert(3);
	buf.N_insert(6);
	buf.N_insert(5);
	buf.N_insert(7);

	buf.inorderPrint(); 
	buf.N_delete(4);
        buf.N_delete(3);
	buf.inorderPrint();
	return 0;
}
