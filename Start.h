#pragma once

namespace SolarSystem
{
    public ref class Start {
    public:
        Start(System::String^ name, double radius, double mass);
        
        property System::String^ Name {
            System::String^ get() {
                return m_name;
            }
        }
        property double CenterX{
            double get() {
                return m_centerX;
            }
            void set(double value) {
                m_centerX = value;
            }
        }
        property double CenterY{
            double get() {
                return m_centerY;
            }
            void set(double value) {
                m_centerY = value;
            }
        }
        property double Radius{
            double get() {
                return m_radius;
            }
        }
        property double Mass {
            double get() {
                return m_mass;
            }
        }

    private:
        System::String^ m_name; //Название Звезды
        double m_radius; //Радиус Звезды
        double m_mass; //Масса Звезды
        double m_centerX; //Координата по X
        double m_centerY; //Координата по Y
    };
}