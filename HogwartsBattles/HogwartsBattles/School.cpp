#include "School.h"
#include <iostream>

void School::free() {
	delete[] students;
	size = capacity = 0;
}

void School::resize() {
	capacity *= 2;
	Student* temp = new Student[capacity];
	for (size_t i = 0; i < size; i++)
		temp[i] = students[i];
	delete[] students;
	students = temp;
}

void School::copy(const School& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	students = new Student[capacity];
	for (size_t i = 0; i < size; i++)
		students[i] = other.students[i];
}

School::School() : size(0), capacity(8) {
	students = new Student[capacity];
}

School::School(const School& other) {
	copy(other);
}

School::School(School&& other) noexcept : students(other.students), size(other.size), capacity(other.capacity) {
	other.students = nullptr;
	other.capacity = 8;
	other.size = 0;
}

School& School::operator=(const School& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

School& School::operator=(School&& other) noexcept {
	if (this != &other)
	{
		free();
		students = other.students;
		size = other.size;
		capacity = other.capacity;
		other.students = nullptr;
		other.size = 0;
		other.capacity = 8;
	}
	return *this;
}

School::~School() {
	free();
}

void School::addStudent(const Student& toAdd) {
	if (size == capacity)
		resize();
	students[size] = toAdd;
	size++;
}

void School::assignHouse(const std::string& _name, const std::string& _house) {
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getName() == _name)
		{
			students[i].setHouse(_house);
			break;
		}
	}
}

void School::givePower(const std::string& _name, const Power& _power) {
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getName() == _name)
		{
			students[i].setPower(&_power);
			break;
		}
	}
}

int School::getHouseStudentsCount(const std::string& _house) const {
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getHouse() == _house)
			count++;
	}
	return count;
}

Student* School::getFirstStudent(const std::string& _house) {
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getHouse() == _house)
			return &students[i];
	}
	return nullptr;
}

const Student* School::getStudents() const {
	return students;
}

bool School::removeStudent(const std::string _name) {
	for (size_t i = 0; i < size; i++)
	{
		if (students[i].getName() == _name)
		{
			size--;
			for (size_t j = i; j < size; j++)
				students[j] = students[j + 1];
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, const School& school) {
	size_t length = school.size;
	for (size_t i = 0; i < length; i++)
	{
		std::cout << school.students[i].getName() << " ("
			<< school.students[i].getHouse() << ") \n";
	}
	return out;
}