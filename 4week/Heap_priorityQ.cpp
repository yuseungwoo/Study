#include <iostream>
#define HEAP_MAX 8

using namespace std;

int N_swap(int &d1,int &d2){
	if (d1 < d2){
		int temp=d1;
		d1=d2;
		d2=temp;

		return 1;
	}
	else{
		return 0;
	}
}

class Heap{
public:
	
	int cur_point=1;
	int buf[HEAP_MAX]={0};

	int N_insert(int _data){
		if(_data > 0){
			buf[cur_point]=_data;	
			cur_point++;
			return 1;
		}
		else {
			cout << "비정상적인값 >> "<< _data<< endl; 
			return -1;
		}
	}

	void heap_sort(){

		int root=1;
		int left=0,right=0;
 		int swap_buf[HEAP_MAX],swap_check=0,swap_check_left=1,swap_check_right=1;
		swap_buf[0]=0;

		while(1){
			
			if((left + 1 >= HEAP_MAX ) || (right+1 >=HEAP_MAX)){
					
				for(int i=1; i<=(root-1);i++){
					swap_check=swap_check+swap_buf[i]; 
				}

				if(swap_check==0) break;
				else{ 
					root=1;
					swap_check=0;
				}
					
			}
			left=2*root;
			right=2*root+1;
			
			swap_check_left=N_swap(buf[root],buf[left]);
			swap_check_right=N_swap(buf[root],buf[right]);
			swap_buf[root]=(swap_check_left || swap_check_right);

			cout << root<<" >> "<< "("<<left<<","<<right <<") "<<swap_buf[root] <<endl;

			root++;
		}	
	}

	int POP(){
		
		int root;

		if(cur_point==1){
			cout << "heap이 비었습니다" <<endl;
			return -1;
		}
		else if(cur_point>1){
			 
			root=buf[1];
			
			for(int i=1; i<(HEAP_MAX-1); i++){

				buf[i]=buf[i+1];
	
			}
			
			buf[HEAP_MAX-1]=0;
			cur_point--;	
			return root;
		}
		else{}

	}
	
	int heap_check(){
	    int check_value=(HEAP_MAX - cur_point);	
	    if (check_value > 0){
		cout << "usage "<< cur_point <<" stauts P" << endl;
		return 1;
	    }
	    else{
		cout << "usage " << cur_point << " status N" << endl;
	        return -1;
	    }
	}
	
	void N_print(){
		for(int i=1; i<HEAP_MAX; i++){
			cout << buf[i] << " ";			
		}
		cout << endl;
	}

};

int main(){
/*
	int tmp1=2,tmp2=1;

	cout << tmp1 << "," << tmp2 << endl;
	cout << N_swap(tmp1,tmp2) << endl;
	cout << tmp1 << "," << tmp2 << endl;
*/	
       
	Heap list;
	
	list.N_insert(4);
	list.N_insert(2);
	list.N_insert(6);
	list.N_insert(1);
	list.N_print();
	list.heap_check();
	
	list.N_insert(3);
	list.N_insert(5);
	list.N_insert(7);
	list.N_print();
	list.heap_check();

	list.heap_sort();
	list.N_print();
	
	cout << "POP data >> "<< list.POP() << endl;

	list.heap_sort();		
	list.N_print();

	cout << "ysw" << endl;
	return 0;
}
