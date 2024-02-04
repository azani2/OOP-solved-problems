#pragma once
#include "Student.h"

class School {
private:
	Student* students;
	size_t size, capacity;
	
	void free();
	void resize();
	void copy(const School& other);

public:
	School();
	School(const School& other);
	School(School&& other) noexcept;
	School& operator=(const School& other);
	School& operator=(School&& other) noexcept;
	~School();

	void addStudent(const Student& toAdd);
	void assignHouse(const std::string& _name, const std::string& _house);
	void givePower(const std::string& _name, const Power& _power);

	int getHouseStudentsCount(const std::string& _house) const;
	Student* getFirstStudent(const std::string& _house);
	const Student* getStudents() const;
	bool removeStudent(const std::string _name);

	friend std::ostream& operator<<(std::ostream& out, const School& school);
};

