#ifndef MYCONTEXT_H
#define MYCONTEXT_H

#include "postit.h"
#include "carnet.h"
#include "bloc.h"

#include <QObject>
#include <QString>


class MyContext : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString myProperty READ getMyproperty WRITE setMyproperty NOTIFY myPropertyChanged)

public:
    explicit MyContext(QObject *parent = nullptr);

    /* *** fonctions de liasion CPP -> QML *** */
    Q_INVOKABLE void test (QString texte);
    Q_INVOKABLE void saveBoard(QString date);
    Q_INVOKABLE void addBloc(Bloc* b);
    Q_INVOKABLE void afficheMBloc();
    Q_INVOKABLE void deleteMBloc(Bloc* bloc);

signals:

    void myPropertyChanged();
    void sendtoQML (QString texte);

private:

    QString m_myproperty;
    std::vector<Postit*> m_postits;
    std::vector<Carnet*> m_carnets;
    std::vector<Bloc*> m_blocs;


public slots:
    void setMyproperty(const QString &myProperty);
    QString getMyproperty() const;

    /* *** fonctions de liaison QML -> CPP *** */
    void receivedFromQMl(QString texte);

};

#endif // MYCONTEXT_H
