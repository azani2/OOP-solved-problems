#include "Shapes.h"
#include <iostream>

double dist(point& pointA, point& pointB) {
	float xB = pointB.x;
	float yB = pointB.y;
	float xAB = pointA.x - xB;
	float yAB = pointA.y - yB;

	return sqrt(xAB * xAB + yAB * yAB);
}

Shape::Shape(const point* _points, const unsigned _pointsCount) : pointsCount(_pointsCount) {
	points = new point[pointsCount];
	for (size_t i = 0; i < pointsCount; i++)
	{
		points[i].x = _points[i].x;
		points[i].y = _points[i].y;
	}
}

void Shape::setPointAt(size_t idx, float _x, float _y) {
	if (idx >= this->pointsCount)
		throw std::exception("Index out of bounds!");

	this->points[idx] = { _x, _y };
}

bool Shape::hasPoint(const point& _point) {
	for (size_t i = 0; i < pointsCount; i++)
	{
		if (this->points[i].x == _point.x && this->points[i].y == _point.y)
			return true;
	}
	return false;
}

bool Shape::hasPoint(const float _x, const float _y) {
	for (size_t i = 0; i < pointsCount; i++)
	{
		if (this->points[i].x == _x && this->points[i].y == _y)
			return true;
	}
	return false;
}

Shape::~Shape() {
	delete[] this->points;
}

bool Shape::valid() {
	return pointsCount;
}

Circle::Circle(const point* _points, const unsigned _pointsCount, const point& _center) : Shape(_points, _pointsCount) {
	center = new point();
	center->x = _center.x;
	center->y = _center.y;
}

bool Circle::valid() {
	return this->pointsCount >= 1;
}

double Circle::area() {
	float r = radius();
	return 3.14 * r * r;
}

double Circle::radius() {
	if (!Circle::valid())
		return 0;

	return dist(*this->center, this->points[0]);
}

double Circle::perimeter() {
	float r = radius();
	return 6.28 * r;
}

Circle::~Circle() {
	delete center;
}

Triangle::Triangle(const point* _points) : Shape(_points, 3) {
	
}

bool Triangle::valid() {
	return this->pointsCount == 3;
}

double Triangle::area() {
	if (!Triangle::valid())
		return 0;
	double aLen = dist(this->points[0], this->points[1]);
	double bLen = dist(this->points[0], this->points[2]);
	double cLen = dist(this->points[2], this->points[1]);

	double halfP = Triangle::perimeter() / 2;

	return sqrt(halfP * (halfP - aLen) * (halfP - bLen) * (halfP - cLen));
}

double Triangle::perimeter() {
	if (!Triangle::valid())
		return 0;
	double aLen = dist(this->points[0], this->points[1]);
	double bLen = dist(this->points[0], this->points[2]);
	double cLen = dist(this->points[2], this->points[1]);

	return aLen + bLen + cLen;
}

Rectangle::Rectangle(const point* _points) : Shape(_points, 4) {

}

bool Rectangle::valid() {
	return this->pointsCount == 4;
}

double Rectangle::area() {//assuming points are ordered
	if (!Rectangle::valid())
		return 0;
	double aLen = dist(this->points[0], this->points[1]);
	double bLen = dist(this->points[0], this->points[3]);
	return aLen * bLen;
}

double Rectangle::perimeter() {//assuming points are ordered
	if (!Rectangle::valid())
		return 0;
	double aLen = dist(this->points[0], this->points[1]);
	double bLen = dist(this->points[0], this->points[3]);

	return 2 * (aLen + bLen);
}
