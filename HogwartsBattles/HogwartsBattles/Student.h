#pragma once
#include "Power.h"

class Student {
public:
	Student();
	Student(const std::string& name, const std::string& house, int health, const Power* power);

	const std::string& getName() const;
	const std::string& getHouse() const;
	int getHealth() const;
	const Power* getPower() const;

	bool isAlive() const;
	int attack() const;
	void takeDamage(int damage);

	void setHouse(const std::string& _house);
	void setPower(const Power* _power);

private:
	std::string name;
	std::string house;
	int health;
	const Power* power;
};

