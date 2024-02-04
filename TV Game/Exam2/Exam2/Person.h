#pragma once
#include <string>

class Person
{
private:
	static int id;
	char* name;
	double age;
	std::string businessCard;
	double intellect;
	int personalId;

	void copy(const Person& other);
	void free();

public:
	Person(char* _name, int _age, std::string _businessCard, int _intellect);
	Person(const Person& other);
	Person& operator=(const Person& other);
	void printInformation();
	double getCoefficient() const;
	char* getName();
	int getId() const;
	double getAge() const;
	void setIntellect(double _intellect);
	std::string getBussinessCard() const;
	~Person();
};

