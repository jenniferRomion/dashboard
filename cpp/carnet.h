#ifndef CARNET_H
#define CARNET_H

#include "bloc.h"


class Carnet : public Bloc
{
public:
    Carnet();
    bool estEgal(Carnet const&b) const;


};

bool operator==(Carnet const& b, Carnet const& c);

#endif // CARNET_H

