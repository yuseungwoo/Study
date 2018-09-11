//http://gyugyu.tistory.com/67# 을 참고하여 공부하였습니다. 

#include <iostream>
using namespace std;
 
#define MAX 10
class Queue
{
private:
    int queue[MAX];
    int front;
    int rear;
public :
    Queue();
    ~Queue();
 
    bool Put(int);  //항목을 기억공간에 저장할 함수.
    bool Get(int &); //저장된 항목을 꺼내기 위한 함수.
};
 
Queue::Queue()
{
    front = 0;
    rear = 0;
}
Queue::~Queue(){}
 
bool Queue::Put(int _d)
{
    if ((rear + 1) % MAX == front)
    {
        return false;
    }
 
    queue[rear] = _d;
    rear = ++rear % MAX;
    return true;
}
 
bool Queue::Get(int &_d)
{
    if (front == rear)
    {
        return false;
    }
     
    _d = queue[front];
    front = ++front % MAX;
    return true;
 
}
 
void main()
{
    Queue q;
 
    for (int i = 0; i < 11; i++)
    {
        q.Put(i+1);
    }
 
    int d;
    while (q.Get(d))
    {
        cout << d << "," << endl;
    }
}


출처: http://gyugyu.tistory.com/67# [GYU's DEV STORY]
