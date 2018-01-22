#include "mycontext.h"

#include <QApplication>
#include <QDebug>


MyContext::MyContext(QObject *parent) : QObject(parent)
{

}


/* *** Fonctions QML -> CPP et CPP -> QML *** */

void MyContext::test(QString texte)
{
    qDebug() << "test ok";
}

void MyContext::saveBoard(QString date)
{
    qDebug() << date << endl;
}

void MyContext::addBloc(Bloc *b)
{
    m_blocs.push_back(b);
    qDebug() << "element stocke";

}

void MyContext::afficheMBloc()
{
    for (auto *b : m_blocs)
    {
        qDebug() << "affichage";
        b->affiche();
    }
}

void MyContext::deleteMBloc(Bloc *bloc) //ne fonctionne pas !
{
//    Bloc temp = *bloc;

//    for (auto *b : m_blocs)
//    {
//        if (temp == *b)
//            qDebug() << "trouve";

//        else
//            qDebug() << "non trouve";
//    }
}


void MyContext::receivedFromQMl(QString texte)
{
    qDebug() << texte;
}


/* *** Gestion de QPROPERTY *** */

void MyContext::setMyproperty(const QString &myProperty)
{
    if (myProperty != m_myproperty){
        m_myproperty = myProperty;
        emit myPropertyChanged();
    }
}

QString MyContext::getMyproperty() const
{
    return m_myproperty;
}



