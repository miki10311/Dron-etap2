#ifndef PRZESZKODA_PRET_HH
#define PRZESZKODA_PRET_HH

/*!
 *  \file
 *  \brief Definicja klasy Przeszkoda_Pret
 *
 *  Plik zawiera definicje klasy Przeszkoda_Pret, ktora
 *  opisuje budowe przeszkody-preta.
 *
 */

#include "Przeszkoda.hh"
#include "Wymiary.hh"
#include <memory>


/*!
 *  \brief Klasa 'Przeszkoda_Pret' opisuje budowe 
 *  przeszkody-preta.
 *
 *  Publiczne:
 *     Konstruktor Przeszkoda_Pret opisuje nam preta-przeszkode.
 *     Metoda kolizja odpowiada za kolizje drona i przeszkody.
 */
class Przeszkoda_Pret : public Przeszkoda {

public:


/*!
 * \brief Opisuje nam budowe preta.
 *
 * Argumenty:
 *    \param[in] dlugosc     - dlugosc preta
 *    \param[in] szerokosc   - szerokosc preta
 *    \param[in] wysokosc    - wysokosc preta
 *    \param[in] nazwa_kopii - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg  - nazwa pliku tekstowego z oryginalem
 *    \param[in] punkty      - wektor 3D opisujacy wierzcholki preta
 *    \param[in] sr_prze_x   - wspolrzedna x srodka przeszkody
 *    \param[in] sr_prze_y   - wspolrzedna y srodka przeszkody
 *    \param[in] sr_prze_z   - wspolrzedna z srodka przeszkody
 */
Przeszkoda_Pret(double dlugosc, double szerokosc, double wysokosc, string nazwa_oryg, string nazwa_kopii) : Przeszkoda(dlugosc, szerokosc, wysokosc, nazwa_oryg, nazwa_kopii)
{
  Wektor3D punkt;
  ilosc_wierz=2;
  srodek=0;
  Translacja=0;
  osZ(obrot,0);
  osZ(rotacja,0);   // inicjalizacja poszczegolnych wielkosci

  sr_prze_x= dlugosc/2;
  sr_prze_y= szerokosc/2;
  sr_prze_z = wysokosc/2;

  punkty.resize(ilosc_wierz);
  this->nazwa_oryg = nazwa_oryg;
  this->nazwa_kopii = nazwa_kopii;

  for (int i=0; i<2; i++)
  {
    punkty[i][0] = -dlugosc/2;
    punkty[i][1] = -szerokosc/2;
    punkty[i][2] = -wysokosc/2;
  }

  punkty[1][0] += dlugosc;
  punkty[1][1] += szerokosc;
}



/*!
* \brief Opisuje zachowanie drona podczas kolizji z przeszkoda, wykorzystujac dane z pliku Wymiary.hh.
*
* Argumenty:
*    \param[in] dron       - interpretacja drona jako prostopadloscian
*    \param[in] punkty     - wektor 3D opisujacy wierzcholki figury
*    \param[in] sr_prze_x  - wspolrzedna x srodka przeszkody
*    \param[in] sr_prze_y  - wspolrzedna y srodka przeszkody
*    \param[in] sr_prze_z  - wspolrzedna z srodka przeszkody
*
* Zwraca:
*    Informacje o obecnosci kolizji lub jej braku.
*/
virtual bool kolizja(Dron dron)
{
  if(wez_srodek_kol()[0]-DLUGOSC/2-sr_prze_x<=dron.wez_figure().wez_srodek_kol()[0] && dron.wez_figure().wez_srodek_kol()[0]<= wez_srodek_kol()[0]+DLUGOSC/2+sr_prze_x
  && wez_srodek_kol()[1]-SZEROKOSC/2-sr_prze_y<=dron.wez_figure().wez_srodek_kol()[1] && dron.wez_figure().wez_srodek_kol()[1]<=wez_srodek_kol()[1]+SZEROKOSC/2+sr_prze_y
  && wez_srodek_kol()[2]-WYSOKOSC/2-sr_prze_z<=dron.wez_figure().wez_srodek_kol()[2] && dron.wez_figure().wez_srodek_kol()[2]<= wez_srodek_kol()[2]+WYSOKOSC/2+sr_prze_z)
  {
      cout<<"Kolizja z przeszkoda: Pret!"<<endl;
      return true;
  }
  return false;
}
};
#endif