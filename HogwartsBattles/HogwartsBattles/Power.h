#pragma once
#include <iostream>
#include <string>
#include <cstring>

class Power {
private:
	std::string name;
	int damage;

public:
	Power(const std::string& name, int damage);
	friend bool operator<(const Power& left, const Power& right);

	const std::string& getName() const;
	int getDamage() const;
};

