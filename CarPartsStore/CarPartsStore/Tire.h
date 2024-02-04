#pragma once
#include "CarPart.h"

class Tire : public CarPart {
private:
	unsigned width;
	int profile;
	unsigned diameter;

public:
	void display() const override;
	CarPart* clone() const override;

	Tire(std::string name, std::string manufacturer, unsigned year, unsigned width, int profile, unsigned diameter);
	~Tire() = default;
};

