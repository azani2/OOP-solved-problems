#include "Employee.h"

void Employee::copy(const Employee& other) {
	this->name = other.name;
	this->age = other.age;
	this->salary = other.salary;
}

unsigned const Employee::getSalary() const {
	return this->salary;
}

void Employee::print() {
	std::cout << name << ", " << age << ", " << salary;
}

Employee::Employee() : name(""), age(0), salary(0) {}

Employee::Employee(std::string _name, unsigned _age, unsigned _salary) : name(_name), age(_age), salary(_salary) {}

Employee::Employee(const Employee& other) {
	copy(other);
}

Employee& Employee::operator=(const Employee& other) {
	if (this != &other)
		copy(other);
	return *this;
}
