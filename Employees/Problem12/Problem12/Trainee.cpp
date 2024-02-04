#include "Trainee.h"


void Trainee::copy(const Trainee& other) {
	Employee::copy(other);
	this->weeksLeft = other.weeksLeft;
}

void Trainee::print() {
	std::cout << "Trainee: ";
	Employee::print();
	std::cout << ", " << weeksLeft << " weeks left\n";
}

Trainee::Trainee() : Employee(), weeksLeft(0) {}

Trainee::Trainee(std::string _name, unsigned _age, unsigned _salary, unsigned _weeksLeft) : Employee(_name, _age, _salary), weeksLeft(_weeksLeft) {}

Trainee::Trainee(const Trainee& other) {
	copy(other);
}

Trainee& Trainee::operator=(const Trainee& other) {
	if (this != &other)
		copy(other);
	return *this;
}


Employee* Trainee::clone() {
	return new Trainee(*this);
}
