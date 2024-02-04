#pragma once
#include "Person.h"
#include <vector>

class TVGame {
private:
	const size_t MAX_ARR_SIZE = 200;
protected:
	unsigned eventsSize;
	unsigned participantsSize;
	std::vector<Person> participants;
	Person* host;
	char** events;

public:
	TVGame(const std::vector<Person>& _participants, Person* _host, char** _events);
	void showEvents(unsigned limit);
	void printFormatInformation();
	virtual void doEvent() = 0;
	virtual ~TVGame();
};
