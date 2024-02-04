#pragma once
#include "Employee.h"

class Trainee : virtual public Employee {
protected:
	unsigned weeksLeft;

	virtual void copy(const Trainee& other);
public:
	virtual void print();

	Trainee();
	Trainee(std::string _name, unsigned _age, unsigned _salary, unsigned _weeksLeft);
	Trainee(const Trainee& other);
	Trainee& operator=(const Trainee& other);
	virtual ~Trainee() = default;

	Employee* clone() override;
};

