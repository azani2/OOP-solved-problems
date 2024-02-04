#pragma once
#pragma warning (disable: 4996)
#include <iostream>
#include <cstring>

enum class food {
	meat,
	plants,
	both
};

class Animal {
private:
	static unsigned animalsCreated;
	char* name;

protected:
	double weight;
	food foodType;

	void copy(const Animal& other);
	void free();

public:
	static unsigned getAnimalsCount();
	virtual int eat() const = 0;
	virtual food getFood() const = 0;
	char* getName() const;
	double getWeight() const;

	Animal(const char* _name, double weight, food foodType);
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

};

