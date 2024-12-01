#include "Gra.hpp"

#include <iostream>

int main()
{
    std::cout << "Witaj graczu! Oto gra ekonomiczna w ktorej symulujesz prowadzenie przedsiebiorstwa. \n"
                 "Prowadzisz swoja firme, a celem gry jest osiagniecie wartosci spolki (sredni przychod z ostatnich 3 miesiecy - zadluzenie) = 100 000.\n"
                 "Twoj poczatkowy stan konta = 100 000 \n"
                 "Dokladniejszy opis gry znajduje sie w instrukcji do projektu.\n"
                 "Akcje, ktore mozesz wykonac to: \n"
                 "lp - wylistuj pracownikow(imiona i wynagrodzenia)\n"
                 "zinz - zatrudnij inz.\n"
                 "zmag - zatrudnij mag.\n"
                 "zmkt - zatrudnij mark.\n"
                 "zrob - zatrudnij rob.\n"
                 "kred - wez kredyt (w nastepnym kroku podaj kwote i czas splaty)\n"
                 "kt - zakoncz ture i wyswietl stan firmy na poczatku nastepnego miesiaca\n"
                 "Zaczynajmy! :)\n";
                
                
    Gra g{};

    g.firma_.zatrudnij(Inz("MEiL"));
    g.firma_.zatrudnij(Mkt{3452});
    g.firma_.zatrudnij(Mag{1});
    g.firma_.zatrudnij(Rob{42.});

    while (1)
    {
        g.akcja_Gracza();
        if (g.get_Stan() == true)
        {
            if ((g.firma_.wartosc_Firmy() - Kredyt::calkowiteZadluzenie_) >= 100000 && g.firma_.miesiac_ > 3)
            {
                std::cout << "\n\nGRATULACJE!!! WYGRALES GRE!!! SPROBUJ JESZCZE RAZ!!!\n";
                exit(EXIT_SUCCESS);
            }
            else if ((g.firma_.get_Stan_Konta()) < 0)
            {
                std::cout << "\n\nNIESTETY ZBANKRUTOWALES :( KONIEC GRY. SPROBUJ JESZCZE RAZ\n";
                exit(EXIT_SUCCESS);
            }
            else
            {
                g.firma_.miesiac_++;
                std::cout << "\n\nZaczynamy kolejny miesiac, podejmij akcje!\n\n";
                g.stan_= false;
            }
        }
    }
}
