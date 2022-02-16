#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

/*!
 *  \file
 *  \brief Definicja klasy Graniastoslup
 *
 *  Plik zawiera definicje klasy Graniastoslup, ktora
 *  opisuje budowe sroby.
 *
 */

#include "Bryla.hh"
#include "Wymiary.hh"


/*!
 *  \brief Klasa 'Graniastoslup' opisuje budowe sruby.
 *
 *  Publiczne:
 *     Konstruktor Graniastoslup opisuje nam srube ze srodkiem na wierzcholku
 *     drona o grubosci zadanej stala GRUBOSC.
 */

class Graniastoslup : public Bryla {

public:


/*!
 * \brief Opisuje nam srube ze srodkiem na wierzcholku drona o grubosci 
 * zadanej stala GRUBOSC z pliku Wymiary.hh.
 *
 * Argumenty:
 *    \param[in] srodek      - srodek podstawy graniastoslupa (wierzcholek drona)
 *    \param[in] przekatna   - dlugosc przekatnej podstawy graniastoslupa
 *    \param[in] nazwa_kopii - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg  - nazwa pliku tekstowego z oryginalem
 *    \param[in] punkty      - wektor 3D opisujacy wierzcholki graniastoslupa
 */
 Graniastoslup(Wektor3D srodek, double przekatna ,string nazwa_oryg, string nazwa_kopii);
};


//opisane w ciele klasy
Graniastoslup::Graniastoslup(Wektor3D srodek, double przekatna ,string nazwa_oryg, string nazwa_kopii)
{
  Wektor3D wek;
  ilosc_wierz=0;
  this->srodek = srodek;
  this->nazwa_oryg = nazwa_oryg;
  this->nazwa_kopii = nazwa_kopii;

  for(int i= 0; i>=-300;i-=60)
  {
    wek[0]=srodek[0]+GRUBOSC;
    wek[1]=srodek[1]+przekatna*sin(i*M_PI/180);
    wek[2]=srodek[2]+przekatna*cos(i*M_PI/180);
    punkty.push_back(wek);

    wek[0]=srodek[0];
    wek[1]=srodek[1]+przekatna*sin(i*M_PI/180);
    wek[2]=srodek[2]+przekatna*cos(i*M_PI/180);
    punkty.push_back(wek);

    ilosc_wierz+=2;
  }

  punkty.push_back(punkty[0]);
  ilosc_wierz++;
  punkty.push_back(punkty[1]);
  ilosc_wierz++;
}
#endif