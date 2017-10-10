#include "stdafx.h"
#include "CardGame.h"
#include <iostream>

using namespace std;

void PlayGames() {

	CardGame bridge(4);
	CardGame blackjack(8);
	CardGame solitaire(1);
	CardGame poker(5);
}

int main() {

	PlayGames();
	return 0;
}