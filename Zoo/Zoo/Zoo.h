#pragma once
#include "ZooSector.h"

class Zoo {
private:
	std::string name;
	int kgOfPlants;
	int kgOfMeat;
	ZooSector<Mammal> mammals;
	ZooSector<Bird> birds;
	Animal** animals;
	size_t size, capacity;

	void resize();
	void free();
	void addAnimal(Animal* toAdd);

public:
	void addMammal(Mammal& toAdd);
	void addBird(Bird& toAdd);
	int feedAnimals();

	static void getCountOfAllAnimals();

	void setPlants(int plantsKg);
	void setMeat(int meatKg);

	Zoo();
	Zoo(Zoo&& other) noexcept;
	Zoo& operator=(Zoo&&) noexcept;
	~Zoo();

	Zoo(const Zoo& other) = delete;//trqbva clone() na vseki animal
	Zoo& operator=(const Zoo& other) = delete;
};

