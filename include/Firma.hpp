#include "TypyPracowników.hpp"
#include "Kredyt.hpp"
#include <variant>
#include <vector>

class Firma
{
public:
    void drukuj_Pracownikow() const;

    void wez_Kredyt(double kwota, int czas_splaty);

    void zatrudnij(const std::variant< Inz, Mkt, Mag, Rob >& p);

    void zaplac_Wynagrodzenie();

    void otrzymaj_Przychod();

    void splac_Raty();

    double get_Stan_Konta() const;

    double wartosc_Firmy();

    double oblicz_Przychod() const;

    static double stanKonta_;
    std::vector< Kredyt > kredyty_{};

    std::vector< std::variant< Inz, Mkt, Mag, Rob > > prac_{};

    std::vector< double > historiaPrzych_{};

    static const int    N_;
    static const double M_;
    static int          miesiac_;
};