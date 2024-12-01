#include "TypyPracowników.hpp"
#include "RandomNameGenerator.hpp"
#include <iostream>


Pracownik::Pracownik() : imie_(getRandomName()){};



void Inz::print() const
{ 
    std::cout << imie_ << " Skonczony wydzial: " << wydzial_ << " Wynagrodzenie: " << wynagrodzenie_ << "\n";
}

const int        Inz::wynagrodzenie_ = 8000;
const int Inz::CI_            = 300;
int              Inz::nInz_          = 0;

Inz::Inz(std::string wydzial) : Pracownik(), wydzial_(wydzial)
{
    ++nInz_;
}



void Mkt::print() const
{ 
    std::cout << imie_ << " Liczba obserwujacych: " << follows_ << " Wynagrodzenie: " << wynagrodzenie_
              << "\n";
}

const int Mkt::wynagrodzenie_ = 7000;
const int Mkt::CMkt_          = 50;
int       Mkt::nMkt_          = 0;

Mkt::Mkt(int follows) : Pracownik(), follows_(follows)
{
    ++nMkt_;
}



void Mag::print() const
{ 
    std::cout << imie_ << " Obsluga wozka widlowego: " << obslWidl_ << " Wynagrodzenie: " << wynagrodzenie_ << "\n";
}


const int Mag::wynagrodzenie_ = 6000;
const int Mag::CMag_          = 40;
int       Mag::nMag_          = 0;

Mag::Mag(bool obslWidl) : Pracownik(), obslWidl_(obslWidl)
{
    ++nMag_;
}



void Rob::print() const
{ 
    std::cout << imie_ << " Rozmiar buta: " << but_ << " Wynagrodzenie: " << wynagrodzenie_ << "\n";
}

const int Rob::wynagrodzenie_ = 5000;
const int Rob::CRob_          = 30;
int       Rob::nRob_          = 0;

Rob::Rob(double but) : Pracownik(), but_(but)
{
    ++nRob_;
}
