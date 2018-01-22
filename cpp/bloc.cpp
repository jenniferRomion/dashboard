#include "bloc.h"

Bloc::Bloc(QObject *parent) : QObject(parent)
{

}

Bloc::~Bloc()
{
    qDebug() << "destruction bloc ok" << endl;
}

void Bloc::affiche()
{
    qDebug() << "width = " << QString::number(m_width)
             << " ; height = " << QString::number(m_height)
             << " ; radius = " << QString::number(m_radius)
             << " ; xValue = " << QString::number(m_xValue)
             << " ; yValue = " << QString::number(m_yValue)
             << " ; message = " << m_message;
}

bool Bloc::estEgal(const Bloc &b) const
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

/* **** Gestion des QPROPERTY **** */
void Bloc::setWidth(const int &l)
{
    if (m_width != l) {
        m_width = l;
        emit widthChanged();
    }
}

int Bloc::width() const
{
    return m_width;
}

void Bloc::setHeight(const int &h)
{
    if(m_height != h) {
        m_height = h;
        emit heightChanged();
    }
}

int Bloc::height() const
{
    return m_height;
}

void Bloc::setRadius(const int &r)
{
    if (m_radius != r) {
        m_radius = r;
        emit radiusChanged();
    }
}

int Bloc::radius() const
{
    return m_radius;
}

void Bloc::setXValue(const int &x)
{
    if (m_xValue != x) {
        m_xValue = x;
        emit xValueChanged();
    }
}

int Bloc::xValue() const
{
    return m_xValue;
}

void Bloc::setYValue(const int &y)
{
    if (m_yValue != y) {
        m_yValue = y;
        emit yValueChanged();
    }
}

int Bloc::yValue() const
{
    return m_yValue;
}

void Bloc::setMessage(const QString &message)
{
    if (m_message != message) {
        m_message = message;

        qDebug() << "m_message = " << m_message;

        emit messageChanged();
    }
}

QString Bloc::message() const
{
    return m_message;
}


bool operator==(const Bloc &b, const Bloc &c)
{
    return b.estEgal(c);
}
