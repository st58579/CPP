#include "time.h"
#include "Date.h"
#include "DateTime.h"
#include <iostream>
#define ARRAY_SIZE 10

using namespace std;

Time* getRandomTime() {
	Time* time = new Time(rand() % 24, rand() % 60, rand() % 60);
	return time;
}
Date* getRandomDate() {
	Date* date = new Date(rand() % 50 + 1970, rand() % 11+1, rand() % 29+1);
	return date;
}
DateTime* getRandomDateTime() {
	DateTime* dt = new DateTime(getRandomDate(), getRandomTime());
	return dt;
}

void swap(IComparable** arr, int index1, int index2) {
	IComparable* temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void printArray(IComparable** arr, int size)
{
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		cout << arr[i]->toString() << endl;
	}
}

int partition(IComparable** arr, int start, int end) {
	IComparable* pivot = arr[end];
	IComparable* temp;
	size_t index = start-1; //index of smallest element
	for (size_t i = start; i < end - 1; i++) //from left to rightmost element to pivot
	{
		if (arr[i]->compareTo(pivot) == -1) { //search for element, smaller than pivot
			index++;
			swap(arr, i, index); //swap found element with next from smallest	
		}
	}
	temp = arr[end];
	arr[end] = arr[++index];
	arr[index] = temp;
	return index;
}

void quickSort(IComparable** arr, int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end); //pivot on right place

		quickSort(arr, start, pivot - 1);
		quickSort(arr, pivot + 1, end);
	}
}

void InsertionSort(IComparable** arr, int size) {
	IComparable* tmp;
	for (size_t i = 1; i < size-1; i++)	//first element is already sorted
	{									
		size_t j = i;
		while (j > 0 && arr[j - 1] > arr[j]) { //insert element in right position
			tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}

void BubbleSort(IComparable** arr, int size) {
	IComparable* tmp;
	for (size_t i = 0; i < size-1; i++) //total amount of iteration
	{
		for (size_t j = 0; j < size-1; j++) //comparing pairs
		{
			if (arr[j]->compareTo(arr[j + 1]) == 1) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

}

void SelectionSort(IComparable** arr, int size) {
	int indexMin = 0;
	for (size_t i = 0; i < size-1; i++) //position in sorted part
	{
		indexMin = i;
		for (size_t j = i+1; j < size; j++) //selection from unsorted part
		{
			if (arr[j]->compareTo(arr[indexMin]) == -1) {
				indexMin = j;
			}
		}
		IComparable* temp = arr[i];
		arr[i] = arr[indexMin];
		arr[indexMin] = temp;
	}
}

int main() {

	/*       TIME TEST         */

	cout << "TIME TEST" << endl << endl;
	/* selection sort */
	IComparable** array = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		array[i] = getRandomTime();
	}
	printArray(array, ARRAY_SIZE);
	cout << "Selection sort" << endl;
	SelectionSort(array, ARRAY_SIZE);
	printArray(array, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* bubble sort */
	IComparable** arrayBubble = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayBubble[i] = getRandomTime();
	}
	printArray(arrayBubble, ARRAY_SIZE);
	cout << "Bubble sort" << endl;
	BubbleSort(arrayBubble, ARRAY_SIZE);
	printArray(arrayBubble, ARRAY_SIZE);
	cout <<  "___________________" << endl << endl;
	/* insertion sort */
	IComparable** arrayInsertion = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayInsertion[i] = getRandomTime();
	}
	printArray(arrayInsertion, ARRAY_SIZE);
	cout << "Insertion sort" << endl;
	BubbleSort(arrayInsertion, ARRAY_SIZE);
	printArray(arrayInsertion, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* quick sort */
	IComparable** arrayQuick = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayQuick[i] = getRandomTime();
	}
	printArray(arrayQuick, ARRAY_SIZE);
	cout << "Quick sort" << endl;
	quickSort(arrayQuick, 0, ARRAY_SIZE-1);
	printArray(arrayQuick, ARRAY_SIZE);
	cout << "___________________" << endl << endl;

	/*         DATE TEST         */	

	cout << "DATE TEST" << endl << endl;
	/* selection sort */
	IComparable** arrayD = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayD[i] = getRandomDate();
	}
	printArray(arrayD, ARRAY_SIZE);
	cout << "Selection sort" << endl;
	SelectionSort(arrayD, ARRAY_SIZE);
	printArray(arrayD, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* bubble sort */
	IComparable** arrayDBubble = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDBubble[i] = getRandomDate();
	}
	printArray(arrayDBubble, ARRAY_SIZE);
	cout << "Bubble sort" << endl;
	BubbleSort(arrayDBubble, ARRAY_SIZE);
	printArray(arrayDBubble, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* insertion sort */
	IComparable** arrayDInsertion = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDInsertion[i] = getRandomDate();
	}
	printArray(arrayDInsertion, ARRAY_SIZE);
	cout << "Insertion sort" << endl;
	BubbleSort(arrayDInsertion, ARRAY_SIZE);
	printArray(arrayDInsertion, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* quick sort */
	IComparable** arrayDQuick = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDQuick[i] = getRandomDate();
	}
	printArray(arrayDQuick, ARRAY_SIZE);
	cout << "Quick sort" << endl;
	quickSort(arrayDQuick, 0, ARRAY_SIZE - 1);
	printArray(arrayDQuick, ARRAY_SIZE);
	cout << "___________________" << endl << endl;

	/*         DATE_TIME TEST         */

	cout << "DATE_TIME TEST" << endl << endl;
	/* selection sort */
	IComparable** arrayDT = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDT[i] = getRandomDateTime();
	}
	printArray(arrayDT, ARRAY_SIZE);
	cout << "Selection sort" << endl;
	SelectionSort(arrayDT, ARRAY_SIZE);
	printArray(arrayDT, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* bubble sort */
	IComparable** arrayDTBubble = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDTBubble[i] = getRandomDateTime();
	}
	printArray(arrayDTBubble, ARRAY_SIZE);
	cout << "Bubble sort" << endl;
	BubbleSort(arrayDTBubble, ARRAY_SIZE);
	printArray(arrayDTBubble, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* insertion sort */
	IComparable** arrayDTInsertion = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDTInsertion[i] = getRandomDateTime();
	}
	printArray(arrayDTInsertion, ARRAY_SIZE);
	cout << "Insertion sort" << endl;
	BubbleSort(arrayDTInsertion, ARRAY_SIZE);
	printArray(arrayDTInsertion, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
	/* quick sort */
	IComparable** arrayDTQuick = new  IComparable * [ARRAY_SIZE];
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		arrayDTQuick[i] = getRandomDateTime();
	}
	printArray(arrayDTQuick, ARRAY_SIZE);
	cout << "Quick sort" << endl;
	quickSort(arrayDTQuick, 0, ARRAY_SIZE - 1);
	printArray(arrayDTQuick, ARRAY_SIZE);
	cout << "___________________" << endl << endl;
}