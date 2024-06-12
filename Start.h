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
        System::String^ m_name; //�������� ������
        double m_radius; //������ ������
        double m_mass; //����� ������
        double m_centerX; //���������� �� X
        double m_centerY; //���������� �� Y
    };
}