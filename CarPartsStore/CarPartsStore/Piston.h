#pragma once
#include "CarPart.h"
class Piston : public CarPart {
private:
	double diameter;
	double range;

public:
	void display() const override;
	CarPart* clone() const override;

	Piston(std::string name, std::string manufacturer, unsigned year, double diameter, double range);
};

