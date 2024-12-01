class Kredyt
{
public:
    Kredyt(double kwota, int czas_splaty);

    double splac_Rate();


    double dlug_;
    int    pozostaleRaty_;
    double        rata_;
    static double calkowiteZadluzenie_;
};
