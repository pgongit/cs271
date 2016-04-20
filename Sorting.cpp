#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <vector> 
#include <fstream>
#include <iostream>


using namespace std;

const int A_SIZE = 10000;
int Swaps;
int Comparisons;
enum SortType{ bubble, quick, insertion, shell, merge};



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
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			Comparisons++;
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
				Swaps++;
			}
		}
	}
}


void InsertionSort(int data[], int n)
{
	int i, j, element;
	for (i = 1; i < n; i++)
	{
		element = data[i];
		j = i;
		while ((j > 0) && (data[j - 1] > element))
		{
			data[j] = data[j - 1];
			j = j - 1;
			Comparisons++;
			Swaps++;
			
		}
		data[j] = element;
	}
}



void ShellSort(int data[], int n)
{
	int temp, gap, i;
	int swapped;
	gap = n / 2;
	do
	{
		do {
			swapped = 0;
			for (i = 0; i < n - gap; i++)
			{
				Comparisons++;
				if (data[i] > data[i + gap])
				{
					temp = data[i];
					data[i] = data[i + gap];
					data[i + gap] = temp;
					swapped = 1;
					Swaps++;
				}
			}
		} while (swapped == 1);
	} while ((gap = gap / 2) >= 1);
}




int QuickSortPartition(int data[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = data[(left + right) / 2];

	while (i <= j) {
		while (data[i] < pivot)
			i++;

		while (data[j] > pivot)
			j--;

		if (i <= j) {
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			Swaps++;
			i++;
			j--;
		}
	};
	return i;
}
void QuickSort(int data[], int left, int right)
{
	
	int index = QuickSortPartition(data, left, right);
	Comparisons++;
	if (left < index - 1)
	{
		QuickSort(data, left, index - 1);
	}

	if (index < right)
	{
		QuickSort(data, index, right);
	}
}



void Merge(int data[], int size1, int size2)
{
	int temp[A_SIZE];
	int ptr1 = 0, ptr2 = 0;
	int *arr1 = data, *arr2 = data + size1;

	while (ptr1 + ptr2 < size1 + size2) {
		
		Swaps++;
		if (ptr1 < size1 && arr1[ptr1] <= arr2[ptr2] || ptr1 < size1 && ptr2 >= size2)
		{
			temp[ptr1 + ptr2] = arr1[ptr1++];
			Comparisons++;
		}
		if (ptr2 < size2 && arr2[ptr2] < arr1[ptr1] || ptr2 < size2 && ptr1 >= size1)
		{
			temp[ptr1 + ptr2] = arr2[ptr2++];
			Comparisons++;
		}
	}

	for (int i = 0; i < size1 + size2; i++)
	{
		data[i] = temp[i];
	}
}
void MergeSort(int data[], int n)
{
	if (n == 1)
		return;

	
	int size1 = n / 2, size2 = n - size1;
	MergeSort(data, size1);
	MergeSort(data + size1, size2);
	Merge(data, size1, size2);
	
}





void RunSort(int data[], string unsortedType, SortType sType)
{
	int sortData[A_SIZE];
	Swaps = 0;
	Comparisons = 0;
	string sortType = "";
	Copy(data, sortData, A_SIZE);

	switch (sType)
	{
	case bubble:
		sortType = "Bubble Sort";
		BubbleSort(sortData, A_SIZE);
		break;
	case quick:
		sortType = "Quick Sort";
		QuickSort(sortData, 0, A_SIZE - 1);
		break;
	case shell:
		sortType = "Shell Sort";
		ShellSort(sortData, A_SIZE);
		break;
	case insertion:
		sortType = "Insrtion Sort";
		InsertionSort(sortData, A_SIZE);
		break;
	case merge:
		sortType = "Merge Sort";
		MergeSort(sortData, A_SIZE);
		break;
	}

	cout << endl;
	cout << sortType << " " << unsortedType << endl;
	cout << "Number of swaps: " << Swaps << endl;
	cout << "Number of comparisons: " << Comparisons << endl;

	/*
	for (int k = 0; k < A_SIZE; k++)
	{
		cout << data[k] << " ";
	}

	cout << endl;
	for (int k = 0; k < A_SIZE; k++)
	{
		cout << sortData[k] << " ";
	}
	*/
}







int main()
{
	int data[A_SIZE];
	
	

	/*
	WriteDataToArray("Test.txt", data, A_SIZE);
	RunSort(data, "Test", bubble);
	RunSort(data, "Test", quick);
	RunSort(data, "Test", insertion);
	RunSort(data, "Test", shell);
	RunSort(data, "Test", merge);
	*/
	
	WriteDataToArray("DataFewUnique.txt", data, A_SIZE);
	RunSort(data, "Few Unique", bubble);
	RunSort(data, "Few Unique", quick);
	RunSort(data, "Few Unique", insertion);
	RunSort(data, "Few Unique", shell);
	RunSort(data, "Few Unique", merge);

	
	
	
	WriteDataToArray("DataNearlySorted.txt", data, A_SIZE);
	RunSort(data, "Nearly Sorted", bubble);
	RunSort(data, "Nearly Sorted", quick);
	RunSort(data, "Nearly Sorted", insertion);
	RunSort(data, "Nearly Sorted", shell);
	RunSort(data, "Nearly Sorted", merge);

	

	WriteDataToArray("DataRandom.txt", data, A_SIZE);
	RunSort(data, "Random", bubble);
	RunSort(data, "Random", quick);
	RunSort(data, "Random", insertion);
	RunSort(data, "Random", shell);
	RunSort(data, "Random", merge);



	WriteDataToArray("DataReversed.txt", data, A_SIZE);
	RunSort(data, "Reversed", bubble);
	RunSort(data, "Reversed", quick);
	RunSort(data, "Reversed", insertion);
	RunSort(data, "Reversed", shell);
	RunSort(data, "Reversed", merge);

	

	system("pause");

	return 0;
}

