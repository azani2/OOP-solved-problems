#pragma once
#include "Trainee.h"
#include "Worker.h"

class WorkingTrainee : public Trainee, public Worker {
private:
	void free() override;
	void copy(const WorkingTrainee& other);

public:
	void print();

	WorkingTrainee();
	WorkingTrainee(std::string _name, unsigned _age, unsigned _salary, unsigned _months, const size_t* _projects, const size_t size, unsigned _weeksLeft);
	WorkingTrainee(const WorkingTrainee& other);
	WorkingTrainee& operator=(const WorkingTrainee& other);
	virtual ~WorkingTrainee() = default;

	Employee* clone() override;
};

