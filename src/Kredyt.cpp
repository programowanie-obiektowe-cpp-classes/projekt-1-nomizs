#include "Kredyt.hpp"

#include <iostream>

double Kredyt::calkowiteZadluzenie_ = 0;

Kredyt::Kredyt(double kwota, int czas_splaty)
    : dlug_(kwota), pozostaleRaty_(czas_splaty) 
{ 
    dlug_ = dlug_ + czas_splaty * 10;
    rata_               = dlug_ / czas_splaty;
    calkowiteZadluzenie_ = calkowiteZadluzenie_ + dlug_;
}


double Kredyt::splac_Rate()
{ 
    if (pozostaleRaty_ == 0)
        return 0;
    else
    {
        dlug_                = dlug_ - rata_;
        pozostaleRaty_      = pozostaleRaty_ - 1;
        calkowiteZadluzenie_ = calkowiteZadluzenie_ - rata_;
        return rata_;
    }
}