#pragma once
#include <iostream>
#include <utility>

struct point {
	float x;
	float y;

	point() : x(0), y(0) {};
	point(const float _x, const float _y) : x(_x), y(_y) {};
};


class Shape {
protected:
	point* points;
	unsigned pointsCount;

public:
	Shape(const point* _points, const unsigned _pointsCount);
	void setPointAt(size_t idx, float _x, float _y);
	virtual double area() = 0;
	virtual double perimeter() = 0;
	bool hasPoint(const point& _point);
	bool hasPoint(const float _x, const float _y);
	virtual bool valid();
	virtual ~Shape();
};


class Circle : public Shape {
private:
	point* center;
public:
	Circle(const point* _points, const unsigned _pointsCount, const point& _center);
	bool valid() override;
	double area() override;
	double perimeter() override;
	double radius();
	~Circle();
};

class Triangle : public Shape {
public:
	Triangle(const point* _points);
	bool valid() override;
	double area() override;
	double perimeter() override;
};

class Rectangle : public Shape {
public:
	Rectangle(const point* _points);
	bool valid() override;
	double area() override;
	double perimeter() override;
};