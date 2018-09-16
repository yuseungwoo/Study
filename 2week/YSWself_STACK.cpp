#include <iostream>

using namespace std;

class Node{
	
	public:	
		int data;
		Node *next; 
	
};

class STACK{
	
	public:
		Node *top;
		Node *bottom;
	
	STACK(){
		top=NULL;
		bottom=NULL;
	}		
	
	void N_PUSH(int _data){
		
		Node *newNode= new Node();
		newNode->data=_data;
		newNode->next=NULL;
		
		if(bottom==NULL) bottom=top=newNode;  
		else if(bottom->next==NULL){
				top=newNode;
				bottom->next	= top;	
		}
		else{
			
			Node *pNode=bottom;
		
				while(pNode != top) pNode=pNode -> next;
				
				pNode->next=newNode;
				top=pNode->next;
		}	
	}
	int N_POP(){
		
		Node *pNode=bottom;
		Node *prevNode=pNode;
		
		if(top==NULL && bottom == NULL){
			cout << "stack이 비었습니다" << endl;
			return -1;
		}
		else if(top == bottom){
			pNode=bottom;
			bottom=NULL;
			top=NULL;
			return pNode -> data;
			delete pNode;
		}	
		else{
				while(pNode -> next != top) {
					pNode=pNode -> next;
				}
			
			top=pNode;
			pNode=pNode->next;
			return pNode->data;
			delete pNode;
		}
	} //Defined by STACK ADT
	//void N_print() Defined by STACK ADT
	
};


int main(){
	
	STACK list;
	
	list.N_PUSH(1);
	list.N_PUSH(2);
	list.N_PUSH(3);
	
	cout << list.N_POP() << endl;
	cout << list.N_POP() << endl;
	cout << list.N_POP() << endl;
	cout << list.N_POP() << endl;
	
}
