#ifndef BRYLA_HH
#define BRYLA_HH

/*!
 *  \file
 *  \brief Definicja klasy Bryla.
 *
 *  Plik zawiera definicje klasy Bryla.
 *  ktora zapisuje bryly do plikow tekstowych.
 *
 */

#include "Przestrzen_3D.hh"


/*!
 *  \brief Klasa 'Bryla' zapisuje wspolrzedne bryl do plikow tekstowych.
 *  
 *  Chronione:
 *     ilosc_wierz - ilosc wierzcholkow bryly
 *
 *  Publiczne:
 *     Metoda zapis zapisuje kopie na ktorej pracujemy.
 *     Metoda zapis_oryg zapisuje oryginal bryly.
 */
class Bryla : public Przestrzen_3D {

protected:

/*!
 *  \brief Liczba wierzcholkow.
 */
 int ilosc_wierz;


public:

/*!
 * \brief Zapisuje kopie na ktorej pracujemy.
 *
 * Argumenty:
 *    \param[in] ilosc_wierz - ilosc wierzcholkow bryly
 *    \param[in] nazwa_kopii - nazwa kopii roboczej
 *    \param[in] punkty      - wektor 3D opisujacy wierzcholki bryly
 */
 void zapis();


 /*!
 * \brief Zapisuje oryginal bryly.
 *
 * Argumenty:
 *    \param[in] ilosc_wierz - ilosc wierzcholkow bryly
 *    \param[in] nazwa_oryg  - nazwa oryginalu
 *    \param[in] punkty      - wektor 3D opisujacy wierzcholki bryly
 */
 void zapis_oryg();
};



//opisane w ciele klasy
void Bryla::zapis()
{
    ofstream plik;
    plik.open(nazwa_kopii);

    for(int i=0; i<ilosc_wierz; i++)
    {
        if(i%2 == 0)
        plik << endl;

        plik << punkty[i] << endl;
    }
    plik.close();
}



//opisane w ciele klasy
void Bryla::zapis_oryg()
{
    ofstream plik;
    plik.open(nazwa_oryg);

    for(int i=0; i<ilosc_wierz; i++)
    {
        if(i%2 == 0)
        plik << endl;
        
        plik << punkty[i] << endl; 
    }
    plik.close();
}
#endif