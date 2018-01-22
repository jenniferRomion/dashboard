#include "carnet.h"


Carnet::Carnet() : Bloc()
{
}

bool Carnet::estEgal(const Carnet &b) const
{
    if (b.m_width == m_width
            && b.m_height == m_height
            && b.m_radius == m_radius
            && b.m_xValue == m_xValue
            && b.m_yValue == m_yValue
            && b.m_message == m_message)
        return true;

    else
        return false;
}



bool operator==(const Carnet &b, const Carnet &c)
{
    return b.estEgal(c);
}
