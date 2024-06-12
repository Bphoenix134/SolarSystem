#pragma once
#include "Planet.h"
#include "Start.h"
#include "Satellite.h"
#include "HeavenlyBody.h"

#include "math.h"

namespace SolarSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	public ref class SolarSystem : public System::Windows::Forms::Form
	{
	private:
		Planet^ _mercury;
		Planet^ _venus;
		Planet^ _earth;
		Planet^ _mars;
		Start^ _sun;
		Satellite^ _moon;
		Satellite^ _phobos;
		Satellite^ _deimos;
		HeavenlyBody^ _comet;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label8;
 
	public:
		SolarSystem(void){
			InitializeComponent();
			CreatePlanets();
		}

	protected:
		~SolarSystem(){
			if (components){
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		// Глобальные переменные
		double seconds;
		int coefficient = 1;
		float ClickX;
		float ClickY;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(71, 867);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(180, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &SolarSystem::button1_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::White;
			this->trackBar1->Location = System::Drawing::Point(129, 649);
			this->trackBar1->Maximum = 11;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(56, 212);
			this->trackBar1->TabIndex = 1;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &SolarSystem::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Location = System::Drawing::Point(89, 610);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 36);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Скорость\r\nдвижения планет";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->pictureBox1->Location = System::Drawing::Point(242, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1682, 966);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SolarSystem::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &SolarSystem::pictureBox1_MouseClick);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &SolarSystem::timer1_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(15, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 22);
			this->label2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(15, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 22);
			this->label3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(15, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 22);
			this->label4->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(15, 143);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 22);
			this->label5->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(15, 188);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 22);
			this->label6->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(15, 230);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 22);
			this->label7->TabIndex = 9;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(12, 114);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(337, 305);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(89, 500);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 25);
			this->label8->TabIndex = 11;
			// 
			// SolarSystem
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(1924, 966);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"SolarSystem";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Модель Солнечной системы";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Активация работы анимации
		if (!timer1->Enabled) {
			timer1->Enabled = true;
			this->button1->Text = L"Стоп";
		}
		// Остановка работы анимации
		else {
			timer1->Enabled = false;
			this->button1->Text = L"Старт";
		}
	}
	
	private: void CreatePlanets(){
		// Создание экземпляров планет
		_mercury = gcnew Planet("Меркурий", 20, 0.33, 0.006, 155, 0.12, Color::LightGray, Color::Gray);
		_venus = gcnew Planet("Венера", 30, 4.88, 0.011, 215, 0.12, Color::White, Color::LightGray);
		_earth = gcnew Planet("Земля", 28, 5.97, 0.007, 275, 0.12, Color::LightGreen, Color::Green);
		_mars = gcnew Planet("Марс", 23, 6.42, 0.009, 345, 0.12, Color::Pink, Color::Red);

		// Создание экземпляр Солнца(радиус 0.7 * pow(10, 9))
		_sun = gcnew Start("Солнце", 110, 1.99 * pow(10, 30));

		// Создание экземпляров спутников
		_moon = gcnew Satellite("Луна", 10, 0.73, 0.03, 28, 0.2, Color::LightGray, Color::Gray);
		_phobos = gcnew Satellite("Фобос", 10, 1.072, 0.035, 25, 0.12, Color::LightGray, Color::Gray);
		_deimos = gcnew Satellite("Деймос", 8, 1.48, 0.03, 34, 0.01, Color::LightGray, Color::Gray);

		// Создание комет
		_comet = gcnew HeavenlyBody(8, 0.5, 0.05);

		// Подписываемся на событие солнечного затмения
		_earth->SubOnEclipse(_moon);
		_mars->SubOnEclipse(_deimos);
		_mars->SubOnEclipse(_phobos);

		// Подписываемся на событие столкновение кометы с планетой
		_mercury->SubOnBreakComet(_comet);
		_venus->SubOnBreakComet(_comet);
		_earth->SubOnBreakComet(_comet);
		_mars->SubOnBreakComet(_comet);

		// Координаты Солнца
		_sun->CenterX = 650;
		_sun->CenterY = 380;
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Масштабируем значение seconds с учетом коэффициента
		double scaledSeconds = seconds * coefficient;

		// Задается движение планет вокруг солнца
		_mercury->MoveAroundOrbit(scaledSeconds, _sun);
		_venus->MoveAroundOrbit(scaledSeconds, _sun);
		_earth->MoveAroundOrbit(scaledSeconds, _sun);
		_mars->MoveAroundOrbit(scaledSeconds, _sun);

		// Задается движение спутника вокруг планеты
		_moon->MoveAroundOrbit(scaledSeconds, _earth);
		_phobos->MoveAroundOrbit(scaledSeconds, _mars);
		_deimos->MoveAroundOrbit(scaledSeconds, _mars);

		// Изображение планет,звезд, спутников
		Graphics^ g = e->Graphics;
		
		// Рисуем Солнце
		SolidBrush^ sunBrush = gcnew SolidBrush(Color::Yellow);
		g->FillEllipse(sunBrush, (float)(_sun->CenterX - _sun->Radius / 2), (float)(_sun->CenterY - _sun->Radius / 2), (float)_sun->Radius, (float)_sun->Radius);

		// Рисуем планеты
		_mercury->SunLigthing(scaledSeconds, g);
		_venus->SunLigthing(scaledSeconds, g);
		_earth->SunLigthing(scaledSeconds, g);
		_mars->SunLigthing(scaledSeconds, g);

		// Рисуем спутники
		_moon->SunLighting(_earth, scaledSeconds, g);
		_phobos->SunLighting(_mars, scaledSeconds, g);
		_deimos->SunLighting(_mars, scaledSeconds, g);

		// Событие солнечного затмения
		_moon->isEclipse(_earth, scaledSeconds, g);
		_phobos->isEclipse(_mars, scaledSeconds, g);
		_deimos->isEclipse(_mars, scaledSeconds, g);

		// Создаем кометы
		_comet->RandomExist(scaledSeconds);
		if (_comet->CometExists) {
			_comet->MoveBody(_sun, _mercury, _venus, _earth, _mars, g);
			if (_comet->CometExists)
				g->FillEllipse(Brushes::LightGoldenrodYellow, (int)(_comet->PositionX - 5), (int)(_comet->PositionY - 5), 10, 10);
		}

		// Информационное табло
		Pen^ pen = gcnew Pen(Color::White, 3);
		// Определяем область на основе координат
		if (pow(ClickX - _sun->CenterX, 2) + pow(ClickY - _sun->CenterY, 2) <= pow(_sun->Radius / 2, 2)) {
			g->DrawEllipse(pen, (float)(_sun->CenterX - _sun->Radius / 2), (float)(_sun->CenterY - _sun->Radius / 2), (float)_sun->Radius, (float)_sun->Radius);
			label2->Text = "Название Звезды: " + Convert::ToString(_sun->Name);
			label3->Text = "Радиус: " + Convert::ToString(_sun->Radius);
			label4->Text = "Масса: " + Convert::ToString(_sun->Mass);
		}
		else if (pow(ClickX - _mercury->PositionX, 2) + pow(ClickY - _mercury->PositionY, 2) <= pow(_mercury->Radius / 2, 2)) {
			_mercury->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _venus->PositionX, 2) + pow(ClickY - _venus->PositionY, 2) <= pow(_venus->Radius / 2, 2)) {
			_venus->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _earth->PositionX, 2) + pow(ClickY - _earth->PositionY, 2) <= pow(_earth->Radius / 2, 2)) {
			_earth->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _mars->PositionX, 2) + pow(ClickY - _mars->PositionY, 2) <= pow(_mars->Radius / 2, 2)) {
			_mars->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _moon->PositionX, 2) + pow(ClickY - _moon->PositionY, 2) <= pow(_moon->Radius / 2, 2)) {
			_moon->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _phobos->PositionX, 2) + pow(ClickY - _phobos->PositionY, 2) <= pow(_phobos->Radius / 2, 2)) {
			_phobos->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
		else if (pow(ClickX - _deimos->PositionX, 2) + pow(ClickY - _deimos->PositionY, 2) <= pow(_deimos->Radius / 2, 2)) {
			_deimos->InfoTable(g, label2, label3, label4, label5, label6, label7);
		}
	}

	// Таймер времени
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		seconds += 0.85;
		this->pictureBox1->Invalidate();
	}

	// Ползунок времени
	private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
		coefficient = this->trackBar1->Value;
	}

	// Кклик левой кнопки мыши
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			// Получаем координаты нажатия
			ClickX = e->X;
			ClickY = e->Y;
		}
		this->pictureBox1->Invalidate();
	}
	};
}