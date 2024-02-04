#pragma once
#include "Employee.h"
#include "Trainee.h"
#include "Worker.h"
#include "WorkingTrainee.h"

class EmployeeCollection {
private:
	std::vector<Employee*> collection;
public:
	void printEmployees();

	EmployeeCollection() = default;
	EmployeeCollection(const EmployeeCollection& other);
	void addWorker(const Worker& toAdd);
	void addTrainee(const Trainee& toAdd);
	void addWorkingTrainee(const WorkingTrainee& toAdd);
};

