#include "Start.h"
namespace SolarSystem
{
    Start::Start(System::String^ name, double radius, double mass){
        m_name = name;
        m_radius = radius;
        m_mass = mass;
    }
}
