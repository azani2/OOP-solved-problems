#include "Engine.h"

void Engine::display() const {
	displayBase();
	std::cout << ", " << power << "hp, pistons:\n";
	size_t length = pistons.size();
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "    ";
		pistons[i].display();
	}
}

CarPart* Engine::clone() const {
	return new Engine(*this);
}

Engine::Engine(std::string name, std::string manufacturer, unsigned year, unsigned power, const Piston* pistons, size_t size) : CarPart(name, manufacturer, year), power(power) {
	for (size_t i = 0; i < size; i++)
		this->pistons.push_back(pistons[i]);
}

Engine::Engine(std::string name, std::string manufacturer, unsigned year, unsigned power) : CarPart(name, manufacturer, year), power(power) {}

void Engine::addPiston(const Piston& toAdd) {
	this->pistons.push_back(toAdd);
}
