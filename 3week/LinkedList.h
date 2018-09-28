#pragma once
#include <iostream>

using namespace std;

template<typename T> 
class CLinkedList
{
public:
	CLinkedList() : pHead(NULL) { }
public:
	class CNode
	{
	public:
		CNode() : pLink(NULL) { } 
		T Data;
		CNode *pLink;
	};

public:
	CNode *pHead;

	void InsertNode(T data)
	{
		CNode *NewNode = new CNode;
		CNode *pTemp = NULL;

		if(pHead == NULL)	pHead = NewNode;
		else
		{
			pTemp = pHead;
			while(1)
			{
				if(pTemp->pLink != NULL)	pTemp = pTemp->pLink;
				else	break;
			}
			pTemp->pLink = NewNode;
		}
		NewNode->Data = data;
		cout << "Inserted data: " << data << endl;
	}

	void DeleteNode(T data)
	{
		if(IsEmpty()) 
		{
			cout << "No Node" << endl;
			return;
		}

		CNode *pTemp = pHead;
		CNode *pPreTemp = NULL;

		do
		{
			if(pTemp->Data != data)
			{
				pPreTemp = pTemp;
				pTemp = pTemp->pLink;
			}
			else	
			{
				if(pPreTemp == NULL)	pHead = pTemp->pLink;
				else	pPreTemp->pLink = pTemp->pLink;

				delete pTemp;
				cout << "Deleted data: " << data << endl;
				return;
			}

		}while(pTemp != NULL);

		cout << data << " doesn't exist" << endl;

	}

	void PrintAll()
	{
		if(IsEmpty()) 
		{
			cout << "No Node" << endl;
			return;
		}

		CNode *pTemp = pHead;

		do
		{
			cout << "PrintData: " << pTemp->Data << endl;
			pTemp = pTemp->pLink;
		}while(pTemp != NULL);
	}
	bool IsEmpty()
	{
		return pHead == NULL;
	}
};

