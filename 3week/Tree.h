#pragma once
#include <iostream>

using namespace std;

template<typename T>
class CTree
{
public:
	enum Direction{ LEFT, RIGHT };
	CTree() : root(NULL) { }
	class CTreeNode
	{
	public:
		CTreeNode() : pLeft(NULL), pRight(NULL) { }
		T Data;
		CTreeNode *pLeft;
		CTreeNode *pRight;
	};
	struct SearchInfo
	{
		SearchInfo() : pParent(NULL), pNode(NULL) { }
		CTreeNode* pParent;
		CTreeNode* pNode;
		Direction dir;
	};
private:
	CTreeNode *root;

public:
	CTreeNode* InsertRecursion(CTreeNode *node, T data)
	{
		CTreeNode *pTemp = node;
		
		if(node == NULL)	
		{
			CTreeNode *NewNode = new CTreeNode();
			NewNode->Data = data;
			cout<<"Inserted Item: " << data <<endl;
			return NewNode;
		}
		else
		{
			if(node->Data < data)	
			{
				pTemp->pRight = InsertRecursion(pTemp->pRight, data);
				return pTemp;
			}
			else if(node->Data > data)
			{
				pTemp->pLeft = InsertRecursion(pTemp->pLeft, data);
				return pTemp;
			}
			else
			{
				cout<< data <<" exists already"<<endl;
				return pTemp;
			}
		}
	}

	void InsertNode(T data)
	{
		root = InsertRecursion(root, data);
	}

	SearchInfo SearchNode(T data)
	{
		CTreeNode *pTemp = root;
		SearchInfo info;

		while(pTemp != NULL)
		{
			if(pTemp->Data < data) 
			{
				info.pParent = pTemp;
				info.dir = RIGHT;
				info.pNode = pTemp->pRight;
				pTemp = pTemp->pRight;
			}
			else if(pTemp->Data > data)
			{
				info.pParent = pTemp;
				info.dir = LEFT;
				info.pNode = pTemp->pLeft;
				pTemp = pTemp->pLeft;
			}
			else
				return info;
		}
		return info;
	}


	T DeleteNode(T data)
	{
		SearchInfo Info = SearchNode(data);
		CTreeNode *pParentNode = Info.pParent;
		CTreeNode *pNode = Info.pNode;
		T Data = pNode->Data;
		Direction dir = Info.dir;

		if(Info.pNode == NULL)
		{
			cout<< "The data doesn't exist" <<endl;
			return NULL;
		}

		if(pNode->pLeft == NULL && pNode->pRight == NULL)
		{
			dir == LEFT ? pParentNode->pLeft = NULL : pParentNode->pRight = NULL;
			delete pNode;
		}
		else if(pNode->pLeft == NULL || pNode->pRight == NULL)
		{
			if(pNode->pLeft == NULL)
				if(dir == LEFT)
					pParentNode->pLeft = pNode->pRight;
				else
					pParentNode->pRight = pNode->pRight;
			else	
				if(dir == LEFT)
					pParentNode->pLeft = pNode->pLeft;
				else
					pParentNode->pRight = pNode->pLeft;

			delete pNode;
		}
		else
		{
			CTreeNode *Max = MaxNode(pNode->pLeft);
			if(Max == NULL) Max = pNode->pLeft;
			pNode->Data = DeleteNode(Max->Data);
		}
		return Data;
	}

	CTreeNode* MaxNode(CTreeNode *node)
	{
		CTreeNode *pTemp = node;
		CTreeNode *pParent = NULL;
		while(pTemp != NULL)
		{
			pParent = pTemp;
			pTemp = pTemp->pRight;
		}
		cout<<"Max Node Data: " << pParent->Data << endl;
		return pParent;
	}

	void Inorder(CTreeNode *node)
	{
		if(node != NULL)
		{
			Inorder(node->pLeft);
			cout<<"print: " << node->Data<<endl;
			Inorder(node->pRight);
		}
	}

	void printNode(){	Inorder(root);	}
};

