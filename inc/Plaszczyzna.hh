#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

/*!
 *  \file
 *  \brief Definicja klasy Plaszczyzna
 *
 *  Plik zawiera definicje klasy Plaszczyzna, ktora
 *  zapisuje plaszczyzny do plikow tekstowych.
 *
 */

#include "Przestrzen_3D.hh"
#include "Dron.hh"


/*!
 *  \brief Klasa 'Plaszczyzna' zapisuje wspolrzedne plaszczyzn do plikow tekstowych.
 *
 *  Chronione:
 *     gestosc_siatki - ilosc pojedynczych kratek
 *
 *  Publiczne:
 *     Metoda zapis zapisuje kopie na ktorej pracujemy.
 *     Metoda zapis_oryg zapisuje oryginal plaszczyzny.
 */
class Plaszczyzna : public Przestrzen_3D {

protected:

/*!
 *  \brief Ilosc pojedynczych kratek.
 */
int gestosc_siatki;


public:


/*!
 * \brief Zapisuje kopie na ktorej pracujemy.
 *
 * Argumenty:
 *    \param[in] gestosc_siatki - ilosc pojedynczych kratek
 *    \param[in] nazwa_kopii    - nazwa kopii roboczej
 *    \param[in] punkty         - wektor 3D opisujacy wierzcholki bryly
 */
void zapis();



 /*!
 * \brief Zapisuje oryginal plaszczyzny.
 *
 * Argumenty:
 *    \param[in] gestosc_siatki - ilosc pojedynczych kratek
 *    \param[in] nazwa_oryg     - nazwa oryginalu
 *    \param[in] punkty         - wektor 3D opisujacy wierzcholki bryly
 */
void zapis_oryg();
};


//opisane w ciele klasy
void Plaszczyzna::zapis()
{
    ofstream plik;
    plik.open(nazwa_kopii);
    int k=0;
    for(int i=0; i<(int)punkty.size()/gestosc_siatki; i++)
    {
        for(int j=0; j<gestosc_siatki; j++)
        {
            plik<<punkty[k]<<endl;
            k++;
        }
        plik<<endl;
    }
    plik.close();
}


//opisane w ciele klasy
void Plaszczyzna::zapis_oryg()
{
    ofstream plik;
    plik.open(nazwa_oryg);
    int k=0;
    for(int i=0; i<(int)punkty.size()/gestosc_siatki; i++)
    {
        for(int j=0; j<gestosc_siatki; j++)
        {
            plik<<punkty[k]<<endl;
            k++;
        }
        plik<<endl;
    }
    plik.close();  
}
#endif