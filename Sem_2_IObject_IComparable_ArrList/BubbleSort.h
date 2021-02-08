#pragma once
#include "ISortable.h"
#include "ArrayList.h"
class BubbleSort {
public:
	void sort(ISortable* s);
private:
	void swap(ArrayList* arr, int p1, int p2);
};