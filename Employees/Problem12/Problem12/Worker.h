#pragma once
#include "Employee.h"
#include <vector>

class Worker : virtual public Employee {
protected:
	unsigned months;
	std::vector<size_t> projects;

	virtual void copy(const Worker& other);
	virtual void free();
public:
	virtual void print();

	Worker();
	Worker(std::string _name, unsigned _age, unsigned _salary, unsigned _months, const size_t* _projects, const size_t size);
	Worker(const Worker& other);
	Worker& operator=(const Worker& other);
	virtual ~Worker() = default;

	Employee* clone() override;
};

