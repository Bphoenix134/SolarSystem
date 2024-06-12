#include "HeavenlyBody.h"
#include "Start.h"
#include "Planet.h"

#define _USE_MATH_DEFINES
#include "math.h"

using namespace std;
using namespace System;

namespace SolarSystem {

	HeavenlyBody::HeavenlyBody(double radius, double mass, double angularVelocity){
		m_radius = radius;
		m_mass = mass;
		m_angularVelocity = angularVelocity;
	}

	// ыМетод появление кометы в рандомном месте
	void HeavenlyBody::RandomExist(double timeStep) {
		if(m_cometExists)
			return;
		Random^ rand = gcnew Random();
		if (rand->NextDouble() < 0.1 && !m_cometExists) {
			m_cometExists = true;
			m_positionX = rand->Next(100, 800);
			m_positionY = rand->Next(100, 400);
			m_currentRotationAngle = rand->NextDouble() * 2 * Math::PI;
			m_angularVelocity = rand->NextDouble() * 40;
		}
	}

	// Метод движения комет
	void HeavenlyBody::MoveBody(Start^ sun, Planet^ planet1, Planet^ planet2, Planet^ planet3, Planet^ planet4, Graphics^ g) {
		if (m_cometExists) {
			m_positionX += cos(m_currentRotationAngle) * m_angularVelocity;
			m_positionY += sin(m_currentRotationAngle) * m_angularVelocity;

			// Проверяем столкновение с Солнцем
			if (pow(m_positionX-sun->CenterX,2) + pow(m_positionY-sun->CenterY, 2) <= pow(sun->Radius/2, 2)) {
				m_cometExists = false;
				g->FillEllipse(Brushes::Red, (int)(m_positionX - 5), (int)(m_positionY - 5), 20, 20);
			}
			// Проверяем столкновение с планетой
			if (pow(m_positionX - planet1->PositionX, 2) + pow(m_positionY - planet1->PositionY, 2) <= pow(planet1->Radius/2, 2)) {
				CollisionsWithThePlanet(g, this);
				g->FillEllipse(Brushes::Red, (int)(PositionX - 5), (int)(PositionY - 5), 20, 20);
				m_cometExists = false;
			}
			if (pow(m_positionX - planet2->PositionX, 2) + pow(m_positionY - planet2->PositionY, 2) <= pow(planet2->Radius/2, 2)) {
				CollisionsWithThePlanet(g, this);
				g->FillEllipse(Brushes::Red, (int)(PositionX - 5), (int)(PositionY - 5), 20, 20);
				m_cometExists = false;
			}
			if (pow(m_positionX - planet3->PositionX, 2) + pow(m_positionY - planet3->PositionY, 2) <= pow(planet3->Radius/2, 2)) {
				CollisionsWithThePlanet(g, this);
				g->FillEllipse(Brushes::Red, (int)(PositionX - 5), (int)(PositionY - 5), 20, 20);
				m_cometExists = false;
			}
			if (pow(m_positionX - planet4->PositionX, 2) + pow(m_positionY - planet4->PositionY, 2) <= pow(planet4->Radius/2, 2)) {
				CollisionsWithThePlanet(g, this);
				g->FillEllipse(Brushes::Red, (int)(PositionX - 5), (int)(PositionY - 5), 20, 20);
				m_cometExists = false;
			}
			if ((m_positionX < -10 || m_positionX > 1300) || (m_positionY < -10 || m_positionY > 800)) {
				m_cometExists = false;
			}
		}
	}
}
