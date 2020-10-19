#pragma once
#ifndef OBJECT_H
#define OBJECT_H
class Object {
private:
	int id;
	double x;
	double y;
	
public:
	Object(int id, int x, int y);
	virtual ~Object() {};
	double GetX() const;
	double GetY() const;
	int GetID() const;
	void SetX(double x);
	void SetY(double y);
	void SetID(int id);
};
#endif //OBJECT_H
