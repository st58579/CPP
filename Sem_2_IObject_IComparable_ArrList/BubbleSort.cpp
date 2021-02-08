#include "BubbleSort.h"
#include "ArrayList.h"
void BubbleSort::sort(ISortable* s)
{
	int i, j;
	ArrayList* arr = dynamic_cast<ArrayList*>(s);
	for (i = 0; i < arr->getCount()-1; i++)
	{
		for (j = 0; j < arr->getCount()-i-1; j++)
		{
			Point3D* p1 = dynamic_cast<Point3D*>(arr->get(j));
			Point3D* p2 = dynamic_cast<Point3D*>(arr->get(j+1));
			if (p1->compareTo(p2) == 1) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void BubbleSort::swap(ArrayList* arr, int p1, int p2)
{
	IComparable* tmp = arr->get(p1);
	arr->set(p1, arr->get(p2));
	arr->set(p2, tmp);
}

