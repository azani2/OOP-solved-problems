#include "Car.h"


void Car::copy(const Car& other) {
	this->brand = other.brand;
	this->model = other.model;
	this->capacity = other.capacity;
	this->size = other.size;
	parts = new CarPart * [capacity];
	for (size_t i = 0; i < size; i++)
		parts[i] = other.parts[i]->clone();
}

void Car::resize() {
	capacity *= 2;
	CarPart** temp = new CarPart * [capacity];

	for (size_t i = 0; i < size; i++)
		temp[i] = parts[i];
	
	delete[] parts;
	parts = temp;
}

void Car::free() {
	for (size_t i = 0; i < size; i++)
		delete parts[i];
	delete[] parts;
}

void Car::displayCarParts() const {
	for (size_t i = 0; i < size; i++)
		parts[i]->display();
}

void Car::addPart(const CarPart& toAdd) {
	if (size == capacity)
		resize();

	parts[size] = toAdd.clone();
	size++;
}

void Car::setModel(std::string _model) {
	this->model = _model;
}

void Car::setBrand(std::string _brand) {
	this->brand = _brand;
}

Car::Car() {
	this->size = 0;
	this->capacity = 8;
	parts = new CarPart * [capacity];
}

Car::Car(const Car& other) {
	copy(other);
}

Car& Car::operator=(const Car& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Car::~Car() {
	free();
}