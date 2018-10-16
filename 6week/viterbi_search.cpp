//
//  main.cpp
//  search_shortest_way
//
//  Created by ktmac on 16/10/2018.
//  Copyright © 2018 ktmac. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#define N_way 5
#define N_inf 10000

using namespace std;

class S_way{
    
    public :
    int path_weight[N_way][N_way];
    int place_buf[N_way]={0};
    int pStep,pStart,pEnd,pCur;
    
    S_way(){
       
        pStep=0;
        pStart=0;
        pEnd=0;
        pCur=0;
        
        srand((unsigned int)time(NULL));
        for(int i=0; i<N_way; i++){
            for(int j=0; j<N_way; j++){
                if( (i==0 && j==2) || (i==2 && j==0) || (i==1 && j==3) || (i==3 && j==1) || (i==j)){
                    path_weight[i][j]=N_inf;
                    continue;
                }
                path_weight[i][j]=rand()%20+1;
            }
        }
    }
    
    
    
    void _search(int _pStart,int _pEnd){
        pStep=0;
        pCur=_pStart;
        pEnd=_pEnd;
        int min_temp=N_inf;
        int min_idx=-1;
       
        while(1){
  
            
            if(pCur==pEnd){
                break;
            }
            
            for(int i=0; i<N_way;i++){  // forward

                if(path_weight[pCur][i]==N_inf) continue;
                else if( pCur==pStart && i==pEnd && path_weight[pCur][i]!=N_inf) {
                    min_temp=path_weight[pCur][i];
                }
                else{
                    cout << path_weight[pCur][i]  << " ";
                    if(min_temp > path_weight[pCur][i]){
                        min_temp = path_weight[pCur][i];
                        min_idx = i;
                    }
                    // cout << "pCur : " << pCut ;
                    
                }
            
            }
            min_temp=N_inf;
            pCur=min_idx;
            pStep++;
            
        }
        
        //back_trace
    }
    
    void weight_show(){
        for(int i=0; i<N_way; i++){
            for(int j=0; j<N_way; j++){
                cout << path_weight[i][j] << " ";
            }
            cout << endl;
        }
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //cout << "Hello, World!\n";
    S_way t;
    t._search(0,1);
    
    //t.weight_show();
    
    return 0;
}
