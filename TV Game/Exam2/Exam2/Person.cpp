#include "Person.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

int Person::id = 0;

void Person::copy(const Person& other) {
	personalId = other.personalId;
	age = other.age;
	businessCard = other.businessCard;
	intellect = other.intellect;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Person::free() {
	if (name) delete[] name;
}

Person::Person(char* _name, int _age, std::string _businessCard, int _intellect) {
	name = new char[strlen(_name)];
	strcpy(name, _name);
	age = _age;
	businessCard = _businessCard;
	intellect = _intellect;
	personalId = id;
	id++;
}

Person::Person(const Person& other) {
	copy(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

void Person::printInformation() {
	std::cout << name << ", aged: " << age << std::endl << businessCard << "\nIntellect: " << intellect << "\n---\n";
}

double Person::getCoefficient() const {
	return intellect / age;
}

char* Person::getName() {
	return name;
}

int Person::getId() const {
	return personalId;
}
double Person::getAge() const {
	return age;
}

std::string Person::getBussinessCard() const {
	return businessCard;
}

void Person::setIntellect(double _intellect) {
	intellect = _intellect;
}

Person::~Person() {
	free();
}