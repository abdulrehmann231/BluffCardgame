#pragma once
#include "Player.h"

using namespace System::Collections::Generic;
ref class  Bluff
{
private:

	player^ current_player;
	int current_player_index = 0;  
	int total_players = 0;
public:
	void Next_Turn(player^ p);
	Bluff();
	Bluff(player^ p, int c_i, int t);
	Bluff^ operator=(Bluff^ op);
	List<Card^>^ InitializeDeck();
	List<player^>^ Distribute(List<player^>^ players, List<Card^>^ Deck);
	List<Card^>^ Shuffle(List<Card^>^ Deck);
	
	
	
};

