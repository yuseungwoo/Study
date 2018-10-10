#include <iostream>
#define BUF_LEN 8
using namespace std;

int POW(int n){
    
    int temp=1;
    
    for(int i=0; i<n;i++) temp=temp*2;
    
    return temp;
}

int swap(int &d1,int &d2){
    if (d1 > d2){
        int temp=d1;
        d1=d2;
        d2=temp;
        
        return 1;
    }
    else{
        return 0;
    }
}

class Nsort{
    
public:
    int buf[BUF_LEN]={4,1,3,2,8,5,7,6};
    int sorted_buf[BUF_LEN]={4,1,3,2,8,5,7,6};
    int sorted_p=0;
    
    void bubble_sort(){
        
        int swap_check=0,swap_buf[BUF_LEN-1]={1};
        int i=0;
        
        while(1){
        
            if( i >= BUF_LEN-1){
                swap_check=0;
                for(int j=0; j<BUF_LEN-1;j++){
                    swap_check=swap_check+swap_buf[j];
                }
                
                if(swap_check==0) {
                    break;
                }
                else{
                    i=0;
                    swap_check=0;
                    for(int j=0; j<BUF_LEN-1;j++){
                        swap_buf[i]=1;
                    }
                }
                ;
            }
            
            swap_buf[i]=swap(sorted_buf[i],sorted_buf[i+1]);
            sorted_show();
            i++;
        }
        
    }
    
    void merge_sort(){
        
        int mid_idx;
        
        if(BUF_LEN%2==0){
            mid_idx=BUF_LEN/2;
        }
        else{
            mid_idx=(BUF_LEN-1)/2;
        }
        int cont_var=0,idx1_ch=0,idx2_ch=0,comp1_idx=0,comp2_idx=0;
        while(1){
            
            if (POW(cont_var) > BUF_LEN) {
                break;
            }
            
            for (int i=0; i<=mid_idx; i++){
                //배열 분할
                comp1_idx=i*POW(cont_var+1);
                comp2_idx=comp1_idx+POW(cont_var);
                
                if (comp1_idx >= BUF_LEN || comp2_idx >= BUF_LEN) {
                    idx1_ch=comp1_idx;
                    idx2_ch=comp2_idx;
                    comp1_idx=0;
                    comp2_idx=0;
                    sorted_p=0;
                    break;
                }
                
                //병합
                MERGE(comp1_idx,comp2_idx);
                
                //
            }
            cont_var++;
        }
        
    }
    
    void show(){
        for(int i=0; i<BUF_LEN; i++) cout << buf[i] <<" ";
        cout << endl;
    }
    void sorted_show(){
        for(int i=0; i<BUF_LEN; i++) cout << sorted_buf[i] <<" ";
        cout << endl;
    }
    
    void MERGE(int idx1, int idx2){
        
        int buf_len=(idx2-idx1);
        int *idx1_buf=new int[buf_len];
        int *idx2_buf=new int[buf_len];
        
        
        for (int i_1=0; i_1<idx2-idx1;i_1++){
            idx1_buf[i_1]=sorted_buf[i_1+idx1];
        }
        for (int i_2=0; i_2<buf_len;i_2++){
            idx2_buf[i_2]=sorted_buf[i_2+idx2];
        }
        
        int i=0,j=0;
        
        while(i < buf_len || j < buf_len ){
            
            if(idx1_buf[i] > idx2_buf[j]){
                sorted_buf[sorted_p]=idx2_buf[j];
                j++;
                sorted_p++;
                if(j==buf_len || buf_len==1){
                    for(int k=i; k<buf_len; k++){
                        sorted_buf[sorted_p++]=idx1_buf[k];
                    }
                    sorted_show();
                    break;
                }
                sorted_show();
            }
            else{
                sorted_buf[sorted_p]=idx1_buf[i];
                i++;
                sorted_p++;
                if(i==buf_len || buf_len==1){
                    for(int k=j; k<buf_len; k++){
                        sorted_buf[sorted_p++]=idx2_buf[k];
                    }
                    sorted_show();
                    break;
                }
                sorted_show();
            }
            
        }
        
        delete [] idx1_buf;
        delete [] idx2_buf;
    }
    //idx1 The former, idx2 The latter
    
};

int main(){
    
    Nsort buf;
    
    buf.show();
    //buf.merge_sort();
    buf.bubble_sort();
    //buf.sorted_show();
    
    return 0;
}

