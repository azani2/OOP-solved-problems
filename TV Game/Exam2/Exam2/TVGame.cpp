#include "Person.h"
#include "TVGame.h"
#include <vector>
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

TVGame::TVGame(const std::vector<Person>& _participants, Person* _host, char** _events) {
	participantsSize = _participants.size();
	for (size_t i = 0; i < participantsSize; i++)
		participants.push_back(_participants[i]);

	host = new Person(*_host);
	events = new char*[MAX_ARR_SIZE];
	eventsSize = 0;
	if (_events) {
		eventsSize = sizeof(_events) / sizeof(char*);
		for (size_t i = 0; i < eventsSize; i++) {
			events[i] = new char[MAX_ARR_SIZE];
			strcpy(events[i], _events[i]);
		}
	}
}

void TVGame::showEvents(unsigned limit) {
	std::cout << "Events recap: \n";
	for (size_t i = 0; i < eventsSize && i < limit; i++) {
		if ((events + i) != nullptr)
			std::cout << events[i] << std::endl;
	}

	if (limit > eventsSize)
		std::cout << "No more events are present\n\n";
}

void TVGame::printFormatInformation() {
	host->printInformation();
	for (size_t i = 0; i < participantsSize; i++)
		participants[i].printInformation();
}

TVGame::~TVGame() {
	for (size_t i = 0; i < eventsSize; i++)
		delete[] events[i];

	delete[] events;
}