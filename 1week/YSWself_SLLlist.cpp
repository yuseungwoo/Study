#include <iostream>

using namespace std;

class Node{
	
public:

	int data;
	Node *next; 
	
};

class SLL{
	
public:	
	
	Node *head;
		
		SLL(){
			head = NULL;
		}
		
		void N_insert(int _data){
			
			//gen-Node
			Node *newNode= new Node();
			newNode->data = _data;
			newNode->next = NULL;

			if(head==NULL){
					
					head=newNode;
			}
			else if(head->next==NULL){

					head->next=newNode;		
			}
			else{

					Node *pNode=head;
					while(pNode->next != NULL){
							pNode=pNode->next;
					}							
					pNode->next=newNode;				
			}
		} 
		
		void N_delete(int _data){
			
			Node *pNode=head;
			Node *prevNode=pNode;
			
			if (pNode==NULL) cout << "Node가 비어있습니다." << endl; 
			else{
				
				if(pNode -> data == _data){

							head=pNode->next;
							delete pNode;			
				}
				else{
					while(pNode->data!=_data){
						prevNode=pNode;
						pNode=pNode->next;
					}
					prevNode->next=pNode->next;
					delete pNode;
				}
			
			}
		}
		
		void N_print(){
			
			Node *pNode=head;
			//cout << head -> data <<endl;
			while(pNode!=NULL){
				
					cout << pNode->data <<endl;
					pNode = pNode->next;
			}
			
		}
	
};

int main(){
	
	//cout << "hi" << endl;
 	
	SLL list;
	list.N_insert(1);
	list.N_insert(2);
	list.N_insert(3);
	list.N_print();
	list.N_delete(1);
	list.N_delete(2);
	list.N_delete(3);
	list.N_delete(4);
	list.N_print();
	 
	return 0;
}
