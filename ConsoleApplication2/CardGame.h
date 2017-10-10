#pragma once
class CardGame
{
	int players;
	static int totalParticipants;

public:
	CardGame(int players);
	~CardGame();
	static int GetParticipants() { return totalParticipants; }
};

