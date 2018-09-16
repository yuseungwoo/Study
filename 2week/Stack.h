#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CStack
{
public:
	CStack() : Top(NULL) { };
	class CStackNode
	{
	public:
		CStackNode() : link(NULL) { }
		T Data;
		CStackNode *link;
	};

	CStackNode *Top;

	
	bool IsEmpty()
	{
		return Top == NULL;
	}
	void Push(T data)
	{
		CStackNode *NewNode = new CStackNode;
		NewNode->Data = data;
		NewNode->link = Top;
		Top = NewNode;
		cout<< "Inserted Item: " << NewNode->Data<<endl;
	}

	T Pop()
	{
		if(IsEmpty())	return 0;

		T data = Top->Data;
		CStackNode *temp = Top->link;
		delete Top;
		Top = temp;

		return data;
	}

	void Delete()
	{
		if(IsEmpty())	return;

		CStackNode *temp = Top->link;
		delete Top;
		Top = temp;
	}

	T peek()
	{
		if(IsEmpty())	return 0;

		return Top->Data;
	}
};

