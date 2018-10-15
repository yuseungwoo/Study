#pragma once
#include "LinkedList.h"

#define TABLE_SIZE 10
#define HASH_KEY(key)	key%TABLE_SIZE

using namespace std;

class CHash
{
public:
	class CNode
	{
	public:
		CNode() : pLink(NULL) {}
		int nData;
		CNode *pLink;
	};
public:
	CNode *pTable[TABLE_SIZE];

	CHash()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
			pTable[i] = NULL;
	}
	~CHash()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if(pTable[i] != NULL)	delete pTable[i];
		}
	}

public:
	void AddHashData(int data)
	{
		int nKey = HASH_KEY(data);
		if (pTable[nKey] == NULL)
		{
			pTable[nKey] = new CNode();
			pTable[nKey]->nData = data;
		}
		else
		{
			CNode *pNode = new CNode();
			CNode *pPre = pTable[nKey];
			CNode *pTemp = pTable[nKey]->pLink;
			while (pTemp != NULL)
			{
				pPre = pTemp;
				pTemp = pTemp->pLink;
			}
				
			pPre->pLink = pNode;
			pNode->nData = data;
		}

		cout << "Added data: " << data << endl;
	}

	void DeleteHashData(int data)
	{
		int nKey = HASH_KEY(data);

		if (pTable[nKey] == NULL)
		{
			cout << data << "doesn't exist" << endl;
			return;
		}

		CNode *pTemp = NULL;
		if (pTable[nKey]->nData == data)
		{
			pTemp = pTable[nKey]->pLink;
			delete pTable[nKey];
			pTable[nKey] = pTemp;
		}
		else
		{
			pTemp = pTable[nKey]->pLink;
			while (pTemp != NULL)
			{
				if (pTemp->nData == data)
				{
					pTemp = pTable[nKey]->pLink;
					delete pTable[nKey];
					pTable[nKey] = pTemp;
					break;
				}
				else	pTemp = pTemp->pLink;
			}
			if(pTemp == NULL)
				cout << data << "doesn't exist" << endl;
		}
	}

	CNode* SearchHashData(int data)
	{
		int nKey = HASH_KEY(data);

		if (pTable[nKey] == NULL)
		{
			cout << data << "doesn't exist" << endl;
			return NULL;
		}

		CNode *pTemp = NULL;
		if (pTable[nKey]->nData == data)
		{
			return pTable[nKey];
		}
		else
		{
			pTemp = pTable[nKey]->pLink;
			while (pTemp != NULL)
			{
				if (pTemp->nData == data)
					return pTable[nKey];
				else	
					pTemp = pTemp->pLink;
			}

			cout << data << "doesn't exist" << endl;
		}
	}

	void PrintAllHashData()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			cout << "key: " << i << endl;
			if (pTable[i] != NULL)
			{
				cout << pTable[i]->nData << " ";
				CNode *pTemp = pTable[i]->pLink;
				while (pTemp != NULL)
				{
					cout << pTemp->nData << " ";
					pTemp = pTemp->pLink;
				}
				cout << endl;
			}
		}
	}

};