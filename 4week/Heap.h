#pragma once
#include <iostream>

#define ARRAY_LENGTH	100
using namespace std;

template<typename T>
class CHeap
{
private:
	int nHeapSize;
	T *arrayHeap;
public:
	CHeap()
	{ 
		nHeapSize = 0;
		arrayHeap = new T[ARRAY_LENGTH];	
	}
	~CHeap()
	{
		delete arrayHeap;
	}

	void InsertHeap(T data)
	{
		if(GetHeapSize() == ARRAY_LENGTH)
		{
			cout << "No empty space to insert data" << endl;
			return;
		}

		int i = ++nHeapSize;
		while(i != 1 && data > arrayHeap[i/2])
		{
			arrayHeap[i] = arrayHeap[i/2];
			i = i/2;
		}
		arrayHeap[i] = data;

		cout<< "Inserted Data: " << data <<endl;
	}

	T DeleteHeap()
	{
		if(GetHeapSize() == 0)
		{
			cout << "Nothing to delete" << endl;
			return NULL;
		}

		int nTemp = 1;
		int nChild = nTemp *2;

		T DeletedData = arrayHeap[1];
		arrayHeap[1] = arrayHeap[nHeapSize--];
		T CmpData = arrayHeap[1];
		while(nChild <= nHeapSize)
		{
			if(arrayHeap[nTemp] >= arrayHeap[nChild])
			{
				if(arrayHeap[nTemp] >= arrayHeap[nChild + 1])	break;
				nChild++;
			}
			else
				if(arrayHeap[nChild] < arrayHeap[nChild + 1])	nChild++;
								
			arrayHeap[nTemp] = arrayHeap[nChild];
			arrayHeap[nChild] = CmpData;
			nTemp = nChild;
			nChild = nTemp*2;
		}

		cout<< "Deleted Data: " << DeletedData <<endl;
		return DeletedData;
	}

	int GetHeapSize(){	return nHeapSize;	}

	void PrintHeap()
	{
		if(GetHeapSize() == 0)
		{
			cout << "Nothing to print" << endl;
			return;
		}

		for(int i = 1; i<=nHeapSize;i++)	cout<< "arrayHeap[" << i << "] " << arrayHeap[i]<< " ";

		cout<<endl;
	}
};
