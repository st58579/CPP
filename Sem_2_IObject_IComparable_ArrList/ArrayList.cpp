#include "ArrayList.h"



 ArrayList::ArrayList(int size)
{
	arr = new IComparable*[size];
	ArrayList::sizeArr = size;
	count = 0;
}

 ArrayList::~ArrayList()
{
	delete[] arr;
}


 int ArrayList::getCount() const
{
	return count;
}

 void ArrayList::increaseSize()
{
	sizeArr = sizeArr * 2;
	IComparable** newArr = new IComparable*[sizeArr];
	std::copy(arr, arr + count, newArr);
	delete[] arr;
	arr = newArr;
}

 void ArrayList::add(IComparable* c)
{
	if (count == sizeArr) increaseSize();
	arr[count] = c;
	count++;
}

 void ArrayList::remove(IComparable* c)
{
}

 int ArrayList::size() const
 {
	 return sizeArr;
 }

 IComparable* ArrayList::get(int pos)
 {
	 return arr[pos];
 }

 void ArrayList::set(int i, IComparable* ic)
 {
	 arr[i] = ic;
 }

