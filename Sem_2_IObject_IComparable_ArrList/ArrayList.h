#pragma once
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "ISortable.h"
#include "Point3D.h"
class ArrayList : public ISortable{
public:
	ArrayList(int size);
	~ArrayList();
	int getCount() const;
	void increaseSize();
	void add(IComparable* c);
	void remove(IComparable* c);

	int size() const override;
	IComparable* get(int pos) override;
	void set(int i, IComparable* ic) override;
private:
	IComparable** arr;
	int sizeArr;
	int count;
};
#endif // !ARRAY_LIST_H
