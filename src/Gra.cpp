#include "Gra.hpp"

#include <iostream>


void Gra::akcja_Gracza()
{
    while (stan_ == false)
    {
        std::string komenda;
        std::cin >> komenda;

        if (komenda == "lp")
            firma_.drukuj_Pracownikow();
        else if (komenda == "zinz")
        {
            std::string wydzial;
            std::cout << "Podaj wydzial jaki ukonczyl twoj nowy pracownik: ";
            std::cin >> wydzial;
            firma_.zatrudnij(Inz(wydzial));
        }
        else if (komenda == "zmag")
        {
            bool obslWidl;
            std::cout << "Czy twoj nowy pracownik moze obslugiwac wozek widlowy?? (1 - tak, 0 - nie): ";

            while (!(std::cin >> obslWidl) || (obslWidl != 0 && obslWidl != 1))
            {
                std::cout << "Bledny format! Wprowadz 1 (tak) lub 0 (nie): ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            
            firma_.zatrudnij(Mag{obslWidl});
        }
        else if (komenda == "zmkt")
        {
            int follows;
            std::cout << "Podaj ile obserwujacych posiada twoj nowy pracownik: ";
            while (!(std::cin >> follows))
            {
                std::cout << "Bledny format! Wprowadz liczbe calkowita: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            firma_.zatrudnij(Mkt{follows});
        }
        else if (komenda == "zrob")
        {
            double but;
            std::cout << "Podaj rozmiar buta twojego nowego pracownika: ";
            while (!(std::cin >> but))
            {
                std::cout << "Bledny format! Wprowadz liczbe: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            firma_.zatrudnij(Rob{but});
        }
        else if (komenda == "kred")
        {
            double kwota;
            int    czas_splaty;
            std::cout << "Podaj kwote na jaka chcesz wziac kredyt, oraz czas jego splaty w miesiacach: ";
            while (!(std::cin >> kwota >>czas_splaty))
            {
                std::cout << "Bledny format! Wprowadz 2 wartosci liczbowe (druga musi byc liczba calkowita: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            firma_.wez_Kredyt(kwota, czas_splaty);
        }
        else if (komenda == "kt")
        {
            tick();
            if (firma_.miesiac_ < 3)
                std::cout << "UWAGA: Aby otrzymac realna wartosc firmy musi ona istniec przynajmniej 3 miesiace\n";

            std::cout << "\nKoniec tury :) \nStan firmy na poczatku nastepnego miesiaca: \nWartosc firmy - calkowite zadluzenie = "
                      << firma_.wartosc_Firmy() - Kredyt::calkowiteZadluzenie_
                      << "\nStan konta = " << firma_.get_Stan_Konta();
        }
        else
        {
            std::cout << "Niestety, nie ma takiej komendy :(\n";
        }
    }
}

bool Gra::get_Stan()
{
    return stan_;
}

void Gra::tick()
{ 
    firma_.otrzymaj_Przychod();
    firma_.splac_Raty();
    firma_.zaplac_Wynagrodzenie();
    stan_ = true;
}