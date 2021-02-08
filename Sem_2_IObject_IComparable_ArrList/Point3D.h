#pragma once
#ifndef POINT3D_H
#define POINT3D_H
#include "IObject.h"
#include "IComparable.h"
#include <string>

class Point3D : public IObject, public IComparable {
public:
	Point3D();
	Point3D(double x, double y, double z);
	~Point3D();
	double getX() const;
	double getY() const;
	double getZ() const;
	std::string toString() override;
	int compareTo(IComparable* c) const override;
private:
	double x, y, z;
};

#endif // !POINT3D_H