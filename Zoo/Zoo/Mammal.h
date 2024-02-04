#pragma once
#include "Animal.h"

class Mammal : public Animal {
private:
	char* fosterer;

	void copy(const Mammal& other);
	void free();

public:
	int eat() const override;
	food getFood() const override;
	char* getFosterer() const;

	Mammal(const char* _name, double weight, food foodType, const char* _fosterer);
	Mammal(const Mammal& other);
	Mammal& operator=(const Mammal& other);
	~Mammal();
};

