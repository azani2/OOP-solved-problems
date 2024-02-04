#pragma once
#include <string>
#include <iostream>

class CarPart {
private: 
	static unsigned count;
	unsigned id;
	std::string name;
	std::string manufacturer;
	unsigned year;

protected:
	void displayBase() const;

public:
	virtual void display() const = 0;
	static unsigned getCount();
	virtual CarPart* clone() const = 0;

	CarPart(std::string name, std::string manufacturer, unsigned year);
	virtual ~CarPart() = default;

};

