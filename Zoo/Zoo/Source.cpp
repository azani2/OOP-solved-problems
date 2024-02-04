#include "Zoo.h"

template<>
void ZooSector<Mammal>::printAnimals() {
	size_t length = animals.size();
	for (size_t i = 0; i < length; i++)
	{
		std::cout << animals[i].getName() << ", weighs " << animals[i].getWeight() << ", fosterer: " << animals[i].getFosterer() << "\n";
	}
}

template<>
void ZooSector<Bird>::printAnimals() {
	size_t length = animals.size();
	for (size_t i = 0; i < length; i++)
	{
		std::cout << animals[i].getName() << ", weighs " << animals[i].getWeight() << ", rescued from " << animals[i].getRescueCity() << ", " << animals[i].getNumberOfEggs() << " eggs \n";
	}
}

int main() {
	Mammal m1("mouse", 1, food::plants, "Pesho");
	Mammal m2("tiger", 40, food::meat, "RescueTeam");
	Bird b1("dodo", 5, food::plants, "earth 26mil years ago", 1);
	Bird b2("pterodactyl", 200, food::meat, "...", 1);
	Zoo zoo1;
	zoo1.addMammal(m1);
	zoo1.addMammal(m2);
	zoo1.addBird(b1);
	zoo1.addBird(b2);
	zoo1.setMeat(33);
	zoo1.setPlants(10);
	zoo1.feedAnimals();

	return 0;
}