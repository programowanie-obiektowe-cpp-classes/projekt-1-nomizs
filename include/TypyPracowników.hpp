#include <iostream>

class Pracownik
{
public:
    std::string imie_;

    Pracownik();
};

class Inz : public Pracownik
{
public:
    void print() const;

    std::string      wydzial_;
    static const int wynagrodzenie_;
    static const int CI_;
    static int       nInz_;

    Inz(std::string wydzial);
};

class Mkt : public Pracownik
{
public:
    void print() const;

    int              follows_;
    static const int wynagrodzenie_;
    static const int CMkt_;
    static int       nMkt_;

    Mkt(int follows);
};


class Mag : public Pracownik
{
public:
    void print() const;

    bool             obslWidl_;
    static const int wynagrodzenie_;
    static const int CMag_;
    static int       nMag_;

    Mag(bool obslWidl);
};

class Rob : public Pracownik
{
public:
    void print() const;

    double           but_;
    static const int wynagrodzenie_;
    static const int CRob_;
    static int       nRob_;

    Rob(double but);
};
