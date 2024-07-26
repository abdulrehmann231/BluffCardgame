#include "Card.h" 
#include "Player.h"
#include <iostream>
#include <string> 

//#include <fcntl.h>
#include "Bluff.h"
//#include <msclr/marshal_cppstd.h>

//using namespace System::IO;
using namespace std;
using namespace System::Collections::Generic;
//using namespace msclr::interop;


void Bluff::Next_Turn(player^ p)
{
	current_player_index++;
	if(current_player_index>= total_players)
	{
		current_player_index = 0;
		current_player = p;
	}
}
 Bluff::Bluff()
{
}
 Bluff::Bluff(player^ p, int c_i, int t)
{
	 current_player = p;
	 current_player_index = c_i;
	 total_players = t;

}
 Bluff^ Bluff::operator=(Bluff^ op)
 {
	 if (this != op) {


		 current_player = op->current_player;
		 current_player_index = op->current_player_index;
		 total_players = op->total_players;
	 }
		 return this;
	 
 }
 List<Card^>^ Bluff::InitializeDeck()
 {
	  List<Card^>^ Deck = gcnew List<Card^>();

	 char suits[] = { 'C', 'D', 'H', 'S' };
	 for (int s = 0; s < 4; s++) {
		 for (int v = 1; v <= 13; v++) {
			 String^ suitStr = gcnew String(std::string(1, suits[s]).c_str());
			 String^ valueStr = v.ToString();
			 String^ fileName = String::Format("{0}{1}.jpg", suitStr, valueStr);
			 String^ appDirectory = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
			 String^ imageFolder = System::IO::Path::Combine(appDirectory, "Images");
			 String^ imagePath = System::IO::Path::Combine(imageFolder, fileName);
			 imagePath = "D:\\New folder (2)\\repo\\CppCLR_WinformsProject1\\Images\\" + fileName;
			 /*if (System::IO::File::Exists(imagePath))*/
				 {
				 	Image^ cardImage = Image::FromFile(imagePath);
					Card^ card = gcnew Card(suits[s], v, cardImage);
		 			Deck->Add(card);
		 		 }
		 }
	 }
	 return Deck;
 }
 //{
	
	

	//		 // Get the path to the image
	
	

	//		 // Check if the image exists
	//		 
	//		 else
	//		 {
	//			 
	//		 }
	//	 }
	// }

	// return Deck;
 //}


 List<player^>^ Bluff::Distribute(List<player^>^ players , List<Card^>^ Deck)
 {
	 int numPlayers = players->Count;
	 int cardsPerPlayer = Deck->Count / numPlayers;
	 int remainingCards = Deck->Count % numPlayers;

	 int cardIndex = 0;
	 for (int i = 0; i < numPlayers; i++) {
		 for (int j = 0; j < cardsPerPlayer; j++) {
			 players[i]->AddCard(Deck[cardIndex++]);
		 }
	 }

	 // Distribute remaining cards
	 for (int i = 0; i < remainingCards; i++) {
		 players[i]->AddCard(Deck[cardIndex++]);
	 }
	 return players;
 }

 List<Card^>^ Bluff::Shuffle(List<Card^>^ Deck)
 {
	 Random^ rnd = gcnew Random();
	 int n = Deck->Count;
	 while (n > 1) {
		 n--;
		 int k = rnd->Next(n + 1);
		 Card^ temp = Deck[k];
		 Deck[k] = Deck[n];
		 Deck[n] = temp;
	 }
	 return Deck;
 }