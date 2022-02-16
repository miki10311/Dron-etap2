#ifndef DNO_HH
#define DNO_HH

/*!
 *  \file
 *  \brief Definicja klasy Dno
 *
 *  Plik zawiera definicje klasy Dno,
 *  ktora opisuje powierzchnie dna jako szachownice.
 *
 */

#include "Plaszczyzna.hh"
#include "Wymiary.hh"



/*!
 *  \brief Klasa 'Dno' opisuje dno przestrzeni, w ktorej porusza sie dron.
 *
 *  Public:
 *     Konstruktor Dno realizuje wyglad dna jako szachownice.
 *     Metoda kolizja opisuje zachowanie drona podczas kolizji z dnem.
 */
class Dno : public Plaszczyzna {

public:

/*!
 * \brief Realizuje wyglad dna jako szachownice. Dno jest kwadratem.
 *
 * Argumenty:
 *    \param[in] rozmiar_dna    - wymiar calkowity boczny dna
 *    \param[in] glebokosc_dna  - wysokosc na ktorej ma byc dno
 *    \param[in] podzial        - wymiar calkowity boczny pojedynczej kratki
 *    \param[in] gestosc_siatki - ilosc pojedynczych kratek
 *    \param[in] nazwa_kopii    - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg     - nazwa pliku tekstowego z oryginalem
 *
 */
 Dno(int rozmiar_dna, int glebokosc_dna, int podzial, string nazwa_oryg, string nazwa_kopii);
    





/*!
 * \brief Opisuje zachowanie drona podczas kolizji z dnem.
 * Korzysta z Wymiary.hh, aby uzyskac WYSOKOSC drona.
 *
 * Argumenty:
 *    \param[in] dron   - interpretacja drona jako prostopadloscian
 *    \param[in] punkty - wektor 3D opisujacy wierzcholki figury
 *
 * Zwraca:
 *    Informacje o obecnosci kolizji lub jej braku.
 */
 bool kolizja(Dron dron)
 {
    if(punkty[0][2]>=dron.wez_figure().wez_srodek_kol()[2]-WYSOKOSC/2)
    {
        return true;
    }
    return false;
 }
};


//opisane w ciele klasy
Dno::Dno(int rozmiar_dna, int glebokosc_dna, int podzial, string nazwa_oryg, string nazwa_kopii)
{
    Wektor3D punkt;
    gestosc_siatki=0;
    this->nazwa_oryg=nazwa_oryg;
    this->nazwa_kopii=nazwa_kopii;

    for (int szer=(-rozmiar_dna)/2; szer<=rozmiar_dna/2; szer+=podzial)
    {
        gestosc_siatki++;
        for (int dlu=(-rozmiar_dna)/2; dlu<=rozmiar_dna/2; dlu+=podzial)
        {
            punkt[0] = szer;
            punkt[1] = dlu;
            punkt[2] = glebokosc_dna;
            punkty.push_back(punkt);
        }
    }
}
#endif