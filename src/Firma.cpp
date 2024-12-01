#include "Firma.hpp"
#include "PrinterPracownikow.hpp"
#include <iostream>


void Firma::drukuj_Pracownikow() const
{ 
    for (auto pracownik:prac_)
    {
        std::visit(PrinterPracownikow{}, pracownik);
    }
}

void Firma::wez_Kredyt(double kwota, int czas_splaty)
{
    if (czas_splaty > 12)
    {
        std::cout << "Nie mozesz wziac kredytu na dluzej niz 12 miesiecy\n";
    }
    else if (Kredyt::calkowiteZadluzenie_ + kwota + czas_splaty * 10 > M_ * wartosc_Firmy())
    {
        std::cout << "Niestety nie udalo sie wziac kredytu: Calkowite zadluzenie nie moze przekroczyc wartosci 0.5 razy wartosc spolki\n";
    }
    else
    {
        kredyty_.emplace_back(kwota, czas_splaty);
    }
}

void Firma::zatrudnij(const std::variant< Inz, Mkt, Mag, Rob >& p)
{ 
    prac_.push_back(p);
}

void Firma::zaplac_Wynagrodzenie()
{
    stanKonta_ -= (Inz::nInz_ * Inz::wynagrodzenie_) + (Mkt::nMkt_ * Mkt::wynagrodzenie_) +
                  (Mag::nMag_ * Mag::wynagrodzenie_) + (Rob::nRob_ * Rob::wynagrodzenie_);
}

void Firma::otrzymaj_Przychod()
{ 
    historiaPrzych_.push_back(oblicz_Przychod());
    stanKonta_ += historiaPrzych_[miesiac_ - 1];
}

void Firma::splac_Raty()
{ 
    for (auto kredyt : kredyty_)
    {      
        stanKonta_ = stanKonta_ - kredyt.splac_Rate();
    }
}

double Firma::get_Stan_Konta() const
{
    return stanKonta_;
}

double Firma::wartosc_Firmy()
{ 
    double wartoscF = 0;

    if (historiaPrzych_.size() >= N_)
    {
        for (int i = 0; i < N_; i++)
        {
            wartoscF += historiaPrzych_[miesiac_ - 1 - i];
        }
        return wartoscF / N_;
    }
    else
    {
        wartoscF = stanKonta_;
        return wartoscF;
    }
}

double Firma::oblicz_Przychod() const
{ 
    int    pojemnoscMagazynu = Mag::nMag_ * Mag::CMag_;
    double cenaProduktu      = Inz::nInz_ * Inz::CI_;
    int    popyt             = Mkt::nMkt_ * Mkt::CMkt_;
    int    mozliwaProdukcja  = Rob::nRob_ * Rob::CRob_;

    int faktycznaProdukcja = std::min(pojemnoscMagazynu, mozliwaProdukcja);
    int sprzedaneProdukty  = std::min(popyt, faktycznaProdukcja);

    return sprzedaneProdukty * cenaProduktu;
}

double                Firma::stanKonta_ = 100000;
const int    Firma::N_         = 3;
const double          Firma::M_         = 0.5;
int                   Firma::miesiac_   = 1;