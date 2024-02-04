#pragma once
#include <string>
#include <iostream>

class Employee {
protected:
	std::string name;
	unsigned age;
	unsigned salary;

	virtual void copy(const Employee& other);
public:
	const unsigned getSalary() const;
	virtual void print();

	Employee();
	Employee(std::string _name, unsigned _age, unsigned _salary);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	virtual ~Employee() = default;

	virtual Employee* clone() = 0;
};

