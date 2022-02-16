#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

/*!
 *  \file
 *  \brief Definicja klasy Prostopadloscian
 *
 *  Plik zawiera definicje klasy Prostopadloscian, ktora
 *  opisuje budowe prostopadloscianu (naszego drona).
 *
 */

#include "Bryla.hh"


/*!
 *  \brief Klasa 'Prostopadloscian' opisuje budowe prostopadloscianu (drona).
 *
 *  Publiczne:
 *     Konstruktor Prostopadloscian opisuje nam prostopadloscian.
 *     Metoda wez_srodek_kol zwraca nam aktualna wartosc srodka drona do kolizji.
 */
class Prostopadloscian : public Bryla {

public:


/*!
 * \brief Zwraca nam aktualna wartosc srodka drona potrzebny do kolizji.
 *
 * Argumanty:
 *    \param[in] Translacja - aktualny stan srodka drona
 */
const Wektor3D &wez_srodek_kol() const 
{
  return Translacja;
}

/*!
 * \brief Opisuje nam budowe prostopadloscianu (naszego drona).
 *
 * Argumenty:
 *    \param[in] dlugosc     - dlugosc drona
 *    \param[in] szerokosc   - szerokosc drona
 *    \param[in] wysokosc    - wysokosc drona
 *    \param[in] nazwa_kopii - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg  - nazwa pliku tekstowego z oryginalem
 *    \param[in] punkty      - wektor 3D opisujacy wierzcholki drona
 */
Prostopadloscian(double dlugosc, double szerokosc, double wysokosc,string nazwa_oryg, string nazwa_kopii);
};


//opisane w ciele klasy
Prostopadloscian::Prostopadloscian(double dlugosc, double szerokosc, double wysokosc,string nazwa_oryg, string nazwa_kopii)
{
  Wektor3D punkt;
  ilosc_wierz=10;
  kat_obrotu=0;
  kat_opadania=0;
  kat_rotacji=0;

  punkty.resize(ilosc_wierz);
  this->nazwa_oryg = nazwa_oryg;
  this->nazwa_kopii = nazwa_kopii;

  for (int i=0; i<10; i++)
  {
    punkty[i][0] = -dlugosc/2;
    punkty[i][1] = -szerokosc/2;
    punkty[i][2] = -wysokosc/2;
  }
  punkty[1][0] += dlugosc;

  punkty[2][1] += szerokosc;

  punkty[3][0] += dlugosc;
  punkty[3][1] += szerokosc;

  punkty[4][1] += szerokosc;
  punkty[4][2] += wysokosc;

  punkty[5][0] += dlugosc;
  punkty[5][1] += szerokosc;
  punkty[5][2] += wysokosc;

  punkty[6][2] += wysokosc;

  punkty[7][0] += dlugosc;
  punkty[7][2] += wysokosc;

  punkty[9][0] += dlugosc;
}
#endif