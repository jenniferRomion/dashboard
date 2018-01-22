#include "postit.h"

Postit::Postit() : Bloc()
{
}

Postit::~Postit()
{
    qDebug() << "destruction postIt ok" << endl;
}

bool Postit::estEgal(const Postit &b) const
{
    if (b.m_width == m_width
            && b.m_height == m_height
            && b.m_radius == m_radius
            && b.m_xValue == m_xValue
            && b.m_yValue == m_yValue
            && b.m_message == m_message
            && b.m_color == m_color
            && b.m_rotation == m_rotation)
        return true;

    else
        return false;
}

bool operator==(const Postit &b, const Postit &c)
{
    return b.estEgal(c);
}

void Postit::affiche()
{
    qDebug() << "width = " << QString::number(m_width)
             << " ; height = " << QString::number(m_height)
             << " ; radius = " << QString::number(m_radius)
             << " ; xValue = " << QString::number(m_xValue)
             << " ; yValue = " << QString::number(m_yValue)
             << " ; message = " << m_message
             << " ; color = " << m_color
             << " ; rotation = " << QString::number(m_rotation);
}


///* **** Gestion des QPROPERTY **** */

void Postit::setColor(const QString &color)
{
    if (m_color != color) {
        m_color = color;
        emit colorChanged();
    }
}

QString Postit::color() const
{
    return m_color;
}


void Postit::setRotation(const int &r)
{
    if (m_rotation != r) {
        m_rotation = r;
        emit rotationChanged();
    }
}

int Postit::rotation() const
{
    return m_rotation;
}
