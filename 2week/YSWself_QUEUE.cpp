#include <iostream>

using namespace std;

class Node{
	
	public: 	
		int data;
		Node *next=NULL;
	
};

class QUEUE{
	
	 public:
	 	Node *front; //for dequeue 
		Node *rear;  //for enqueue
	
		QUEUE(){
			front=NULL;
			rear=NULL;
		}	
		
	 void N_enq(int _data){
	 	
			Node *newNode = new Node();
			newNode -> data = _data;
			
			if(front==NULL && rear==NULL) front=rear=newNode;
		 	else if(front==rear){
				rear=newNode;
				front->next=rear; 	
			}
			else{
					Node *pNode=front;
			
			 		while(pNode!=rear) pNode=pNode->next;
					 
					rear=newNode; 
					pNode->next=rear;
									  
			 }
	 }	
	 int N_deq(){
	 	
		   if(front==NULL && rear==NULL){
		   		cout << "QUEUE가 비었습니다." << endl; 		  			return -1; 
			}	
		   else if(front==rear){
		   	
			   Node *pNode=front;
			   
			   front=NULL;
			   rear=NULL;
			   
			   return pNode -> data;
			   delete pNode;
			   
		   }
		   else{
		   	
			   Node *pNode=front;
			   
			   front = pNode->next;
			   
			   return pNode -> data;
			   delete pNode;
			   
		   }
	 }	
};

int main(){
	
	QUEUE buf;
	
	buf.N_enq(1);
	buf.N_enq(2);
	buf.N_enq(3);
	
	cout << buf.N_deq() << endl;
	cout << buf.N_deq() << endl;
	cout << buf.N_deq() << endl;
	cout << buf.N_deq() << endl;
	
	return 0;
}
