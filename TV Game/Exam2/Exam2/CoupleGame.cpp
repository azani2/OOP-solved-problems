#include "CoupleGame.h"
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

CoupleGame::CoupleGame(const std::vector<Person>& _participants, Person* _host, char** _events) : TVGame(_participants, _host, _events) {
	pairs = new Pair[participantCapacity / 2];
	unsigned currentPair = 0;
	for (size_t i = 0; i < participantsSize; i += 2)
	{
		pairs[currentPair].firstPersonID = participants[i].getId();
		pairs[currentPair].secondPersonID = participants[i + 1].getId();
		currentPair++;
	}
}

void CoupleGame::doEvent() {
	Pair chosenPair = findBanishedParticipants();
	char* nextEvent = new char[100];
	strcpy(nextEvent, "Do event: \0");
	char firstPersonName[20];
	char secondPersonName[20];

	for (size_t i = 0; i < participantsSize; i++)
	{
		int currentID = participants[i].getId();
		if (currentID == chosenPair.firstPersonID)
			strcpy(firstPersonName, participants[i].getName());
		else if (currentID == chosenPair.secondPersonID)
			strcpy(secondPersonName, participants[i].getName());
	}

	strcat(nextEvent, firstPersonName);
	strcat(nextEvent, " and ");
	strcat(nextEvent, secondPersonName);
	strcat(nextEvent, " were eliminated.");

	events[eventsSize] = nextEvent;
	eventsSize++;
}

CoupleGame::Pair CoupleGame::findBanishedParticipants() {
	Pair chosenPair = pairs[0];
	double firstPersonCoef = participants[0].getCoefficient();
	double secondPersonCoef = participants[1].getCoefficient();
	double minCoef = firstPersonCoef + secondPersonCoef;
	for (size_t i = 2; i < participantsSize; i += 2) {
		double currentCoef = participants[i].getCoefficient() + participants[i + 1].getCoefficient();
		if (currentCoef < minCoef) {
			chosenPair.firstPersonID = participants[i].getId();
			chosenPair.secondPersonID = participants[i + 1].getId();
			minCoef = currentCoef;
		}
	}
	for (size_t i = 0; i < participantsSize; i++) {
		if (participants[i].getId() == chosenPair.firstPersonID || participants[i].getId() == chosenPair.secondPersonID) {
			participants[i].setIntellect(100);//should be done with boolean array for banishment instead to not change person data 
		}
	}
	return chosenPair;
}

CoupleGame::~CoupleGame() {
	delete[] pairs;
}