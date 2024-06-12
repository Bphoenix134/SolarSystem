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
        //Метод вращение планеты вокруг Солнца
        virtual void MoveAroundOrbit(double currentTime, Start^ sun);

        // Методы влияния солнечной системы
        void OnEclipse(Graphics^ g, Satellite^ satellite);
        void SubOnEclipse(Satellite^ satellite);

        // Методы влияние столкновения с кометой
        void OnBreakComet(Graphics^ g, HeavenlyBody^ heavenlyBody);
        void SubOnBreakComet(HeavenlyBody^ heavenlyBody);

        //Метод освещения планеты Солнцем
        void SunLigthing(double currentTime, Graphics^ g);

        // Метод создания информационного табла
        virtual void InfoTable(Graphics^ g, Label^ label2, Label^ label3, Label^ label4, Label^ label5, Label^ label6, Label^ label7);

        // Свойства
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
        property double СurrentRotationAngle {
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
        System::String^ m_name; //Название планеты
        double m_radius; //Радиус планеты
        double m_mass; //Масса планеты
        double m_angularVelocity; //Угловая скорость 
        double m_orbitSemiMajorAxis; //Большая полуось орбиты
        double m_eccentricity; //Эксцентриситет орбиты
        double m_positionX; //Координата по X
        double m_positionY; //Координата по Y
        double m_currentRotationAngle; //Текущий угол поворота планеты
        Color m_color; //Цвет планеты
        Color m_shadow; //Тень планеты
    };
}