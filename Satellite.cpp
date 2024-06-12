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

    // Метод вращение спутника вокруг планеты
    void Satellite::MoveAroundOrbit(double currentTime, Planet^ planet) {
        // Расчет новых координат планеты
        m_currentRotationAngle = m_angularVelocity * currentTime; // угол поворота за время currentTime
        double r = (m_orbitSemiMajorAxis * (1 - m_eccentricity * m_eccentricity)) / (1 + m_eccentricity * cos(m_currentRotationAngle)); // расстояние от планеты до Солнца по закону Кеплера
        // Обновление положения планеты
        m_positionX = planet->PositionX + r * cos(m_currentRotationAngle); // положение по X относительно Солнца
        m_positionY = planet->PositionY + r * sin(m_currentRotationAngle); // положение по Y относительно Солнца
    };

    // Метод освещения спутника Солнцем
    void Satellite::SunLighting(Planet^ planet, double currentTime, Graphics^ g){
        // Создание объекта заполнение цветом спутника
        SolidBrush^ satelliteBrush = gcnew SolidBrush(m_color);
        SolidBrush^ satelliteLitBrush = gcnew SolidBrush(m_shadow);

        // Вычисление положения спутника
        double nSatellite = trunc(m_currentRotationAngle / (2 * Math::PI));
        double nPlanet = trunc (planet->СurrentRotationAngle / (2 * Math::PI));
        double AngleSatellite = m_currentRotationAngle - 2 * Math::PI * nSatellite;
        double AnglePlanet = planet->СurrentRotationAngle - 2 * Math::PI * nPlanet;
        double angleDiff = Math::Abs(AngleSatellite - AnglePlanet);

        // Не освещается за планетой
        if (angleDiff < Math::PI/2 || angleDiff > 3*Math::PI/2) {
            g->FillEllipse(satelliteLitBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
        }
        // Освещается перед планетой
        else {
            g->FillEllipse(satelliteBrush, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
            g->FillPie(satelliteLitBrush, (float)(m_positionX - m_radius / 2), (float)( m_positionY - m_radius / 2), (float)m_radius, (float)m_radius, (float)(planet->СurrentRotationAngle * 180 / M_PI - 90), 180.);
        }
    }

    // Метод Солнечного затмения
    void Satellite::isEclipse(Planet^ planet, double currentTime, Graphics^ g) {
        // Вычисление положеления спутника 
        double nSatellite = trunc(m_currentRotationAngle / (2 * Math::PI));
        double nPlanet = trunc(planet->СurrentRotationAngle / (2 * Math::PI));
        double angleSatellite = m_currentRotationAngle - 2 * Math::PI * nSatellite;
        double anglePlanet = planet->СurrentRotationAngle - 2 * Math::PI * nPlanet;
        double angleDiff = Math::Abs(angleSatellite - anglePlanet); 

        // Когда спутник перед планетой, то появляется тень на планете
        if (angleDiff > 5*Math::PI/6 && angleDiff < 7*Math::PI/6) {
            SolarEclipse(g, this);
            SolidBrush^ eclipseBrush = gcnew SolidBrush(planet->Col);
            g->FillPie(eclipseBrush, (float)(planet->PositionX - planet->Radius / 2), (float)(planet->PositionY - planet->Radius / 2), (float)planet->Radius, (float)planet->Radius, (float)(planet->СurrentRotationAngle * 180 / Math::PI + 150), 60.0);
        }
    }

    // Метод создание информационного табла
    void Satellite::InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7) {
        Pen^ pen = gcnew Pen(Color::White, 3);
        g->DrawEllipse(pen, (float)(m_positionX - m_radius / 2), (float)(m_positionY - m_radius / 2), (float)m_radius, (float)m_radius);
        label2->Text = "Название спутника: " + Convert::ToString(m_name);
        label3->Text = "Радиус: " + Convert::ToString(m_radius);
        label4->Text = "Масса: " + Convert::ToString(m_mass);
        label5->Text = "Скорость вращения: " + Convert::ToString(m_angularVelocity);
        label6->Text = "Эксцентриситет: " + Convert::ToString(m_eccentricity);
        label7->Text = "Большая полуось: " + Convert::ToString(m_orbitSemiMajorAxis);
    }
}
