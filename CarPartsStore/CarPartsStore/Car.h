#pragma once
#include "Piston.h"
#include "Engine.h"
#include "FuelTank.h"
#include "Tire.h"

class Car {
private:
	std::string brand;
	std::string model;
	CarPart** parts;
	size_t size, capacity;

	void copy(const Car& other);
	void resize();
	void free();

public:
	void displayCarParts() const;
	void addPart(const CarPart& toAdd);
	void setModel(std::string _model);
	void setBrand(std::string _brand);

	Car();
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();
};

