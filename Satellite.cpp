#include "Satellite.h"
#include "Planet.h"
#include "Start.h"

#define _USE_MATH_DEFINES
#include "math.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace SolarSystem {

    Satellite::Satellite(System::String^ name, double radius, double mass, double angularVelocity, double orbitSemiMajorAxis, double eccentricity, Color color, Color shadow) : Planet(name, radius, mass, angularVelocity, orbitSemiMajorAxis, eccentricity, color, shadow) {
    }

    // ����� �������� �������� ������ �������
    void Satellite::MoveAroundOrbit(double currentTime, Planet^ planet) {
        // ������ ����� ��������� �������
        m_currentRotationAngle = m_angularVelocity * currentTime; // ���� �������� �� ����� currentTime
        double r = (m_orbitSemiMajorAxis * (1 - m_eccentricity * m_eccentricity)) / (1 + m_eccentricity * cos(m_currentRotationAngle)); // ���������� �� ������� �� ������ �� ������ �������
        // ���������� ��������� �������
        m_positionX = planet->PositionX + r * cos(m_currentRotationAngle); // ��������� �� X ������������ ������
        m_positionY = planet->PositionY + r * sin(m_currentRotationAngle); // ��������� �� Y ������������ ������
    };

    // ����� ��������� �������� �������
    void Satellite::SunLighting(Planet^ planet, double currentTime, Graphics^ g){
        // �������� ������� ���������� ������ ��������
        SolidBrush^ satelliteBrush = gcnew SolidBrush(m_color);
        SolidBrush^ satelliteLitBrush = gcnew SolidBrush(m_shadow);

        // ���������� ��������� ��������
        double nSatellite = trunc(m_currentRotationAngle / (2 * Math::PI));
        double nPlanet = trunc (planet->�urrentRotationAngle / (2 * Math::PI));
        double AngleSatellite = m_currentRotationAngle - 2 * Math::PI * nSatellite;
        double AnglePlanet = planet->�urrentRotationAngle - 2 * Math::PI * nPlanet;
        double angleDiff = Math::Abs(AngleSatellite - AnglePlanet);

        // �� ���������� �� ��������
        if (angleDiff < Math::PI/2 || angleDiff > 3*Math::PI/2) {
            g->FillEllipse(satelliteLitBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
        }
        // ���������� ����� ��������
        else {
            g->FillEllipse(satelliteBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
            g->FillPie(satelliteLitBrush, (float)(m_positionX - m_radius / 2), (float)( m_positionY - m_radius / 2), (float)m_radius, (float)m_radius, (float)(planet->�urrentRotationAngle * 180 / M_PI - 90), 180.);
        }
    }

    // ����� ���������� ��������
    void Satellite::isEclipse(Planet^ planet, double currentTime, Graphics^ g) {
        // ���������� ����������� �������� 
        double nSatellite = trunc(m_currentRotationAngle / (2 * Math::PI));
        double nPlanet = trunc(planet->�urrentRotationAngle / (2 * Math::PI));
        double angleSatellite = m_currentRotationAngle - 2 * Math::PI * nSatellite;
        double anglePlanet = planet->�urrentRotationAngle - 2 * Math::PI * nPlanet;
        double angleDiff = Math::Abs(angleSatellite - anglePlanet); 

        // ����� ������� ����� ��������, �� ���������� ���� �� �������
        if (angleDiff > 5*Math::PI/6 && angleDiff < 7*Math::PI/6) {
            SolarEclipse(g, this);
            SolidBrush^ eclipseBrush = gcnew SolidBrush(planet->Col);
            g->FillPie(eclipseBrush, (float)(planet->PositionX - planet->Radius / 2), (float)(planet->PositionY - planet->Radius / 2), (float)planet->Radius, (float)planet->Radius, (float)(planet->�urrentRotationAngle * 180 / Math::PI + 150), 60.0);
        }
    }

    // ����� �������� ��������������� �����
    void Satellite::InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7) {
        Pen^ pen = gcnew Pen(Color::White, 3);
        g->DrawEllipse(pen, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
        label2->Text = "�������� ��������: " + Convert::ToString(m_name);
        label3->Text = "������: " + Convert::ToString(m_radius);
        label4->Text = "�����: " + Convert::ToString(m_mass);
        label5->Text = "�������� ��������: " + Convert::ToString(m_angularVelocity);
        label6->Text = "��������������: " + Convert::ToString(m_eccentricity);
        label7->Text = "������� �������: " + Convert::ToString(m_orbitSemiMajorAxis);
    }
}
