#include "EmployeeCollection.h"

void EmployeeCollection::printEmployees() {
	size_t length = collection.size();
	for (size_t i = 0; i < length; i++)
		collection[i]->print();
}

EmployeeCollection::EmployeeCollection(const EmployeeCollection& other) {
	size_t size = other.collection.size();
	for (size_t i = 0; i < size; i++)
		collection[i] = other.collection[i]->clone();
}

void EmployeeCollection::addWorker(const Worker& toAdd) {
	Employee* newEmp = new Worker(toAdd);
	collection.push_back(newEmp);
}

void EmployeeCollection::addTrainee(const Trainee& toAdd) {
	Employee* newEmp = new Trainee(toAdd);
	collection.push_back(newEmp);
}

void EmployeeCollection::addWorkingTrainee(const WorkingTrainee& toAdd) {
	Employee* newEmp = new WorkingTrainee(toAdd);
	collection.push_back(newEmp);
}