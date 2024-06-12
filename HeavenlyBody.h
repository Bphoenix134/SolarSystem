#pragma once
#include "Start.h"
#include "Planet.h"

namespace SolarSystem
{
    public ref class HeavenlyBody{
    public:
        HeavenlyBody(double radius, double mass, double angularVelocity);

        // Метод появление в рандомном месте кометы
        void RandomExist(double timeStep);
        
        // Метод движения кометы
        void MoveBody(Start^ sun, Planet^ planet1, Planet^ planet2, Planet^ planet3, Planet^ planet4, Graphics^ g);

        // События
        delegate void CollisionsWithThePlanetHandler(Graphics^ g, HeavenlyBody^ heavenlyBody);
        event CollisionsWithThePlanetHandler^ CollisionsWithThePlanet; //Столкновение с планетой

        property double СurrentRotationAngle {
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
        double m_positionX; //Координаты по X
        double m_positionY; //Координаты по Y
        double m_radius; //Радиус небесного тела
        double m_mass; //Масса небесного тела
        double m_size; //Размер небесного тела
        double m_angularVelocity; //Скорость вращения
        bool m_cometExists = false; //Существует комета или нет
        double m_currentRotationAngle; //Угол вращения
    };
}