struct PrinterPracownikow
{
    template < typename T >
    void operator()(const T& t)
    {
        t.print();
    }
};