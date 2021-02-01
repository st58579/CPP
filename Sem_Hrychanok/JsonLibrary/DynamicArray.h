#pragma once
#ifndef __DYNAMIC_ARRAY_H
#define __DYNAMIC_ARRAY_H

// - šablona s parametrem datového typu uložených hodnot
// - není povoleno užití STL kontejnerů ani jiných knihoven pro ukládání dat
// - realizace musí využívat dynamicky alokované pole, spojový seznam nebo jinou vhodnou Vámi implementovanou ADS 

///////////////////////////////////////////////////////////////////////////////
template <class T>
struct Node {
	Node(const T& data) : data(data), next(nullptr) {}
	~Node() { delete data; }
	T data;
	Node<T>* next;
};

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	~DynamicArray();

	// - přidá element na konec pole
	void append(const T& element);
	void remove(int index);
	// - výjimky při neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;

	// - vrací velikost (počet prvků) v poli
	int getSize() const;
private:
	Node<T>* first;
	Node<T>* actual;
	int size;
};


template<typename T>
DynamicArray<T>::DynamicArray()
{
	first = nullptr;
	actual = nullptr;
	size = 0;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	while (first != NULL)
	{
		Node<T>* tmp = first;
		first = first->next;
		delete tmp;
	}
	delete first;
}

template<typename T>
void DynamicArray<T>::append(const T& element)
{
	if (first == nullptr) {
		first = new Node<T>(element);
	}
	else {
		actual = first;
		while (actual->next != nullptr) {
			actual = actual->next;
		}
		actual->next = new Node<T>(element);
	}
	size++;
}

template<typename T>
void DynamicArray<T>::remove(int index) {
	if (index < size) {
		if (index == 0) {
			first = first->next;
			size--;
		}
		actual = first;
		for (size_t i = 0; i < index - 1; i++)
		{
			actual = actual->next;
		}
		delete actual->next;
		actual->next = actual->next->next;
		size--;
	}
	else {
		throw std::exception("invalid index");
	}
}


template<typename T>
const T& DynamicArray<T>::getElementAt(int index) const
{
	if (index > size - 1) {
		throw std::exception("wrong index");
	}
	Node<T>* act = first;
	for (size_t i = 0; i < index; i++)
	{
		act = act->next;
	}
	return act->data;
}

template<typename T>
int DynamicArray<T>::getSize() const
{
	return size;
}

#endif // !__DYNAMIC_ARRAY_H
