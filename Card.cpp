#include "Card.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
char Card::Get_suit()
{
	return suit;
}
int Card::Get_value()
{
	return value;

}
Image^ Card::Get_pic()
{
    return Cardpic;
}

Card::Card(char s, int v, Image^ Cp) {
    suit = s;
    value = v;
    Cardpic = Cp;
}
Card::Card()
{

}
void Card::set_suit(char s)
{
    suit = s;
}
void Card::set_value(int v)
{
    value = v;
}
void Card::set_pic(Image^ i)
{
    Cardpic = i;
}


