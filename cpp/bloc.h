#ifndef BLOC_H
#define BLOC_H

#include <QObject>
#include <QDebug>
#include <QString>

class BlocContent;
class Bloc : public QObject
{
    Q_OBJECT
public:
    explicit Bloc(QObject *parent = nullptr);
    ~Bloc();

    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged)
    Q_PROPERTY(int xValue READ xValue WRITE setXValue NOTIFY xValueChanged)
    Q_PROPERTY(int yValue READ yValue WRITE setYValue NOTIFY yValueChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)

    virtual void affiche();
    virtual bool estEgal(Bloc const&b) const;



signals:
    void widthChanged();
    void heightChanged();
    void radiusChanged();
    void xValueChanged();
    void yValueChanged();
    void messageChanged();

public slots:

    void setWidth (const int &l);
    int width() const;

    void setHeight (const int &h);
    int height() const;

    void setRadius (const int &r);
    int radius() const;

    void setXValue (const int &x);
    int xValue() const;

    void setYValue (const int &y);
    int yValue() const;

    void setMessage (const QString &message);
    QString message() const;

protected:
    int m_width;
    int m_height;
    int m_radius;
    int m_xValue;
    int m_yValue;
    QString m_message;
};

bool operator==(Bloc const& b, Bloc const& c);

#endif // BLOC_H
