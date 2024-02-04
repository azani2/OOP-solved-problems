#pragma once
#include "Mammal.h"
#include "Bird.h"
#include <vector>

template<typename AnimalType>
class ZooSector {
private:
	std::vector<AnimalType> animals;
	double x, y;

public:
	ZooSector() = default;
	ZooSector(double x, double y);
	void addAnimal(const AnimalType& toAdd);
	void printAnimals();
};

template<typename AnimalType>
ZooSector<AnimalType>::ZooSector(double x, double y) : x(x), y(y) {}

template<typename AnimalType>
void ZooSector<AnimalType>::addAnimal(const AnimalType& toAdd) {
	this->animals.push_back(toAdd);
}

