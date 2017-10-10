#include "stdafx.h"
#include "CardGame.h"
#include <iostream>

using namespace std;

int CardGame::totalParticipants = 0;


CardGame::CardGame(int players) : players(players)
{
	totalParticipants += players;
	cout << players << " players have started a new game. There are now " 
		 << totalParticipants << " players in total." << endl;
}


CardGame::~CardGame()
{
	totalParticipants -= players;
	cout << players << " have finished their game. There are now "
		 << totalParticipants << " players in total" << endl;
}
