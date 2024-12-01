#include "Firma.hpp"

class Gra
{
public:
    void akcja_Gracza();

    bool get_Stan();

    void tick();

    bool  stan_ =false;
    Firma firma_;
};