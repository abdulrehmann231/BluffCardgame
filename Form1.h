#pragma once

#include <string>
#include "Player.h"
#include "Game.h"
#include "MyException.h"
#include "InvalidUserNumberException.h"
#include "MissingDetailsException.h"


namespace CppCLR_WinformsProject1 {

	
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		MyException^ err;
		Form1(void)
		{
			InitializeComponent();
			LblWelcome->Parent =  PbBackground;
			LblWelcome->BackColor = Color::Transparent;
			//
			//TODO: Add the constructor code here
			// 
			
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ PbBackground;
	protected:
	private: System::Windows::Forms::Label^ LblWelcome;
	private: System::Windows::Forms::Label^ Lblplayers;
	private: System::Windows::Forms::TextBox^ TxtNum;
	private: System::Windows::Forms::Button^ BtnHome;
	private: System::Windows::Forms::Button^ BtnExit;
	private: System::Windows::Forms::TextBox^ TxtName1;

	private: System::Windows::Forms::Label^ Lblname1;
	private: System::Windows::Forms::TextBox^ TxtName2;


	private: System::Windows::Forms::Label^ LblName2;
	private: System::Windows::Forms::TextBox^ TxtName3;


	private: System::Windows::Forms::Label^ LblName3;
	private: System::Windows::Forms::TextBox^ TxtName4;


	private: System::Windows::Forms::Label^ LblName4;
	private: System::Windows::Forms::TextBox^ TxtName6;


	private: System::Windows::Forms::Label^ Lblname6;

	private: System::Windows::Forms::TextBox^ TxtName5;

	private: System::Windows::Forms::Label^ LblName5;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->PbBackground = (gcnew System::Windows::Forms::PictureBox());
			this->LblWelcome = (gcnew System::Windows::Forms::Label());
			this->Lblplayers = (gcnew System::Windows::Forms::Label());
			this->TxtNum = (gcnew System::Windows::Forms::TextBox());
			this->BtnHome = (gcnew System::Windows::Forms::Button());
			this->BtnExit = (gcnew System::Windows::Forms::Button());
			this->TxtName1 = (gcnew System::Windows::Forms::TextBox());
			this->Lblname1 = (gcnew System::Windows::Forms::Label());
			this->TxtName2 = (gcnew System::Windows::Forms::TextBox());
			this->LblName2 = (gcnew System::Windows::Forms::Label());
			this->TxtName3 = (gcnew System::Windows::Forms::TextBox());
			this->LblName3 = (gcnew System::Windows::Forms::Label());
			this->TxtName4 = (gcnew System::Windows::Forms::TextBox());
			this->LblName4 = (gcnew System::Windows::Forms::Label());
			this->TxtName6 = (gcnew System::Windows::Forms::TextBox());
			this->Lblname6 = (gcnew System::Windows::Forms::Label());
			this->TxtName5 = (gcnew System::Windows::Forms::TextBox());
			this->LblName5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PbBackground))->BeginInit();
			this->SuspendLayout();
			// 
			// PbBackground
			// 
			this->PbBackground->BackColor = System::Drawing::Color::Gold;
			this->PbBackground->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PbBackground.Image")));
			this->PbBackground->Location = System::Drawing::Point(-12, -1);
			this->PbBackground->Name = L"PbBackground";
			this->PbBackground->Size = System::Drawing::Size(798, 549);
			this->PbBackground->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PbBackground->TabIndex = 0;
			this->PbBackground->TabStop = false;
			this->PbBackground->Click += gcnew System::EventHandler(this, &Form1::PbBackground_Click);
			// 
			// LblWelcome
			// 
			this->LblWelcome->AutoSize = true;
			this->LblWelcome->BackColor = System::Drawing::Color::Gray;
			this->LblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblWelcome->ForeColor = System::Drawing::Color::Gold;
			this->LblWelcome->Location = System::Drawing::Point(284, 9);
			this->LblWelcome->Name = L"LblWelcome";
			this->LblWelcome->Size = System::Drawing::Size(217, 37);
			this->LblWelcome->TabIndex = 1;
			this->LblWelcome->Text = L"WELCOME USER";
			this->LblWelcome->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Lblplayers
			// 
			this->Lblplayers->AutoSize = true;
			this->Lblplayers->BackColor = System::Drawing::Color::Gray;
			this->Lblplayers->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblplayers->ForeColor = System::Drawing::Color::Gold;
			this->Lblplayers->Location = System::Drawing::Point(12, 59);
			this->Lblplayers->Name = L"Lblplayers";
			this->Lblplayers->Size = System::Drawing::Size(254, 30);
			this->Lblplayers->TabIndex = 2;
			this->Lblplayers->Text = L"Enter number of Players :";
			this->Lblplayers->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtNum
			// 
			this->TxtNum->Location = System::Drawing::Point(12, 100);
			this->TxtNum->Name = L"TxtNum";
			this->TxtNum->Size = System::Drawing::Size(201, 20);
			this->TxtNum->TabIndex = 3;
			this->TxtNum->TextChanged += gcnew System::EventHandler(this, &Form1::TxtNum_TextChanged);
			// 
			// BtnHome
			// 
			this->BtnHome->BackColor = System::Drawing::Color::Gold;
			this->BtnHome->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnHome->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnHome->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnHome->Location = System::Drawing::Point(492, 497);
			this->BtnHome->Name = L"BtnHome";
			this->BtnHome->Size = System::Drawing::Size(131, 40);
			this->BtnHome->TabIndex = 4;
			this->BtnHome->Text = L"NEXT";
			this->BtnHome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnHome->UseVisualStyleBackColor = false;
			this->BtnHome->Click += gcnew System::EventHandler(this, &Form1::BtnHome_Click);
			// 
			// BtnExit
			// 
			this->BtnExit->BackColor = System::Drawing::Color::Gold;
			this->BtnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BtnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BtnExit->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnExit->Location = System::Drawing::Point(684, -1);
			this->BtnExit->Name = L"BtnExit";
			this->BtnExit->Size = System::Drawing::Size(102, 40);
			this->BtnExit->TabIndex = 5;
			this->BtnExit->Text = L"EXIT";
			this->BtnExit->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->BtnExit->UseVisualStyleBackColor = false;
			this->BtnExit->Click += gcnew System::EventHandler(this, &Form1::BtnExit_Click);
			// 
			// TxtName1
			// 
			this->TxtName1->Location = System::Drawing::Point(12, 100);
			this->TxtName1->Name = L"TxtName1";
			this->TxtName1->Size = System::Drawing::Size(201, 20);
			this->TxtName1->TabIndex = 7;
			// 
			// Lblname1
			// 
			this->Lblname1->AutoSize = true;
			this->Lblname1->BackColor = System::Drawing::Color::Gray;
			this->Lblname1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblname1->ForeColor = System::Drawing::Color::Gold;
			this->Lblname1->Location = System::Drawing::Point(12, 59);
			this->Lblname1->Name = L"Lblname1";
			this->Lblname1->Size = System::Drawing::Size(238, 30);
			this->Lblname1->TabIndex = 6;
			this->Lblname1->Text = L"Enter name of player 1 :";
			this->Lblname1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtName2
			// 
			this->TxtName2->Location = System::Drawing::Point(12, 172);
			this->TxtName2->Name = L"TxtName2";
			this->TxtName2->Size = System::Drawing::Size(201, 20);
			this->TxtName2->TabIndex = 9;
			// 
			// LblName2
			// 
			this->LblName2->AutoSize = true;
			this->LblName2->BackColor = System::Drawing::Color::Gray;
			this->LblName2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblName2->ForeColor = System::Drawing::Color::Gold;
			this->LblName2->Location = System::Drawing::Point(12, 131);
			this->LblName2->Name = L"LblName2";
			this->LblName2->Size = System::Drawing::Size(242, 30);
			this->LblName2->TabIndex = 8;
			this->LblName2->Text = L"Enter name of player 2 :";
			this->LblName2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtName3
			// 
			this->TxtName3->Location = System::Drawing::Point(12, 244);
			this->TxtName3->Name = L"TxtName3";
			this->TxtName3->Size = System::Drawing::Size(201, 20);
			this->TxtName3->TabIndex = 11;
			// 
			// LblName3
			// 
			this->LblName3->AutoSize = true;
			this->LblName3->BackColor = System::Drawing::Color::Gray;
			this->LblName3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblName3->ForeColor = System::Drawing::Color::Gold;
			this->LblName3->Location = System::Drawing::Point(12, 203);
			this->LblName3->Name = L"LblName3";
			this->LblName3->Size = System::Drawing::Size(242, 30);
			this->LblName3->TabIndex = 10;
			this->LblName3->Text = L"Enter name of player 3 :";
			this->LblName3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtName4
			// 
			this->TxtName4->Location = System::Drawing::Point(12, 316);
			this->TxtName4->Name = L"TxtName4";
			this->TxtName4->Size = System::Drawing::Size(201, 20);
			this->TxtName4->TabIndex = 13;
			// 
			// LblName4
			// 
			this->LblName4->AutoSize = true;
			this->LblName4->BackColor = System::Drawing::Color::Gray;
			this->LblName4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblName4->ForeColor = System::Drawing::Color::Gold;
			this->LblName4->Location = System::Drawing::Point(12, 275);
			this->LblName4->Name = L"LblName4";
			this->LblName4->Size = System::Drawing::Size(242, 30);
			this->LblName4->TabIndex = 12;
			this->LblName4->Text = L"Enter name of player 4 :";
			this->LblName4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtName6
			// 
			this->TxtName6->Location = System::Drawing::Point(12, 460);
			this->TxtName6->Name = L"TxtName6";
			this->TxtName6->Size = System::Drawing::Size(201, 20);
			this->TxtName6->TabIndex = 15;
			// 
			// Lblname6
			// 
			this->Lblname6->AutoSize = true;
			this->Lblname6->BackColor = System::Drawing::Color::Gray;
			this->Lblname6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Lblname6->ForeColor = System::Drawing::Color::Gold;
			this->Lblname6->Location = System::Drawing::Point(7, 419);
			this->Lblname6->Name = L"Lblname6";
			this->Lblname6->Size = System::Drawing::Size(242, 30);
			this->Lblname6->TabIndex = 14;
			this->Lblname6->Text = L"Enter name of player 6 :";
			this->Lblname6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TxtName5
			// 
			this->TxtName5->Location = System::Drawing::Point(12, 388);
			this->TxtName5->Name = L"TxtName5";
			this->TxtName5->Size = System::Drawing::Size(201, 20);
			this->TxtName5->TabIndex = 17;
			// 
			// LblName5
			// 
			this->LblName5->AutoSize = true;
			this->LblName5->BackColor = System::Drawing::Color::Gray;
			this->LblName5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LblName5->ForeColor = System::Drawing::Color::Gold;
			this->LblName5->Location = System::Drawing::Point(7, 347);
			this->LblName5->Name = L"LblName5";
			this->LblName5->Size = System::Drawing::Size(242, 30);
			this->LblName5->TabIndex = 16;
			this->LblName5->Text = L"Enter name of player 5 :";
			this->LblName5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(785, 549);
			this->ControlBox = false;
			this->Controls->Add(this->TxtName5);
			this->Controls->Add(this->LblName5);
			this->Controls->Add(this->TxtName6);
			this->Controls->Add(this->Lblname6);
			this->Controls->Add(this->TxtName4);
			this->Controls->Add(this->LblName4);
			this->Controls->Add(this->TxtName3);
			this->Controls->Add(this->LblName3);
			this->Controls->Add(this->TxtName2);
			this->Controls->Add(this->LblName2);
			this->Controls->Add(this->TxtName1);
			this->Controls->Add(this->Lblname1);
			this->Controls->Add(this->BtnExit);
			this->Controls->Add(this->BtnHome);
			this->Controls->Add(this->TxtNum);
			this->Controls->Add(this->Lblplayers);
			this->Controls->Add(this->LblWelcome);
			this->Controls->Add(this->PbBackground);
			this->Name = L"Form1";
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PbBackground))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TxtNum_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}
    private: System::Void BtnHome_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		try
		{

		
		List<player^>^ Current_player;
		if(TxtNum->Text == "")
		{
			//MessageBox::Show("Please enter valid number of players (Min : 3 , Max : 6) ", "ERROR",MessageBoxButtons::OK,MessageBoxIcon::Error);
			   err = gcnew InvalidUserNumberException();
			   throw err;
		}
		else
		{
			String^ players = TxtNum->Text;
			for each (char c in players)
			{
				if (!Char::IsDigit(c))
				{
					// Display an error message if the input contains non-numeric characters
					//MessageBox::Show("Please enter valid number of players (Min : 3 , Max : 6) ", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
					// Clear the textbox to prevent invalid input
					err = gcnew InvalidUserNumberException();
					throw err;
					TxtNum->Text = "";
					return;
				}
			}
			int plays = int::Parse(players);
			if(plays >= 3 && plays < 7)
			{
				//List<player^>^ Current_player;
				Current_player = gcnew List<player^> () ;
				Lblplayers->Visible = false;
				TxtNum->Visible = false;
				Lblname1->Visible = true;
				LblName2->Visible = true;
				LblName3->Visible = true;
				TxtName1->Visible = true;
				TxtName2->Visible = true;
				TxtName3->Visible = true;
				if(plays >3)
				{
					LblName4->Visible = true;
					TxtName4->Visible = true;
				}
				if(plays>4)
				{
					LblName5->Visible = true;
					TxtName5->Visible = true;
				}
				if(plays>5)
				{
					Lblname6->Visible = true;
					TxtName6->Visible = true;
				}
				 
				
				
				

			}
			else
			{
				//MessageBox::Show("Please enter valid number of players (Min : 3 , Max : 6) ", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
				err = gcnew InvalidUserNumberException();
				throw err;
			}
			
			if (BtnHome->Text == "PLAY")
			{
				if(TxtName1->Text=="" || TxtName2->Text==""|| TxtName3->Text=="")
				{
					//MessageBox::Show("Enter all details", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err = gcnew MissingDetailsException();
					throw err;
					
				}
				if(plays>3 && TxtName4->Text=="")
				{
					//MessageBox::Show("Enter all details", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err = gcnew MissingDetailsException();
					throw err;
				}
				if (plays > 4 && TxtName5->Text == "")
				{
					//MessageBox::Show("Enter all details", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err = gcnew MissingDetailsException();
					throw err;
				}
				if (plays > 5 && TxtName6->Text == "")
				{
					//MessageBox::Show("Enter all details", "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
					err = gcnew MissingDetailsException();
					throw err;
				}
				if (TxtName1->Visible && TxtName1 != nullptr) // Check if TxtName1 is not null
				{
					player^ p= gcnew player(TxtName1->Text);
					Current_player->Add(p);
				}
					//Current_player->Add(gcnew player(TxtName1->Text));
				if (TxtName2->Visible && TxtName2 != nullptr) // Check if TxtName2 is not null
					Current_player->Add(gcnew player(TxtName2->Text));
				if (TxtName3->Visible && TxtName3 != nullptr) // Check if TxtName3 is not null
					Current_player->Add(gcnew player(TxtName3->Text));
				if (TxtName4->Visible && TxtName4 != nullptr) // Check if TxtName4 is not null
					Current_player->Add(gcnew player(TxtName4->Text));
				if (TxtName5->Visible && TxtName5 != nullptr) // Check if TxtName5 is not null
					Current_player->Add(gcnew player(TxtName5->Text));
				if (TxtName6->Visible && TxtName6 != nullptr) // Check if TxtName6 is not null
					Current_player->Add(gcnew player(TxtName6->Text));
				
				this->Hide();
				Game^ form2 = gcnew Game(Current_player);
				form2->Show();
				
			}
			BtnHome->Text = "PLAY";
		}

		

		}
		catch (MyException^ ex)
		{
			MessageBox::Show(ex->Get_message(),"ERROR",MessageBoxButtons::OK, MessageBoxIcon::Error);
		
		}
    }
private: System::Void BtnExit_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Application::Exit();

}
private: System::Void PbBackground_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) 
{
	Lblname1->Visible = false;
	LblName2->Visible = false;
	LblName3->Visible = false;
	LblName4->Visible = false;
	LblName5->Visible = false;
	Lblname6->Visible = false;
	TxtName1->Visible = false;
	TxtName2->Visible = false;
	TxtName3->Visible = false;
	TxtName4->Visible = false;
	TxtName5->Visible = false;
	TxtName6->Visible = false;

	
}
};
}
