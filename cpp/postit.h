#ifndef POSTIT_H
#define POSTIT_H

#include "bloc.h"


class Postit : public Bloc
{
    Q_OBJECT

public:
    Postit();
    ~Postit();

    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(int rotation READ rotation WRITE setRotation NOTIFY rotationChanged)

    bool estEgal(Postit const&b) const;


signals:
    void colorChanged();
    void rotationChanged();


public slots:
    void setColor (const QString &color);
    QString color() const;

    void setRotation (const int &r);
    int rotation() const;

    void affiche();

private:
    QString m_color;
    int m_rotation;

};

bool operator==(Postit const& b, Postit const& c);

#endif // POSTIT_H
