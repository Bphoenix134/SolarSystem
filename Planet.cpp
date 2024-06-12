#include "Planet.h"
#include "Start.h"
#include "Satellite.h"
#include "HeavenlyBody.h"

#define _USE_MATH_DEFINES
#include "math.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace SolarSystem
{
	Planet::Planet(System::String^ name, double radius, double mass, double angularVelocity, double orbitSemiMajorAxis, double eccentricity, Color color, Color shadow){
		m_name = name;
		m_radius = radius;
		m_mass = mass;
		m_angularVelocity = angularVelocity;
		m_orbitSemiMajorAxis = orbitSemiMajorAxis;
		m_eccentricity = eccentricity;
		m_color = color;
		m_shadow = shadow;
	}

	//���������� �������� ������ ������
	void Planet::MoveAroundOrbit(double currentTime, Start^ sun){
		// ������ ����� ��������� �������
		m_currentRotationAngle = m_angularVelocity * currentTime; // ���� �������� �� ����� currentTime
		double r = (m_orbitSemiMajorAxis * (1 - m_eccentricity * m_eccentricity)) / (1 + m_eccentricity * cos(m_currentRotationAngle)); // ���������� �� ������� �� ������ �� ������ �������
		// ���������� ��������� �������
		m_positionX = sun->CenterX + r * cos(m_currentRotationAngle); // ��������� �� X ������������ ������
		m_positionY = sun->CenterY + r * sin(m_currentRotationAngle); // ��������� �� Y ������������ ������
	}

	// ����� ��������� ������� �������
	void Planet::SunLigthing(double currentTime, Graphics^ g) {
		SolidBrush^ planetBrush = gcnew SolidBrush(m_color);
		SolidBrush^ planetLitBrush = gcnew SolidBrush(m_shadow);
		g->FillEllipse(planetBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
		g->FillPie(planetLitBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius, (float)(m_currentRotationAngle * 180 / M_PI - 90), 180.0);
	}
	 
	// ����� �������� ��������������� �����
	void Planet::InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7) {
		Pen^ pen = gcnew Pen(Color::White, 3);
		g->DrawEllipse(pen, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
		label2->Text = "�������� �������: " + Convert::ToString(m_name);
		label3->Text = "������: " + Convert::ToString(m_radius);
		label4->Text = "�����: " + Convert::ToString(m_mass);
		label5->Text = "�������� ��������: " + Convert::ToString(m_angularVelocity);
		label6->Text = "��������������: " + Convert::ToString(m_eccentricity);
		label7->Text = "������� �������: " + Convert::ToString(m_orbitSemiMajorAxis);
	}

	// ���� ������� ��������� �������� � ��� �������
	void Planet::OnEclipse(Graphics^ g, Satellite^ satellite){
		satellite->SolarEclipse -= gcnew Satellite::SolarEclipseHandler(this, &Planet::OnEclipse);
	}
	// �������� �� ������� ��������� ��������
	void Planet::SubOnEclipse(Satellite^ satellite) {
		satellite->SolarEclipse += gcnew Satellite::SolarEclipseHandler(this, &Planet::OnEclipse);
	}

	// ���� ������� � ������� ������������ � �������
	void Planet::OnBreakComet(Graphics^ g, HeavenlyBody^ heavenlyBody) {
		heavenlyBody->CollisionsWithThePlanet -= gcnew HeavenlyBody::CollisionsWithThePlanetHandler(this, &Planet::OnBreakComet);
	}
	// �������� �� ������� ������������ � �������
	void Planet::SubOnBreakComet(HeavenlyBody^ heavenlyBody) {
		heavenlyBody->CollisionsWithThePlanet += gcnew HeavenlyBody::CollisionsWithThePlanetHandler(this, &Planet::OnBreakComet);
	}
}