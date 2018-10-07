#pragma once
#include <iostream>
using namespace std;

template<typename T>
class CSort
{
public:
	CSort() { };
	~CSort() { };
public:
	//선택 정렬
	void SelectionSort(T *arr, int length)
	{
		int nMin = *arr;
		T Temp;
		int nPos = -1;

		for (int i = 1; i < length; i++)
		{
			if (nMin > arr[i])
			{
				nMin = arr[i];
				nPos = i;
			}
		}
		if (nPos != -1)
		{
			Temp = arr[nPos];
			arr[nPos] = *arr;
			*arr = nMin;
		}
		if (length > 1)	SelectionSort(arr + 1, length - 1);
	}

	//버블 정렬
	void BubbleSort(T *arr, int length)
	{
		T Temp;
		for (int i = 0; i<length - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				Temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = Temp;
			}
		}

		if (length>1)	SelectionSort(arr, length - 1);
	}

	//퀵 정렬
	void QuickSort(T *arr, int length)
	{
		int nPivot = length / 2;
		int nStart = 0;
		int nEnd = length - 1;
		T Temp;

		while (1)
		{
			if (arr[nStart] >= arr[nPivot])	break;
			else	nStart++;
		}

		while (1)
		{
			if (arr[nEnd] < arr[nPivot] || nStart == nEnd)	break;
			else	nEnd--;
		}

		if (nStart == nEnd)
		{
			Temp = arr[nPivot];
			arr[nPivot] = arr[nStart];
			arr[nStart] = Temp;

			if (nStart > 1)
			{
				QuickSort(arr, nStart);
			}
			if (length - nStart > 2)
			{
				QuickSort(arr + (nStart + 1), length - nStart - 1);
			}
		}
		else
		{
			Temp = arr[nStart];
			arr[nStart] = arr[nEnd];
			arr[nEnd] = Temp;
			QuickSort(arr, length);
		}
	}

	//삽입 정렬
	void InsertionSort(T *arr, int length, int interval = 1)
	{
		for (int i = 0; i < interval; i++)
		{
			for (int u = i + interval; u < length; u = u + interval)
			{
				for (int s = u - interval; s >= 0; s = s - interval)
				{
					if (arr[u] > arr[s])
					{
						if (s == u - interval) break;
						T Temp = arr[u];
						for (int t = u - 1; t >= s; t--)	arr[t + 1] = arr[t];

						arr[s + 1] = Temp;
						break;
					}
					else
					{
						if (s == 0)
						{
							T Temp = arr[u];
							for (int t = u - 1; t >= s; t--)	arr[t + 1] = arr[t];
							arr[0] = Temp;
						}
					}
				}
			}
		}
	}

	//셸 정렬
	void ShellSort(T *arr, int length)
	{
		int h;
		for (h = length / 2; h > 0; h = h / 2)
			InsertionSort(arr, length, h);
	}
};

//병합 정렬
template<typename T>
class CMergeSort
{
private:
	T *Sorted;
public:
	CMergeSort() 
	{
		Sorted = NULL;
	};
	~CMergeSort()
	{
		if(Sorted != NULL)	delete Sorted;
	};

	void MergeSort(T *arr, int length, int m, int n)
	{
		int nMiddle;
		Sorted = new T[length];

		if (m < n)
		{
			nMiddle = (m + n) / 2;
			MergeSort(arr, length, m, nMiddle);
			MergeSort(arr, length, nMiddle + 1, n);
			Merge(arr, length, m, nMiddle, n);
		}
	}

private:
	void Merge(T *arr, int length, int m, int middle, int n)
	{
		int i, j, k, t;
		i = m;
		j = middle + 1;
		k = m;

		while (i <= middle && j <= n)
		{
			if (arr[i] <= arr[j])	Sorted[k] = arr[i++];
			else Sorted[k] = arr[j++];
			k++;
		}

		if (i > middle)
			for (t = j; t <= n; t++, k++)	Sorted[k] = arr[t];
		else
			for (t = i; t <= middle; t++, k++)	Sorted[k] = arr[t];

		for (t = m; t <= n; t++)	arr[t] = Sorted[t];
	}
};