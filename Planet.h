#pragma once
#include "Start.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

namespace SolarSystem
{
    ref class Satellite;
    ref class HeavenlyBody;

    public ref class Planet {
    public:
        Planet(System::String^ name, double radius, double mass, double angularVelocity, double orbitSemiMajorAxis, double eccentricity, Color color, Color shadow);
        //����� �������� ������� ������ ������
        virtual void MoveAroundOrbit(double currentTime, Start^ sun);

        // ������ ������� ��������� �������
        void OnEclipse(Graphics^ g, Satellite^ satellite);
        void SubOnEclipse(Satellite^ satellite);

        // ������ ������� ������������ � �������
        void OnBreakComet(Graphics^ g, HeavenlyBody^ heavenlyBody);
        void SubOnBreakComet(HeavenlyBody^ heavenlyBody);

        //����� ��������� ������� �������
        void SunLigthing(double currentTime, Graphics^ g);

        // ����� �������� ��������������� �����
        virtual void InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7);

        // ��������
        property double Radius{
            double get(){
                return m_radius;
            }
        }
        property double AngularVelocity{
            double get(){
                return m_angularVelocity;
            }
        }
        property double PositionX{
            double get(){
                return m_positionX;
            }
        }
        property double PositionY{
            double get(){
                return m_positionY;
            }
        }
        property double �urrentRotationAngle {
            double get(){
                return m_currentRotationAngle;
            }
        }
        property Color Col {
            Color get(){
                return m_shadow;
            }
        }

    protected:
        System::String^ m_name; //�������� �������
        double m_radius; //������ �������
        double m_mass; //����� �������
        double m_angularVelocity; //������� �������� 
        double m_orbitSemiMajorAxis; //������� ������� ������
        double m_eccentricity; //�������������� ������
        double m_positionX; //���������� �� X
        double m_positionY; //���������� �� Y
        double m_currentRotationAngle; //������� ���� �������� �������
        Color m_color; //���� �������
        Color m_shadow; //���� �������
    };
}