#include "Point3D.h"

Point3D::Point3D() : x(0), y(0), z(0)
{
}

Point3D::Point3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

Point3D::~Point3D()
{
}

double Point3D::getX() const
{
	return x;
}

double Point3D::getZ() const
{
	return z;
}

double Point3D::getY() const
{
	return y;
}
std::string Point3D::toString()
{
	std::string str = "x : " + std::to_string(x) + ", y : " + std::to_string(y) + ", z : " + std::to_string(z);
	return str;
}

int Point3D::compareTo(IComparable* c) const
{
	Point3D* p = dynamic_cast<Point3D*>(c);
	double d1 = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	double d2 = sqrt(pow(0 - p->getX(), 2) + pow(0 - p->getY(), 2) + pow(0 - p->getZ(), 2));
	if (d1 == d2) return 0;
	else if (d1 > d2) return 1;
	else return -1;
}
