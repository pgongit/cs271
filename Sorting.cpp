#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <iostream>


using namespace std;

const int A_SIZE = 10000;



void WriteDataToArray(string srcFile, int * data, int n)
{
	fstream file;
	char * temp = new char[10];

	file.open(srcFile);

	if (file.is_open() == true)
	{
		int i = 0;
		while (file.peek() != EOF)
		{
			file.getline(temp, 10, ' ');
			if (i < n)
			{
				data[i] = atoi(temp);
			}
			i++;
		}
	}
	file.close();
}
void Copy(int * src, int *dest, int n)
{
	for (int i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}





void BubbleSort(int data[], int n)
{
	int i, j, temp;
	int swaps = 0, comparisons = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				swaps++;
				comparisons++;
			}
		}
	}

	cout << "Number of swaps: " << swaps << endl;
	cout << "Number of comparisons: " << comparisons << endl;
}


void InsertionSort(int data[], int n)
{
	int i, j, element;
	int swaps = 0, comparisons = 0;
	for (i = 1; i < n; i++)
	{
		element = data[i];
		j = i;
		while ((j > 0) && (data[j - 1] > element))
		{
			data[j] = data[j - 1];
			j = j - 1;
		}
		data[j] = element;
		swaps++;
		comparisons++;
	}

	cout << "Number of swaps: " << swaps << endl;
	cout << "Number of comparisons: " << comparisons << endl;
}



void ShellSort(int data[], int n)
{
	int temp, gap, i;
	int swapped;
	int swaps = 0, comparisons = 0;
	gap = n / 2;
	do
	{
		do {
			swapped = 0;
			for (i = 0; i < n - gap; i++)
			{
				if (data[i] > data[i + gap])
				{
					temp = data[i];
					data[i] = data[i + gap];
					data[i + gap] = temp;
					swapped = 1;
					swaps++;
					comparisons++;
				}
			}
		} while (swapped == 1);
	} while ((gap = gap / 2) >= 1);

	cout << "Number of swaps: " << swaps << endl;
	cout << "Number of comparisons: " << comparisons << endl;
}




int QuickSortPartition(int data[], int low, int high)
{
	int pivot, i, j;
	pivot = data[low];
	j = high + 1;
	i = low;

	do
	{
		i++;
		while (data[i] < pivot && low <= high)
		{
			do
			{
				j++;
			} while (pivot < data[j]);

			if (i < j)
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	} while (i < j);
	data[low] = data[j];
	data[j] = pivot;
	return j;
}
void QuickSort(int data[], int low, int high)
{
	int k;
	if (low < high)
	{
		k = QuickSortPartition(data, low, high);
		QuickSort(data, low, k - 1);
		QuickSort(data, k + 1, high);
	}
}



void Merge(int data[], int low, int high, int mid)
{
	int i, j, k, C[A_SIZE];
	i = low;
	j = mid + 1;
	k = 0;
	while ((i <= mid) && (j <= high))
	{
		if (data[i] < data[j])
		{
			C[k] = data[i++];
		}
		else
		{
			C[k] = data[j++];
		}
		k++;
	}
	while (i <= mid)
	{
		C[k++] = data[i++];
	}
	for (i = low, j = 0; i <= high; i++, j++)
	{
		data[i] = C[j];
	}
}
void MergeSort(int data[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(data, low, mid);
		MergeSort(data, mid + 1, high);
		Merge(data, low, high, mid);
	}
}





int main()
{
	int data[A_SIZE];
	int sortData[A_SIZE];
	
	
	WriteDataToArray("DataFewUnique.txt", data, A_SIZE);

	cout << endl;
	cout << "Bubble Sort 'Few Unique' " << endl;
	Copy(data, sortData, A_SIZE);
	BubbleSort(sortData, A_SIZE);

	cout << endl;
	cout << "Insertion Sort 'Few Unique' " << endl;
	Copy(data, sortData, A_SIZE);
	InsertionSort(sortData, A_SIZE);

	cout << endl;
	cout << "Shell Sort 'Few Unique' " << endl;
	Copy(data, sortData, A_SIZE);
	ShellSort(sortData, A_SIZE);


	//Copy(data, sortData, A_SIZE);
	//MergeSort(sortData, 0, A_SIZE-1);

	//Copy(data, sortData, A_SIZE);
	//QuickSort(sortData, 0, A_SIZE - 1);


	
	
	WriteDataToArray("DataNearlySorted.txt", data, A_SIZE);

	cout << endl;
	cout << "Bubble Sort 'NearlySorted' " << endl;
	Copy(data, sortData, A_SIZE);
	BubbleSort(sortData, A_SIZE);

	cout << endl;
	cout << "Insertion Sort 'NearlySorted' " << endl;
	Copy(data, sortData, A_SIZE);
	InsertionSort(sortData, A_SIZE);

	cout << endl;
	cout << "Shell Sort 'NearlySorted' " << endl;
	Copy(data, sortData, A_SIZE);
	ShellSort(sortData, A_SIZE);

	//Copy(data, sortData, A_SIZE);
	//MergeSort(sortData, 0, A_SIZE-1);
	
	//Copy(data, sortData, A_SIZE);
	//QuickSort(sortData, 0, A_SIZE - 1);


	WriteDataToArray("DataRandom.txt", data, A_SIZE);

	cout << endl;
	cout << "Bubble Sort 'Random' " << endl;
	Copy(data, sortData, A_SIZE);
	BubbleSort(sortData, A_SIZE);

	cout << endl;
	cout << "Insertion Sort 'Random' " << endl;
	Copy(data, sortData, A_SIZE);
	InsertionSort(sortData, A_SIZE);

	cout << endl;
	cout << "Shell Sort 'Random' " << endl;
	Copy(data, sortData, A_SIZE);
	ShellSort(sortData, A_SIZE);

	//Copy(data, sortData, A_SIZE);
	//MergeSort(sortData, 0, A_SIZE-1);
	
	//Copy(data, sortData, A_SIZE);
	//QuickSort(sortData, 0, A_SIZE - 1);


	WriteDataToArray("DataReversed.txt", data, A_SIZE);

	cout << endl;
	cout << "Bubble Sort 'Reversed' " << endl;
	Copy(data, sortData, A_SIZE);
	BubbleSort(sortData, A_SIZE);

	cout << endl;
	cout << "Insertion Sort 'Reversed' " << endl;
	Copy(data, sortData, A_SIZE);
	InsertionSort(sortData, A_SIZE);
	
	cout << endl;
	cout << "Shell Sort 'Reversed' " << endl;
	Copy(data, sortData, A_SIZE);
	ShellSort(sortData, A_SIZE);

	//Copy(data, sortData, A_SIZE);
	//MergeSort(sortData, 0, A_SIZE-1);

	//Copy(data, sortData, A_SIZE);
	//QuickSort(sortData, 0, A_SIZE - 2);
	

	system("pause");

	return 0;
}

