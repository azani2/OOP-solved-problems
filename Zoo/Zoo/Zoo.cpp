#include "Zoo.h"


void Zoo::resize() {
	capacity *= 2;
	Animal** temp = new Animal * [capacity];
	for (size_t i = 0; i < size; i++)
		temp[i] = animals[i];
	delete[] animals;
	animals = temp;
}

void Zoo::free() {
	for (size_t i = 0; i < size; i++)
		delete animals[i];
	delete[] animals;
}

void Zoo::addAnimal(Animal* toAdd) {
	if (size == capacity)
		resize();
	animals[size] = toAdd;
	size++;
}

void Zoo::addMammal(Mammal& toAdd) {
	addAnimal(new Mammal(toAdd));
	mammals.addAnimal(toAdd);
}

void Zoo::addBird(Bird& toAdd) {
	addAnimal(new Bird(toAdd));
	birds.addAnimal(toAdd);
}

int Zoo::feedAnimals() {
	int needToBuy = 0;
	for (size_t i = 0; i < size; i++)
	{
		int requiredFood = animals[i]->eat();
		switch (animals[i]->getFood()) {
			case food::meat:
				if (requiredFood > kgOfMeat)
				{
					std::cout << "Not enough meat to feed " << animals[i]->getName() << ".\n";
					needToBuy += requiredFood;
				}
				else
				{
					kgOfMeat -= requiredFood;
					std::cout << animals[i]->getName() << " ate " << requiredFood << " kgs of meat.\n";
				}
				break;
			case food::plants:
				if (requiredFood > kgOfPlants)
				{
					std::cout << "Not enough plants to feed " << animals[i]->getName() << ".\n";
					needToBuy += requiredFood;
				}
				else
				{
					kgOfPlants -= requiredFood;
					std::cout << animals[i]->getName() << " ate " << requiredFood << " kgs of plants.\n";
				}
				break;
			case food::both:
				if (requiredFood > kgOfPlants || requiredFood > kgOfMeat)
				{
					std::cout << "Not enough plants and meat to feed " << animals[i]->getName() << ".\n";
					needToBuy += requiredFood * 2;
				}
				else
				{
					kgOfPlants -= requiredFood;
					kgOfMeat -= requiredFood;
					std::cout << animals[i]->getName() << " ate " << requiredFood << " kgs of plants and kgs meat.\n";
				}
				break;
		}
	}
	std::cout << "Need to buy " << needToBuy << "kgs of meat and plants.\n";
	return needToBuy;
}

void Zoo::getCountOfAllAnimals() {
	std::cout << Animal::getAnimalsCount() << std::endl;
}

void Zoo::setPlants(int plantsKg) {
	kgOfPlants = plantsKg;
}

void Zoo::setMeat(int meatKg) {
	kgOfMeat = meatKg;
}

Zoo::Zoo() : size(0), capacity(1) {
	animals = new Animal * [capacity];
}

Zoo::Zoo(Zoo&& other) noexcept {
	this->size = other.size;
	this->capacity = other.capacity;
	this->animals = other.animals;
	other.animals = nullptr;
}

Zoo& Zoo::operator=(Zoo&& other) noexcept {
	if (this == &other)
		return *this;

	this->size = other.size;
	this->capacity = other.capacity;
	this->animals = other.animals;
	other.animals = nullptr;
	return *this;
}

Zoo::~Zoo() {
	for (size_t i = 0; i < size; i++)
		delete animals[i];
	delete[] animals;
}
