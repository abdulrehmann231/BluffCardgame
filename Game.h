#pragma once
#include "Player.h"
#include "Bluff.h"
#include "Card.h"
#include "MyException.h"
#include "InvalidPlay.h"
#include "InvalidMoveExecption.h"
#include "InvalidBluffException.h"




namespace CppCLR_WinformsProject1 {


	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		List<player^>^ players;//list of players
		Bluff game;//object to control game
		int current=0;//current player index
		int cards_on_table = 0;// how many cards are there on table
		List<Card^>^ Deck = { nullptr };//deck of cards
		List<Card^>^ player_cards = { nullptr };// cards of current player
		List<Card^>^ Table = gcnew List<Card^>();//cards on table
		List<Card^>^ Cards_being_played = { nullptr };//cards being thrown by the current user
		int lastcards=0;//amount of cards played by the last user
		int lastPlayed = 0;//which user played the last cards
		MyException^ err;//for dealing with exceptions
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ BtnEnd;
		   int current_round;//which card is being placed on the table

		void ShowCards()
		{
			int c = 0;
			if (players[current]->GetCards()->Count >= 12)
			{
				c = 12;
			}
			else
			{
				c = players[current]->GetCards()->Count;
			}
			String^ PictureBoxName = "pb";
			for (int i = 0; i < c; i++)
			{
				PictureBoxName = "Card" + (i + 1).ToString();
				PictureBox^ pb = dynamic_cast<PictureBox^>(Controls->Find(PictureBoxName, true)[0]);
				if (player_cards != nullptr && player_cards[i]->Get_pic() != nullptr)
				{

					pb->BackgroundImage = player_cards[i]->Get_pic();
					pb->SizeMode = PictureBoxSizeMode::Zoom; // Adjust image size to fit PictureBox
					pb->BackgroundImageLayout = ImageLayout::Stretch;
					pb->Visible = true;
				}
			}
			for(int i=c;i<12;i++)
			{
				PictureBoxName = "Card" + (i + 1).ToString();
				PictureBox^ pb = dynamic_cast<PictureBox^>(Controls->Find(PictureBoxName, true)[0]);
				pb->Visible = false;
			}
		}
		void PickCards(int lost)//index of player who lost the beluff
		{
			for (int i = 0; i < cards_on_table; i++) {
				players[lost]->AddCard(Table[i]);
			}
			
			/*if(lost == current)
			{
				player_cards = players[lost]->GetCards();
				Lblhand->Text = "Cards in Hand : " + player_cards->Count;
			}*/
			

		}
		void Check_Winner()
		{
			for (int i = 0; i < players->Count; i++)
			{
				if (players[i]->GetCards()->Count <= 0)
				{
					MessageBox::Show(players[i]->Get_name() + " is the winner!!!!!!", "ATTENTION", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					Application::Exit();
				}
			}
		}
		// to do check for loop for last cards
		int CheckBluff()
		{
			int won = 0;
			int card;
			for (int i = Table->Count - 1; i >= (Table->Count - lastcards); i--)
			{
				card =   Table[i]->Get_value();
				if (card == current_round)
				{
					won = 1;
				}
				else
				{
					won = 0;
					break;
				}

			}
			return won;
		}
	private: System::Windows::Forms::Button^ BtnPass;
	public:
	private: System::Windows::Forms::Button^ BtnBeluff;
	private: System::Windows::Forms::Button^ BtnFinish;
	private: System::Windows::Forms::PictureBox^ Card2;
	private: System::Windows::Forms::PictureBox^ Card3;
	private: System::Windows::Forms::PictureBox^ Card4;
	private: System::Windows::Forms::PictureBox^ Card5;
	private: System::Windows::Forms::PictureBox^ Card6;
	private: System::Windows::Forms::PictureBox^ Card1;
	private: System::Windows::Forms::PictureBox^ Card7;
	private: System::Windows::Forms::PictureBox^ Card8;
	private: System::Windows::Forms::PictureBox^ Card9;
	private: System::Windows::Forms::PictureBox^ Card10;
	private: System::Windows::Forms::PictureBox^ Card11;
	private: System::Windows::Forms::PictureBox^ Card12;

		   
		
		
	public:Game(List<player^>^ p)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
			Lblgame->Parent = pictureBox1;
			Lblgame->BackColor = Color::Transparent;
			Lblturn->Parent = pictureBox1;
			Lblturn->BackColor = Color::Transparent;
			Lblhand->Parent = pictureBox1;
			Lblhand->BackColor = Color::Transparent;
			Lblevent->Parent = pictureBox1;
			Lblevent->BackColor = Color::Transparent;
			Lbltable->Parent = pictureBox1;
			Lbltable->BackColor = Color::Transparent;
			players = p;
			Lblevent->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ Lblgame;
	private: System::Windows::Forms::Label^ Lblturn;
	private: System::Windows::Forms::Label^ Lblhand;
	private: System::Windows::Forms::Label^ Lbltable;
	private: System::Windows::Forms::Label^ Lblevent;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Lblgame = (gcnew System::Windows::Forms::Label());
			this->Lblturn = (gcnew System::Windows::Forms::Label());
			this->Lblhand = (gcnew System::Windows::Forms::Label());
			this->Lbltable = (gcnew System::Windows::Forms::Label());
			this->Lblevent = (gcnew System::Windows::Forms::Label());
			this->BtnPass = (gcnew System::Windows::Forms::Button());
			this->BtnBeluff = (gcnew System::Windows::Forms::Button());
			this->BtnFinish = (gcnew System::Windows::Forms::Button());
			this->Card2 = (gcnew System::Windows::Forms::PictureBox());
			this->Card3 = (gcnew System::Windows::Forms::PictureBox());
			this->Card4 = (gcnew System::Windows::Forms::PictureBox());
			this->Card5 = (gcnew System::Windows::Forms::PictureBox());
			this->Card6 = (gcnew System::Windows::Forms::PictureBox());
			this->Card1 = (gcnew System::Windows::Forms::PictureBox());
			this->Card7 = (gcnew System::Windows::Forms::PictureBox());
			this->Card8 = (gcnew System::Windows::Forms::PictureBox());
			this->Card9 = (gcnew System::Windows::Forms::PictureBox());
			this->Card10 = (gcnew System::Windows::Forms::PictureBox());
			this->Card11 = (gcnew System::Windows::Forms::PictureBox());
			this->Card12 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->BtnEnd = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card11))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card12))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(947, 709);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Game::pictureBox1_Click);
			// 
			// Lblgame
			// 
			this->Lblgame->AutoSize = true;
			this->Lblgame->BackColor = System::Drawing::Color::Gray;
			this->Lblgame->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblgame->ForeColor = System::Drawing::Color::Gold;
			this->Lblgame->Location = System::Drawing::Point(344, 9);
			this->Lblgame->Name = L"Lblgame";
			this->Lblgame->Size = System::Drawing::Size(254, 37);
			this->Lblgame->TabIndex = 2;
			this->Lblgame->Text = L"BLUFF CARD GAME";
			this->Lblgame->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lblturn
			// 
			this->Lblturn->AutoSize = true;
			this->Lblturn->BackColor = System::Drawing::Color::Gray;
			this->Lblturn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblturn->ForeColor = System::Drawing::Color::Gold;
			this->Lblturn->Location = System::Drawing::Point(12, 96);
			this->Lblturn->Name = L"Lblturn";
			this->Lblturn->Size = System::Drawing::Size(89, 37);
			this->Lblturn->TabIndex = 3;
			this->Lblturn->Text = L"TURN";
			this->Lblturn->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lblhand
			// 
			this->Lblhand->AutoSize = true;
			this->Lblhand->BackColor = System::Drawing::Color::Gray;
			this->Lblhand->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblhand->ForeColor = System::Drawing::Color::Gold;
			this->Lblhand->Location = System::Drawing::Point(12, 151);
			this->Lblhand->Name = L"Lblhand";
			this->Lblhand->Size = System::Drawing::Size(203, 37);
			this->Lblhand->TabIndex = 4;
			this->Lblhand->Text = L"Cards in Hand :";
			this->Lblhand->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lbltable
			// 
			this->Lbltable->AutoSize = true;
			this->Lbltable->BackColor = System::Drawing::Color::Gray;
			this->Lbltable->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lbltable->ForeColor = System::Drawing::Color::Gold;
			this->Lbltable->Location = System::Drawing::Point(12, 200);
			this->Lbltable->Name = L"Lbltable";
			this->Lbltable->Size = System::Drawing::Size(207, 37);
			this->Lbltable->TabIndex = 5;
			this->Lbltable->Text = L"Cards on table :";
			this->Lbltable->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lblevent
			// 
			this->Lblevent->AutoSize = true;
			this->Lblevent->BackColor = System::Drawing::Color::Gray;
			this->Lblevent->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblevent->ForeColor = System::Drawing::Color::Gold;
			this->Lblevent->Location = System::Drawing::Point(208, 52);
			this->Lblevent->Name = L"Lblevent";
			this->Lblevent->Size = System::Drawing::Size(98, 37);
			this->Lblevent->TabIndex = 6;
			this->Lblevent->Text = L"EVENT";
			this->Lblevent->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// BtnPass
			// 
			this->BtnPass->BackColor = System::Drawing::Color::Gold;
			this->BtnPass->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnPass->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnPass->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnPass->Location = System::Drawing::Point(106, 296);
			this->BtnPass->Name = L"BtnPass";
			this->BtnPass->Size = System::Drawing::Size(150, 40);
			this->BtnPass->TabIndex = 7;
			this->BtnPass->Text = L"PASS";
			this->BtnPass->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnPass->UseVisualStyleBackColor = false;
			this->BtnPass->Click += gcnew System::EventHandler(this, &Game::BtnPass_Click);
			// 
			// BtnBeluff
			// 
			this->BtnBeluff->BackColor = System::Drawing::Color::Gold;
			this->BtnBeluff->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnBeluff->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnBeluff->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnBeluff->Location = System::Drawing::Point(397, 296);
			this->BtnBeluff->Name = L"BtnBeluff";
			this->BtnBeluff->Size = System::Drawing::Size(174, 40);
			this->BtnBeluff->TabIndex = 8;
			this->BtnBeluff->Text = L"CHECK BELUFF";
			this->BtnBeluff->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnBeluff->UseVisualStyleBackColor = false;
			this->BtnBeluff->Click += gcnew System::EventHandler(this, &Game::BtnBeluff_Click);
			// 
			// BtnFinish
			// 
			this->BtnFinish->BackColor = System::Drawing::Color::Gold;
			this->BtnFinish->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnFinish->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnFinish->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnFinish->Location = System::Drawing::Point(687, 296);
			this->BtnFinish->Name = L"BtnFinish";
			this->BtnFinish->Size = System::Drawing::Size(150, 40);
			this->BtnFinish->TabIndex = 9;
			this->BtnFinish->Text = L"PLAY TURN";
			this->BtnFinish->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnFinish->UseVisualStyleBackColor = false;
			this->BtnFinish->Click += gcnew System::EventHandler(this, &Game::BtnFinish_Click);
			// 
			// Card2
			// 
			this->Card2->Location = System::Drawing::Point(204, 370);
			this->Card2->Name = L"Card2";
			this->Card2->Size = System::Drawing::Size(100, 132);
			this->Card2->TabIndex = 10;
			this->Card2->TabStop = false;
			this->Card2->Click += gcnew System::EventHandler(this, &Game::Card2_Click);
			// 
			// Card3
			// 
			this->Card3->Location = System::Drawing::Point(349, 370);
			this->Card3->Name = L"Card3";
			this->Card3->Size = System::Drawing::Size(100, 132);
			this->Card3->TabIndex = 11;
			this->Card3->TabStop = false;
			this->Card3->Click += gcnew System::EventHandler(this, &Game::Card3_Click);
			// 
			// Card4
			// 
			this->Card4->Location = System::Drawing::Point(494, 370);
			this->Card4->Name = L"Card4";
			this->Card4->Size = System::Drawing::Size(100, 132);
			this->Card4->TabIndex = 12;
			this->Card4->TabStop = false;
			this->Card4->Click += gcnew System::EventHandler(this, &Game::Card4_Click);
			// 
			// Card5
			// 
			this->Card5->Location = System::Drawing::Point(639, 370);
			this->Card5->Name = L"Card5";
			this->Card5->Size = System::Drawing::Size(100, 132);
			this->Card5->TabIndex = 13;
			this->Card5->TabStop = false;
			this->Card5->Click += gcnew System::EventHandler(this, &Game::Card5_Click);
			// 
			// Card6
			// 
			this->Card6->Location = System::Drawing::Point(784, 370);
			this->Card6->Name = L"Card6";
			this->Card6->Size = System::Drawing::Size(100, 132);
			this->Card6->TabIndex = 14;
			this->Card6->TabStop = false;
			this->Card6->Click += gcnew System::EventHandler(this, &Game::Card6_Click);
			// 
			// Card1
			// 
			this->Card1->Location = System::Drawing::Point(59, 370);
			this->Card1->Name = L"Card1";
			this->Card1->Size = System::Drawing::Size(100, 132);
			this->Card1->TabIndex = 15;
			this->Card1->TabStop = false;
			this->Card1->Click += gcnew System::EventHandler(this, &Game::Card1_Click);
			// 
			// Card7
			// 
			this->Card7->Location = System::Drawing::Point(59, 542);
			this->Card7->Name = L"Card7";
			this->Card7->Size = System::Drawing::Size(100, 132);
			this->Card7->TabIndex = 16;
			this->Card7->TabStop = false;
			this->Card7->Click += gcnew System::EventHandler(this, &Game::Card7_Click);
			// 
			// Card8
			// 
			this->Card8->Location = System::Drawing::Point(204, 542);
			this->Card8->Name = L"Card8";
			this->Card8->Size = System::Drawing::Size(100, 132);
			this->Card8->TabIndex = 17;
			this->Card8->TabStop = false;
			this->Card8->Click += gcnew System::EventHandler(this, &Game::Card8_Click);
			// 
			// Card9
			// 
			this->Card9->Location = System::Drawing::Point(351, 542);
			this->Card9->Name = L"Card9";
			this->Card9->Size = System::Drawing::Size(100, 132);
			this->Card9->TabIndex = 18;
			this->Card9->TabStop = false;
			this->Card9->Click += gcnew System::EventHandler(this, &Game::Card9_Click);
			// 
			// Card10
			// 
			this->Card10->Location = System::Drawing::Point(494, 542);
			this->Card10->Name = L"Card10";
			this->Card10->Size = System::Drawing::Size(100, 132);
			this->Card10->TabIndex = 19;
			this->Card10->TabStop = false;
			this->Card10->Click += gcnew System::EventHandler(this, &Game::Card10_Click);
			// 
			// Card11
			// 
			this->Card11->Location = System::Drawing::Point(639, 542);
			this->Card11->Name = L"Card11";
			this->Card11->Size = System::Drawing::Size(100, 132);
			this->Card11->TabIndex = 20;
			this->Card11->TabStop = false;
			this->Card11->Click += gcnew System::EventHandler(this, &Game::Card11_Click);
			// 
			// Card12
			// 
			this->Card12->Location = System::Drawing::Point(784, 542);
			this->Card12->Name = L"Card12";
			this->Card12->Size = System::Drawing::Size(100, 132);
			this->Card12->TabIndex = 21;
			this->Card12->TabStop = false;
			this->Card12->Click += gcnew System::EventHandler(this, &Game::Card12_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Highlight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label1->Location = System::Drawing::Point(66, 428);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 20);
			this->label1->TabIndex = 22;
			this->label1->Text = L"ON TABLE";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::Highlight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label2->Location = System::Drawing::Point(211, 428);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 20);
			this->label2->TabIndex = 23;
			this->label2->Text = L"ON TABLE";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::Highlight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label3->Location = System::Drawing::Point(356, 428);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 20);
			this->label3->TabIndex = 24;
			this->label3->Text = L"ON TABLE";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::Highlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label4->Location = System::Drawing::Point(501, 428);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 20);
			this->label4->TabIndex = 25;
			this->label4->Text = L"ON TABLE";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::Highlight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label5->Location = System::Drawing::Point(646, 428);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 20);
			this->label5->TabIndex = 26;
			this->label5->Text = L"ON TABLE";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::Highlight;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label6->Location = System::Drawing::Point(792, 428);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 20);
			this->label6->TabIndex = 27;
			this->label6->Text = L"ON TABLE";
			this->label6->Click += gcnew System::EventHandler(this, &Game::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::SystemColors::Highlight;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label7->Location = System::Drawing::Point(66, 601);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 20);
			this->label7->TabIndex = 28;
			this->label7->Text = L"ON TABLE";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::SystemColors::Highlight;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label8->Location = System::Drawing::Point(211, 601);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(87, 20);
			this->label8->TabIndex = 29;
			this->label8->Text = L"ON TABLE";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::SystemColors::Highlight;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label9->Location = System::Drawing::Point(356, 601);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 20);
			this->label9->TabIndex = 30;
			this->label9->Text = L"ON TABLE";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::SystemColors::Highlight;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label10->Location = System::Drawing::Point(501, 601);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(87, 20);
			this->label10->TabIndex = 31;
			this->label10->Text = L"ON TABLE";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::SystemColors::Highlight;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label11->Location = System::Drawing::Point(646, 601);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(87, 20);
			this->label11->TabIndex = 32;
			this->label11->Text = L"ON TABLE";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::SystemColors::Highlight;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::AntiqueWhite;
			this->label12->Location = System::Drawing::Point(792, 601);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(87, 20);
			this->label12->TabIndex = 33;
			this->label12->Text = L"ON TABLE";
			// 
			// BtnEnd
			// 
			this->BtnEnd->BackColor = System::Drawing::Color::Gold;
			this->BtnEnd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnEnd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnEnd->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnEnd->Location = System::Drawing::Point(770, -1);
			this->BtnEnd->Name = L"BtnEnd";
			this->BtnEnd->Size = System::Drawing::Size(174, 40);
			this->BtnEnd->TabIndex = 34;
			this->BtnEnd->Text = L"END GAME";
			this->BtnEnd->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnEnd->UseVisualStyleBackColor = false;
			this->BtnEnd->Click += gcnew System::EventHandler(this, &Game::BtnEnd_Click);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(943, 709);
			this->ControlBox = false;
			this->Controls->Add(this->BtnEnd);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Card12);
			this->Controls->Add(this->Card11);
			this->Controls->Add(this->Card10);
			this->Controls->Add(this->Card9);
			this->Controls->Add(this->Card8);
			this->Controls->Add(this->Card7);
			this->Controls->Add(this->Card1);
			this->Controls->Add(this->Card6);
			this->Controls->Add(this->Card5);
			this->Controls->Add(this->Card4);
			this->Controls->Add(this->Card3);
			this->Controls->Add(this->Card2);
			this->Controls->Add(this->BtnFinish);
			this->Controls->Add(this->BtnBeluff);
			this->Controls->Add(this->BtnPass);
			this->Controls->Add(this->Lblevent);
			this->Controls->Add(this->Lbltable);
			this->Controls->Add(this->Lblhand);
			this->Controls->Add(this->Lblturn);
			this->Controls->Add(this->Lblgame);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card11))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Card12))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) 
	
	{
		Cards_being_played = gcnew List<Card^>();
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		label5->Visible = false;
		label6->Visible = false;
		label7->Visible = false;
		label8->Visible = false;
		label9->Visible = false;
		label10->Visible = false;
		label11->Visible = false;
		label12->Visible = false;
		Lblturn->Text = players[0]->Get_name()->ToString() + "'s turn";
		Deck = game.InitializeDeck();
		Deck = game.Shuffle(Deck);
		players = game.Distribute(players, Deck);
		player_cards = players[current]->GetCards();
		
		game = gcnew Bluff(players[0],0,players->Count);
		
		
		Card1->Visible = false;
		Card2->Visible = false;
		Card3->Visible = false;
		Card4->Visible = false;
		Card5->Visible = false;
		Card6->Visible = false;
		Card7->Visible = false;
		Card8->Visible = false;
		Card9->Visible = false;
		Card10->Visible = false;
		Card11->Visible = false;
		Card12->Visible = false;
		ShowCards();


		
        
		Lblhand->Text = "Cards in Hand :  " + players[current]->GetCards()->Count;
		Lbltable->Text = "Cards on Table : 0";
	
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void BtnPass_Click(System::Object^ sender, System::EventArgs^ e) 
{
	label1->Visible = false;
	label2->Visible = false;
	label3->Visible = false;
	label4->Visible = false;
	label5->Visible = false;
	label6->Visible = false;
	label7->Visible = false;
	label8->Visible = false;
	label9->Visible = false;
	label10->Visible = false;
	label11->Visible = false;
	label12->Visible = false;
	current++;
	if(current >= players->Count)
	{
		current = 0;
	}
	game.Next_Turn(players[current]);
	Lblturn->Text = players[current]->Get_name() + "'s turn";
	Lblhand->Text = "Cards in Hand :  " + players[current]->GetCards()->Count;
	player_cards = players[current]->GetCards();
	ShowCards();
	Cards_being_played = gcnew List<Card^>();
	
	
}
private: System::Void Card1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if(label1->Visible == false)
	{
		
		label1->Visible = true;
		Cards_being_played->Add(player_cards[0]);
		if(Table->Count==0 && Cards_being_played->Count==1 && Cards_being_played->Count==0)
		{
			current_round = player_cards[0]->Get_value();
		}
		
	}
	else {
		label1->Visible = false;
		Cards_being_played->Remove(player_cards[0]);
	}
	
	
}
private: System::Void Card2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label2->Visible == false)
	{
		label2->Visible = true;
		Cards_being_played->Add(player_cards[1]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[1]->Get_value();
		}
	}
	else {
		label2->Visible = false;
		Cards_being_played->Remove(player_cards[1]);
	}
}
private: System::Void Card3_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label3->Visible == false)
	{
		label3->Visible = true;
		Cards_being_played->Add(player_cards[2]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[2]->Get_value();
		}
	}
	else {
		label3->Visible = false;
		Cards_being_played->Remove(player_cards[2]);
	}
}
private: System::Void Card4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label4->Visible == false)
	{
		label4->Visible = true;
		Cards_being_played->Add(player_cards[3]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[3]->Get_value();
		}
	}
	else {
		label4->Visible = false;
		Cards_being_played->Remove(player_cards[3]);
	}
}
private: System::Void Card5_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label5->Visible == false)
	{
		label5->Visible = true;
		Cards_being_played->Add(player_cards[4]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[4]->Get_value();
		}
	}
	else {
		label5->Visible = false;
		Cards_being_played->Remove(player_cards[4]);
	}
}
private: System::Void Card6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label6->Visible == false)
	{
		label6->Visible = true;
		Cards_being_played->Add(player_cards[5]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[5]->Get_value();
		}
	}
	else {
		label6->Visible = false;
		Cards_being_played->Remove(player_cards[5]);
	}
}
private: System::Void Card7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label7->Visible == false)
	{
		label7->Visible = true;
		Cards_being_played->Add(player_cards[6]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[6]->Get_value();
		}
	}
	else {
		label7->Visible = false;
		Cards_being_played->Remove(player_cards[6]);
	}
}
private: System::Void Card8_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label8->Visible == false)
	{
		label8->Visible = true;
		Cards_being_played->Add(player_cards[7]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[7]->Get_value();
		}
	}
	else {
		label8->Visible = false;
		Cards_being_played->Remove(player_cards[7]);
	}
}
private: System::Void Card9_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label9->Visible == false)
	{
		label9->Visible = true;
		Cards_being_played->Add(player_cards[8]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[8]->Get_value();
		}
	}
	else {
		label9->Visible = false;
		Cards_being_played->Remove(player_cards[8]);
	}
}
private: System::Void Card10_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label10->Visible == false)
	{
		label10->Visible = true;
		Cards_being_played->Add(player_cards[9]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[9]->Get_value();
		}
	}
	else {
		label10->Visible = false;
		Cards_being_played->Remove(player_cards[9]);
	}
}
private: System::Void Card11_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label11->Visible == false)
	{
		label11->Visible = true;
		Cards_being_played->Add(player_cards[10]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[10]->Get_value();
		}
	}
	else {
		label11->Visible = false;
		Cards_being_played->Remove(player_cards[10]);
	}
}
private: System::Void Card12_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (label12->Visible == false)
	{
		label12->Visible = true;
		Cards_being_played->Add(player_cards[11]);
		if (Table->Count==0 && Cards_being_played->Count==1) {
			current_round = player_cards[11]->Get_value();
		}
	}
	else {
		label12->Visible = false;
		Cards_being_played->Remove(player_cards[11]);
	}
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BtnFinish_Click(System::Object^ sender, System::EventArgs^ e) 
{
	try
	{

	
	
	if(cards_on_table==0 && Cards_being_played->Count < 2)
	{
		//MessageBox::Show("You must play 2 cards as you are starting the round!! You may pass too");
		err = gcnew InvalidPlay();
		throw err;
	}
	else if(Cards_being_played->Count <1)
	{
		//MessageBox::Show("Play atleast one card or you may Pass!!");
		err = gcnew InvalidMoveExecption();
		throw err;
	}
	else
	{
		lastPlayed = current;
		lastcards = Cards_being_played->Count;
		for(int i=0;i<Cards_being_played->Count;i++)
		{
			Table->Add(Cards_being_played[i]);
			players[current]->RemoveCard(Cards_being_played[i]);
			cards_on_table++;
			
		}
		label1->Visible = false;
		label2->Visible = false;
		label3->Visible = false;
		label4->Visible = false;
		label5->Visible = false;
		label6->Visible = false;
		label7->Visible = false;
		label8->Visible = false;
		label9->Visible = false;
		label10->Visible = false;
		label11->Visible = false;
		label12->Visible = false;
		current++;
		if (current >= players->Count)
		{
			current = 0;
		}
		
		game.Next_Turn(players[current]);
		Lblturn->Text = players[current]->Get_name() + "'s turn";
		Lblhand->Text = "Cards in Hand :  " + players[current]->GetCards()->Count;
		player_cards = players[current]->GetCards();
		ShowCards();
		Cards_being_played = gcnew List<Card^>();
		Lbltable->Text = "Cards on table: " + cards_on_table;
		String^ r;
		if (current_round == 10) {
			r = "J";
		}
		else if (current_round == 11) {
			r = "Q";
		}
		else if (current_round == 12) {
			r = "K";
		}
		else if (current_round == 13) {
			r = "A";
		}
		else {
			r = (current_round + 1).ToString();
		}
		
		Lblevent->Text = players[lastPlayed]->Get_name() + " added " + lastcards + " cards for current round of " + r +" on table ";
		Lblevent->Visible = true;
	  }
	}
	catch (MyException^ ex)
	{
		MessageBox::Show(ex->Get_message(), "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void BtnBeluff_Click(System::Object^ sender, System::EventArgs^ e) 

{
	try
	{

	
	if(current==lastPlayed)
	{
		//MessageBox::Show("You cannot check your own card !! ");
		err = gcnew InvalidBluffException();
		throw err;
	}
	else {
		if (CheckBluff() == 1)
		{
			MessageBox::Show(players[current]->Get_name() + " lost the bluff against " + players[lastPlayed]->Get_name() + " and " + players[current]->Get_name() + " will pick all the cards from table!!!");
			Lblevent->Text = players[current]->Get_name() + " lost the bluff against " + players[lastPlayed]->Get_name();
			Lblevent->Visible = true;


			PickCards(current);
			cards_on_table = 0;
			Table = gcnew List<Card^>();
			current = lastPlayed;
			Lbltable->Text = "Cards on table : " + cards_on_table;
			game.Next_Turn(players[current]);
			Lblturn->Text = players[current]->Get_name() + "'s turn";
			Lblhand->Text = "Cards in Hand :  " + players[current]->GetCards()->Count;
			player_cards = players[current]->GetCards();
			ShowCards();
			Cards_being_played = gcnew List<Card^>();

		}
		else
		{
			MessageBox::Show(players[current]->Get_name() + " won the bluff against " + players[lastPlayed]->Get_name() + " and " + players[lastPlayed]->Get_name() + " will pick all the cards from table!!!");
			Lblevent->Text = players[current]->Get_name() + " won the bluff against " + players[lastPlayed]->Get_name();
			Lblevent->Visible = true;
			PickCards(lastPlayed);
			cards_on_table = 0;
			Table = gcnew List<Card^>();
			Lbltable->Text = "Cards on table : " + cards_on_table;
			Cards_being_played = gcnew List<Card^>();
		}
		Check_Winner();
		
	}

	}
	catch (MyException^ ex)
	{
		MessageBox::Show(ex->Get_message(), "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}
private: System::Void BtnEnd_Click(System::Object^ sender, System::EventArgs^ e) 
{
	System::Windows::Forms::DialogResult result = MessageBox::Show("Are you sure you want to end the game, all progress would be lost ? ", "Attention", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes )
	{
		Application::Exit();
	}



}
};
}
