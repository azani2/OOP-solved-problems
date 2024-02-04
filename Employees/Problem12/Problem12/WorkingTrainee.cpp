#include "WorkingTrainee.h"

void WorkingTrainee::free() {
	name = "";
	age = 0;
	salary = 0;
	weeksLeft = 0;
	months = 0;
	projects.clear();
}

void WorkingTrainee::copy(const WorkingTrainee& other) {
	Employee::copy(other);
	this->months = other.months;
	this->projects = other.projects;
	this->weeksLeft = other.weeksLeft;
}

void WorkingTrainee::print() {
	std::cout << "Working Trainee: ";
	Employee::print();
	std::cout << ", " << weeksLeft << " weeks left, ";
	std::cout << ", " << months << " months, projects : {";
	size_t length = projects.size() - 1;
	for (size_t i = 0; i < length; i++)
		std::cout << projects[i] << ", ";
	std::cout << projects[length] << " }\n";
}

WorkingTrainee::WorkingTrainee() : Worker(), Trainee() {}

WorkingTrainee::WorkingTrainee(std::string _name, unsigned _age, unsigned _salary, unsigned _months, const size_t* _projects, const size_t size, unsigned _weeksLeft) : Worker(_name, _age, _salary, _months, _projects, size), Trainee(_name, _age, _salary, _weeksLeft) {}

WorkingTrainee::WorkingTrainee(const WorkingTrainee& other) {
	copy(other);
}

WorkingTrainee& WorkingTrainee::operator=(const WorkingTrainee& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Employee* WorkingTrainee::clone() {
	return new WorkingTrainee(*this);
}
