#pragma once
#include "Animal.h"
#include <string>

class Bird : public Animal {
private:
	std::string rescueCity;
	int numberOfEggs;

public:
	int eat() const;
	food getFood() const;
	std::string getRescueCity() const;
	int getNumberOfEggs() const;

	Bird(const char* _name, double weight, food foodType, std::string rescueCity, int numberOfEggs);
	Bird(const Bird& other);
	Bird& operator=(const Bird& other);
	~Bird() = default;
};

