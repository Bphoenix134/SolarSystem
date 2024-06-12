#pragma once

#include "Planet.h"
#include "Start.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace SolarSystem
{
    public ref class Satellite : public Planet {
    public:
        Satellite(System::String^ name, double radius, double mass, double angularVelocity, double orbitSemiMajorAxis, double eccentricity, Color color, Color shadow);

        //����� �������� �������� ������ �������
        void MoveAroundOrbit(double currentTime, Planet^ planet) override;

        //����� ��������� �������� �������
        void SunLighting(Planet^ planet, double currentTime, Graphics^ g);

        //����� �������� ��������������� �����
        void InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7) override;

        //����� ���������� ��������
        void isEclipse(Planet^ planet, double currentTime, Graphics^ g);

        // ������� ��������� ��������
        delegate void SolarEclipseHandler(Graphics^ g, Satellite^ satellite);
        event SolarEclipseHandler^ SolarEclipse;

    private:
    };
}
