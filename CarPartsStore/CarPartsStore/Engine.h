#pragma once
#include "CarPart.h"
#include "Piston.h"
#include <vector>

class Engine : public CarPart {
private: 
	unsigned power;
	std::vector<Piston> pistons;

public:
	void display() const override;
	CarPart* clone() const override;
	Engine(std::string name, std::string manufacturer, unsigned year, unsigned power, const Piston* pistons, size_t size);
	Engine(std::string name, std::string manufacturer, unsigned year, unsigned power);
	void addPiston(const Piston& toAdd);
};

