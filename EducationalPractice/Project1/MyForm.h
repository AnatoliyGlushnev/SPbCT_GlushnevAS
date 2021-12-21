#pragma once
#include <fstream>
#include <cstdlib> 
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> 
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iostream>
#include <mutex>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
/* подключение созданной dll */
#include "dllochka.h"

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	char values[100], value;
	char vektor[10][10];
	/// <summary>
	/// Сводка для MyForm2
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;

	private: Thread^ myThread;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Изначальный файл";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(33, 25);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(388, 94);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(33, 125);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(388, 187);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(155, 318);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 39);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Сортировка";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(30, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Глушнев Анатолий Сергеевич ";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(298, 318);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 39);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Диагональ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(442, 367);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

static void vektor_sort(vector<char>& v) {

	/* сортировка вектора и запись его в файл*/

		sort(v.begin(), v.end());
		writeTo("new.txt", v);
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	/* вывод 100 латинских бкув из файла в textBox1 */

	String^ Filename = "words.txt";
	StreamReader^ file = File::OpenText(Filename);
	textBox1->Text = file->ReadToEnd();

	/* создание десяти векторов */

			vector<char> v1;
			vector<char> v2;
			vector<char> v3;
			vector<char> v4;
			vector<char> v5;
			vector<char> v6;
			vector<char> v7;
			vector<char> v8;
			vector<char> v9;
			vector<char> v10;

	/* открытие файла со 100 латинскими буквами*/

			ifstream f;
			f.open("words.txt");

	/* заполнение и сортировка десяти векторов с помощью десяти потоков */

			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v1.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v2.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v3.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v4.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v5.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v6.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v7.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v8.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v9.push_back(value);
			}
			for (int i = 0; i < 10; i++)
			{
				f >> value;
				v10.push_back(value);
			}
			thread potok1(vektor_sort, v1);
			potok1.join();
			thread potok2(vektor_sort, v2);
			potok2.join();
			thread potok3(vektor_sort, v3);
			potok3.join();
			thread potok4(vektor_sort, v4);
			potok4.join();
			thread potok5(vektor_sort, v5);
			potok5.join();
			thread potok6(vektor_sort, v6);
			potok6.join();
			thread potok7(vektor_sort, v7);
			potok7.join();
			thread potok8(vektor_sort, v8);
			potok8.join();
			thread potok9(vektor_sort, v9);
			potok9.join();
			thread potok10(vektor_sort, v10);
			potok10.join();
			f.close();
			
			
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	/* вывод отсортированных векторов в textBox2 */

		String^ Filename = "new.txt";
		StreamReader^ file = File::OpenText(Filename);
		textBox2->Text = file->ReadToEnd();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	/* вывод даты и времени в label1 */

	struct tm* date;
	char Current_date[100];
	const time_t timer = time(NULL);
	date = localtime(&timer);
	strftime(Current_date, 100, "%d.%m.%Y %H:%M:%S", date);
	System::String^ strCLR = gcnew System::String(Current_date);
	label1->Text += strCLR;
	srand(time(0));
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	/* добавление звездочек по диагонали */

	std::vector<char> v11;
	ifstream f;
	f.open("new.txt");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j) {
				f >> vektor[i][j];
				vektor[i][j] = '*';
				v11.push_back(vektor[i][j]);
			}
			else {
				f >> vektor[i][j];
				v11.push_back(vektor[i][j]);
			}
		}
		writeTo1("newTo.txt", v11);
		v11.clear();
	}

	/* вывод результата в textBox2 */

	String^ Filename = "newTo.txt";
	StreamReader^ file = File::OpenText(Filename);
	textBox2->Text = file->ReadToEnd();
}
};
}
