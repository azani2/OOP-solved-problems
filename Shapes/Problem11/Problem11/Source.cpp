#include "Shapes.h"
#include <iostream>

void printAreas(Shape* const* shapes, size_t size) {
	for (size_t i = 0; i < size; i++)
		std::cout << shapes[i]->area() << std::endl;
}

void printPerimeters(Shape* const* shapes, size_t size) {
	for (size_t i = 0; i < size; i++)
		std::cout << shapes[i]->perimeter() << std::endl;
}

void freeCollection(Shape** shapes, size_t size) {
	for (size_t i = 0; i < size; i++)
		delete shapes[i];

	delete[] shapes;
}

int main() {

	Shape** shapes = new Shape * [3];
	point circlePoints[1] = { {1, 1} };
	shapes[0] = new Circle(circlePoints, 1, {0, 0});
	
	point trianglePoints[3] = { {1, 1}, {4, 1}, {4, 4} };
	shapes[1] = new Triangle(trianglePoints);
	point rectanglePoints[4] = { {1, 1}, {4, 1}, {1, 4},  {1, 4} };
	shapes[2] = new Rectangle(rectanglePoints);
	/*for (size_t i = 0; i < 3; i++)
	{
		shapes[i]->area();
	}*/

	printAreas(shapes, 3);
	printPerimeters(shapes, 3);
	
}