#include "Card.h"
#include <vector>
#pragma once        
using namespace System;
using namespace std;
using namespace System::Collections::Generic;
ref class Bluff;
ref class player {
private:
	String^ name;
	List<Card^>^ cards;
public:
	player(String^ p);
	String^ Get_name();
	void Set_name(String^ n);
	void AddCard(Card^ c);
	void RemoveCard(Card^ c);
	List<Card^>^ GetCards();
	
};