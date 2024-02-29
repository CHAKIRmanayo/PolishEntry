#pragma once
#include "my_stack.h"
#include "my_queue.h"
#include "my_lexems.h"

namespace PolishEntry {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		char*  s1;
		MyQueue* q;
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			s1=new char[0];
			q = new MyQueue[1];
			*q = initMyQueue();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  tb1;
	protected: 


	private: System::Windows::Forms::Button^  btnC;
	private: 
	private: Double  lnew;
	private: System::Windows::Forms::Label^  lblErr;
	private: System::Windows::Forms::Label^  lblLexems;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnOK;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lbl3;




	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{

			this->tb1 = (gcnew System::Windows::Forms::TextBox());
			this->btnC = (gcnew System::Windows::Forms::Button());
			this->lblErr = (gcnew System::Windows::Forms::Label());
			this->lblLexems = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lbl3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tb1
			// 
			this->tb1->Location = System::Drawing::Point(37, 32);
			this->tb1->Name = L"tb1";
			this->tb1->Size = System::Drawing::Size(615, 22);
			this->tb1->TabIndex = 0;
			this->tb1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// btnC
			// 
			this->btnC->Location = System::Drawing::Point(446, 298);
			this->btnC->Name = L"btnC";
			this->btnC->Size = System::Drawing::Size(155, 72);
			this->btnC->TabIndex = 2;
			this->btnC->Text = L"C";
			this->btnC->UseVisualStyleBackColor = true;
			this->btnC->Click += gcnew System::EventHandler(this, &MyForm::btnC_Click);
			// 
			// lblErr
			// 
			this->lblErr->AutoSize = true;
			this->lblErr->Location = System::Drawing::Point(79, 86);
			this->lblErr->Name = L"lblErr";
			this->lblErr->Size = System::Drawing::Size(0, 17);
			this->lblErr->TabIndex = 3;
			// 
			// lblLexems
			// 
			this->lblLexems->AutoSize = true;
			this->lblLexems->Location = System::Drawing::Point(79, 168);
			this->lblLexems->Name = L"lblLexems";
			this->lblLexems->Size = System::Drawing::Size(87, 17);
			this->lblLexems->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(79, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Lexems:";
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(82, 298);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(156, 72);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"=";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &MyForm::btnOK_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(79, 194);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"PolishEntry:";
			// 
			// label3
			// 
			this->lbl3->AutoSize = true;
			this->lbl3->Location = System::Drawing::Point(79, 232);
			this->lbl3->Name = L"label3";
			this->lbl3->Size = System::Drawing::Size(0, 17);
			this->lbl3->TabIndex = 7;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(662, 423);
			this->Controls->Add(this->lbl3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblLexems);
			this->Controls->Add(this->lblErr);
			this->Controls->Add(this->btnC);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->tb1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	char* convertStringToChar(String^ path){
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(path).ToPointer();
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (tb1->Text->Length == 0) {
			s1 = new char[0];
		}
		if (tb1->Text->Length > 0 && tb1->Text[tb1->Text->Length - 1] == ' ') {
			tb1->Text = tb1->Text->Remove(tb1->Text->Length - 1);
			tb1->SelectionStart = tb1->Text->Length;
		}
		if (testBrackets(convertStringToChar(tb1->Text)))
			lblErr->Text = "Error brackets";
		else
			lblErr->Text = "";
		correctSTR(convertStringToChar(tb1->Text));
		if (lblErr->Text == "")
			sepLexem(convertStringToChar(tb1->Text));
	}

	void correctSTR(char* s){
		int i, pos2, save1, save2;
		int b = 0;
		int pos1 = testStr(s, s1, &i, &pos2);
		while (isCurr(pos1)) {
			save1 = pos1;
			save2 = pos2;
			s = corrStr(s, pos1, i);
			s1 = new char[strlen(s)];
			strcpy(s1, s);
			b++;
			pos1 = testStr(s, s1, &i, &pos2);
		}
		if (b > 0) {
			tb1->Text = gcnew String(s);
			tb1->SelectionStart = save1 + save2;
		}
		else {
			s1 = new char[strlen(s)];
			strcpy(s1, s);
		}
	}

	void sepLexem(char* s) {

		int t = 0;
		*q = sepLexem1(s, &t);
		Iterator i = begin(*q);
		lblLexems->Text = "";
		if (hasCurrent(i))
		{
			while (hasCurrent(i))
			{
				String^ w = gcnew String(get(i));
				lblLexems->Text = lblLexems->Text + Convert::ToString(" ") + w + Convert::ToString("  ");
				moveNext(i);
			}
		}
		if (t == 0) {
			*q = reRecord(*q);
			i = begin(*q);
			lbl3->Text = "";
			if (hasCurrent(i))
			{
				while (hasCurrent(i))
				{
					String^ w = gcnew String(get(i));
					lbl3->Text = lbl3->Text + Convert::ToString(" ") + w + Convert::ToString("  ");
					moveNext(i);
				}
			}
		}
	}

	private: System::Void btnOK_Click(System::Object^  sender, System::EventArgs^  e) {

		if (lblErr->Text == "Error brackets")
			MessageBox::Show("Error");
		if (lblErr->Text == "") {
			lblErr->Text = Convert::ToString(calcul(*q));


		}

	}
	private: System::Void btnC_Click(System::Object^  sender, System::EventArgs^  e) {

		tb1->Text = "";
		tb1->Focus();
	}
	};
}
