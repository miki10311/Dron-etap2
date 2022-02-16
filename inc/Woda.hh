#ifndef WODA_HH
#define WODA_HH

/*!
 *  \file
 *  \brief Definicja klasy Woda
 *
 *  Plik zawiera definicje klasy Woda,
 *  ktora opisuje powierzchnie wody jako zcisnieta szachownice.
 *
 */

#include "Plaszczyzna.hh"
#include "Wymiary.hh"



/*!
 *  \brief Klasa 'Woda' opisuje gorna powierzchnie przestrzeni,
 *  w ktorej porusza sie dron.
 *
 *  Public:
 *     Konstruktor Woda realizuje wyglad wody jako zcisnieta szachownice.
 *     Metoda kolizja opisuje zachowanie drona podczas kolizji z woda.
 */
class Woda : public Plaszczyzna {

public:

/*!
 * \brief Realizuje wyglad wody jako zcisnieta szachownice.
 *  Podstawa wody jest kwadratem.
 *
 * Argumenty:
 *    \param[in] rozmiar_wody   - wymiar calkowity boczny wody
 *    \param[in] wysokosc_wody  - wysokosc na ktorej ma byc powierzchnia
 *    \param[in] podzial        - wymiar calkowity boczny pojedynczej kratki
 *    \param[in] gestosc_siatki - ilosc pojedynczych kratek
 *    \param[in] wysokosc_fali  - wysokosc powierzchni wody
 *    \param[in] nazwa_kopii    - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg     - nazwa pliku tekstowego z oryginalem
 *
 */
 Woda(int rozmiar_wody, int wysokosc_wody, int podzial, int wysokosc_fali, string nazwa_oryg, string nazwa_kopii);


/*!
 * \brief Opisuje zachowanie drona podczas kolizji z woda,
 * wykorzystujac stale z pliku Wymiary.hh.
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
    if(punkty[0][2]<=dron.wez_figure().wez_srodek_kol()[2]+WYS_FAL+WYSOKOSC/2)
    {
        return true;
    }
    return false;
 }
};

//opisane w ciele klasy
Woda::Woda(int rozmiar_wody, int wysokosc_wody, int podzial, int wysokosc_fali, string nazwa_oryg, string nazwa_kopii)
{
    Wektor3D punkt;
    gestosc_siatki=0;
    this->nazwa_oryg=nazwa_oryg;
    this->nazwa_kopii=nazwa_kopii;

    for (int szer=(-rozmiar_wody)/2; szer<=rozmiar_wody/2; szer+=podzial)
    {
        gestosc_siatki++;
        for (int dlu=(-rozmiar_wody)/2; dlu<=rozmiar_wody/2; dlu+=podzial)
        {
            punkt[0] = szer;
            punkt[1] = dlu;

            if(gestosc_siatki%2==0)
            punkt[2] = wysokosc_wody;
            else
            punkt[2] = wysokosc_wody+wysokosc_fali;
            
            punkty.push_back(punkt);
        }
    }
}
#endif