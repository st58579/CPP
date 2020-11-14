#ifndef CVICENI_06_GROWINGCONTAINER_H
#define CVICENI_06_GROWINGCONTAINER_H

#include <algorithm>
#include <exception>


template<typename T, int StartSize = 5, int GrowingCoefficient = 2>
class GrowingContainer {
public:
    GrowingContainer();

    ~GrowingContainer();

    bool isAnyPlaceAvailable(); //true when there is any space for data
    void increaseSize(); //_arrSize = _arrSize*GrowingCoefficient
    void add(const T &o); //on first available place, if filled -> increaseSize()
    T &operator[](int index); //
    T operator[](int index) const;
    unsigned int count() const; //valid elements count

    void addOnIndex(int index, const T &o); //move data to the right
    void remove(int index); //move data to the left
private:
    T *_arr;
    unsigned _arrSize;
    unsigned _validElementsCount;
};


template<typename T, int StartSize, int GrowingCoefficient>
GrowingContainer<T, StartSize, GrowingCoefficient>::GrowingContainer() {
    _arr = new T[StartSize];
    _arrSize = StartSize;
    _validElementsCount = 0;
}

template<typename T, int StartSize, int GrowingCoefficient>
GrowingContainer<T, StartSize, GrowingCoefficient>::~GrowingContainer() {
    delete[] _arr;
}

template<typename T, int StartSize, int GrowingCoefficient>
bool GrowingContainer<T, StartSize, GrowingCoefficient>::isAnyPlaceAvailable() {
    if (_arrSize > _validElementsCount) {
        return true;
    } else return false;
}

template<typename T, int StartSize, int GrowingCoefficient>
void GrowingContainer<T, StartSize, GrowingCoefficient>::increaseSize() {
    _arrSize = _arrSize * GrowingCoefficient;
    T *newArr = new T[_arrSize];
    std::copy(_arr, _arr+_validElementsCount, newArr);
    delete[] _arr;
    _arr = newArr;
}

template<typename T, int StartSize, int GrowingCoefficient>
void GrowingContainer<T, StartSize, GrowingCoefficient>::add(const T &o) {
    if (!isAnyPlaceAvailable()) {
        increaseSize();
    }
    _arr[_validElementsCount] = o;
    _validElementsCount++;
}

template<typename T, int StartSize, int GrowingCoefficient>
T &GrowingContainer<T, StartSize, GrowingCoefficient>::operator[](int index) {
    if (index > _validElementsCount) {
        throw std::invalid_argument{"Illegal argument"};
    } else {
        return _arr[index];
    }
}

template<typename T, int StartSize, int GrowingCoefficient>
T GrowingContainer<T, StartSize, GrowingCoefficient>::operator[](int index) const {
    if (index > _validElementsCount) {
        throw std::invalid_argument{"Illegal argument"};
    } else {
        return *_arr[index];
    }
}

template<typename T, int StartSize, int GrowingCoefficient>
unsigned int GrowingContainer<T, StartSize, GrowingCoefficient>::count() const {
    return _validElementsCount;
}

template<typename T, int StartSize, int GrowingCoefficient>
void GrowingContainer<T, StartSize, GrowingCoefficient>::addOnIndex(int index, const T &o) {
    if (!isAnyPlaceAvailable()) {
        increaseSize();
    }
    T *newArr = new T[_arrSize];
    std::copy(_arr, _arr + index - 1, newArr);
    newArr[index] = o;
    std::copy(_arr + index, _arr+_validElementsCount, newArr + index + 1);
    delete[] _arr;
    _arr = newArr;
}

template<typename T, int StartSize, int GrowingCoefficient>
void GrowingContainer<T, StartSize, GrowingCoefficient>::remove(int index) {
    T *newArr = new T[_arrSize];
    std::copy(_arr, _arr + index - 1, newArr);
    std::copy(_arr + index + 1, _arr + _validElementsCount, newArr + index);
    delete[] _arr;
    _arr = newArr;
}

#endif //CVICENI_06_GROWINGCONTAINER_H
