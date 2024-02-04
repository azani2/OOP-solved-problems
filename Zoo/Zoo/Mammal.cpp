#include "Mammal.h"

void Mammal::copy(const Mammal& other) {
	Animal::copy(other);
	this->fosterer = new char[strlen(other.fosterer)];
	strcpy(this->fosterer, other.fosterer);
}

void Mammal::free() {
	Animal::free();
	delete[] this->fosterer;
}

int Mammal::eat() const {
	return 4;
}

food Mammal::getFood() const {
	return this->foodType;
}

char* Mammal::getFosterer() const {
	return fosterer;
}

Mammal::Mammal(const char* _name, double weight, food foodType, const char* _fosterer) : Animal(_name, weight, foodType) {
	this->fosterer = new char[strlen(_fosterer)];
	strcpy(this->fosterer, _fosterer);
}

Mammal::Mammal(const Mammal& other) : Animal(other) {
	this->fosterer = new char[strlen(other.fosterer)];
	strcpy(this->fosterer, other.fosterer);
}

Mammal& Mammal::operator=(const Mammal& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Mammal::~Mammal() {
	delete[] this->fosterer;
}