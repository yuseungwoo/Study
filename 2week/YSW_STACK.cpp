// http://gyugyu.tistory.com/67# 참고하여 공부하였습니다. 

// STACK
#include <iostream>
using namespace std;
 
#define MAX 10 // 최대 항목 수를 매크로 상수로 정의
 
class Stack
{
private:
    double item[MAX];   //자료를 저장할 배열 선언
    int top;            //스택 포인터로, 삽입 삭제의 기준 위치.
public:
    Stack();
    ~Stack();
 
    bool Push(double data); //항목을 기억공간에 저장하기 위한 함수.
    bool Pop(double &data); //저장된 항목을 꺼내기 위한 함수.   
};
 
Stack::Stack()
{
    top = -1;   //배열이 0부터 시작되니까. 배열에 아무것도 없는 상태이므로 -1로 초기화함.
}
Stack::~Stack()
{}
 
bool Stack::Push(double data)
{
    if (top == MAX - 1) //스택에 꽉 찼습니다.
    {
        //넣을 공간이 없습니다.
        return false;
    }
    else
    {
        top++;
        item[top] = data;   //스택에 넣습니다.
        return true;
    }
}
 
bool Stack::Pop(double &data)
{
    if (top < 0)
    {
        //아무것도 없어요.
        return false;
    }
    else
    {
        data = item[top];
        top--;
        return true;
    }
}
 
void main()
{
    Stack stack;
    double data;
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
 
    while (stack.Pop(data))
    {
        cout << data << ", "<< endl;
    }
}


출처: http://gyugyu.tistory.com/67# [GYU's DEV STORY]
