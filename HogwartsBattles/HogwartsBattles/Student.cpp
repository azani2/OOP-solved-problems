#include "Student.h"

Student::Student() : power(nullptr), health(100) {
	name = "";
	house = "";
}

Student::Student(const std::string& name, const std::string& house, int health, const Power* power) : name(name), house(house), health(health), power(power) {}

const std::string& Student::getName() const {
	return name;
}

const std::string& Student::getHouse() const {
	return house;
}

int Student::getHealth() const {
	return health;
}

const Power* Student::getPower() const {
	return power;
}

bool Student::isAlive() const {
	return health > 0;
}

int Student::attack() const {
	return power->getDamage();
}

void Student::takeDamage(int damage) {
	health -= damage;
}

void Student::setHouse(const std::string& _house) {
	this->house = _house;
}

void Student::setPower(const Power* _power) {
	this->power = _power;
}

