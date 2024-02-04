#include "Worker.h"

void Worker::copy(const Worker& other) {
	Employee::copy(other);
	this->months = other.months;
	this->projects = other.projects;
}

void Worker::free() {
	months = 0;
	projects.clear();
}

void Worker::print() {
	std::cout << "Worker: ";
	Employee::print();
	std::cout << ", " << months << " months, projects : {";
	size_t length = projects.size() - 1;
	for (size_t i = 0; i < length; i++)
		std::cout << projects[i] << ", ";
	std::cout << projects[length] << " }\n";
}

Worker::Worker() : Employee(), months(0) {
	this->projects.clear();
}

Worker::Worker(std::string _name, unsigned _age, unsigned _salary, unsigned _months, const size_t* _projects, const size_t size) : Employee(_name, _age, _salary), months(_months) {
	for (size_t i = 0; i < size; i++)
		this->projects.push_back(_projects[i]);
}

Worker::Worker(const Worker& other) {
	copy(other);
}

Worker& Worker::operator=(const Worker& other) {
	if (this != &other)
		copy(other);
	return *this;
}


Employee* Worker::clone() {
	return new Worker(*this);
}
