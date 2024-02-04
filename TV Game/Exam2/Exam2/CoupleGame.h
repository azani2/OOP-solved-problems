#pragma once
#include "TVGame.h"

class CoupleGame : public TVGame
{
private:
	struct Pair
	{
		int firstPersonID;
		int secondPersonID;
	};
	Pair* pairs;
	const unsigned participantCapacity = 22;

	Pair findBanishedParticipants();

public:
	CoupleGame(const std::vector<Person>& _participants, Person* _host, char** events);
	void doEvent() override;
	~CoupleGame() override;

};
