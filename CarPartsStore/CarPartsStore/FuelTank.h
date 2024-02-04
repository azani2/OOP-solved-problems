#pragma once
#include "CarPart.h"

template <typename T>
class FuelTank : public CarPart {
private:
	double volume;
	T fuelType;

public:
	FuelTank(std::string name, std::string manufacturer, unsigned year, double volume, T type);
	void display() const override;
	CarPart* clone() const override;
};

template <typename T>
FuelTank<T>::FuelTank(std::string name, std::string manufacturer, unsigned year, double volume, T type) : CarPart(name, manufacturer, year), volume(volume), fuelType(fuelType) {}

template <typename T>
void FuelTank<T>::display() const {
	displayBase();
	std::cout << ", " << volume << "l, " << fuelType << "\n";
}

template <typename T>
CarPart* FuelTank<T>::clone() const {
	return new FuelTank<T>(*this);
}