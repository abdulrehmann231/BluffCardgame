#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Card  {
private:
	char suit;
	int value;
	Image^ Cardpic;
public:
	Card(char s, int v, Image^ Cp);
	Card();
	void set_suit(char s);
	void set_value(int v);
	void set_pic(Image^ i);
	char Get_suit();
	int Get_value();
	Image^ Get_pic();
	
	

};