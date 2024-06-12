#pragma once
#include "Start.h"
#include "Planet.h"

namespace SolarSystem
{
    public ref class HeavenlyBody{
    public:
        HeavenlyBody(double radius, double mass, double angularVelocity);

        // ����� ��������� � ��������� ����� ������
        void RandomExist(double timeStep);
        
        // ����� �������� ������
        void MoveBody(Start^ sun, Planet^ planet1, Planet^ planet2, Planet^ planet3, Planet^ planet4, Graphics^ g);

        // �������
        delegate void CollisionsWithThePlanetHandler(Graphics^ g, HeavenlyBody^ heavenlyBody);
        event CollisionsWithThePlanetHandler^ CollisionsWithThePlanet; //������������ � ��������

        property double �urrentRotationAngle {
            double get() {
                return m_currentRotationAngle;
            }
        }
        property bool CometExists {
            bool get() {
                return m_cometExists;
            }
        }
        property double PositionX {
            double get() {
                return m_positionX;
            }
        }
        property double PositionY {
            double get() {
                return m_positionY;
            }
        }
        property double AngularVelocity {
            double get() {
                return m_angularVelocity;
            }
        }
        property double Radius {
            double get() {
                return m_radius;
            }
        }

    private:
        double m_positionX; //���������� �� X
        double m_positionY; //���������� �� Y
        double m_radius; //������ ��������� ����
        double m_mass; //����� ��������� ����
        double m_size; //������ ��������� ����
        double m_angularVelocity; //�������� ��������
        bool m_cometExists = false; //���������� ������ ��� ���
        double m_currentRotationAngle; //���� ��������
    };
}