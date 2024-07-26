#include "Player.h"

player::player(String^ p) {
    name = p;
    cards = gcnew List<Card^>();
    
}

String^ player::Get_name() {
    return name;
}

void player::Set_name(String^ n) {
    name = n;
}
void player::AddCard(Card^ c)
{
    cards->Add(c);
}
void player::RemoveCard(Card^ c)
{
    cards->Remove(c);
}
List<Card^>^ player::GetCards() {
    return cards;
}
