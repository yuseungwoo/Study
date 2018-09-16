#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CQueue
{
public:
	CQueue() : front(NULL), rear(NULL) { }
	class CQueueNode
	{
	public:
		CQueueNode() : link(NULL) { }
		T Data;
		CQueueNode *link;
	};

	CQueueNode *front;
	CQueueNode *rear;

	
	bool IsEmpty()
	{
		return front == NULL;
	}
	void EnQueue(T data)
	{
		CQueueNode *NewNode = new CQueueNode;
		NewNode->Data = data;
		if(IsEmpty())
		{
			front = NewNode;
			rear = NewNode;
		}
		else
		{
			rear->link = NewNode;
			rear = NewNode;
		}
		cout<<"Inserted Item: " <<data<<endl;
	}

	T DeQueue()
	{
		if(IsEmpty())	return 0;

		T data = front->Data;
		CQueueNode *temp = front->link;
		delete front;
		front = temp;
		if(front == NULL) rear = NULL;

		return data;
	}

	void Delete()
	{
		if(IsEmpty())	return;

		CQueueNode *temp = front->link;
		delete front;
		front = temp;
		if(front == NULL)	rear = NULL;
	}

	T peek()
	{
		if(IsEmpty())	return 0;

		return front->Data;
	}
};

