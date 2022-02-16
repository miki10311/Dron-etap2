#ifndef DRON_HH
#define DRON_HH

/*!
 *  \file
 *  \brief Definicja klasy Dron
 *
 *  Plik zawiera definicje klasy Dron, ktora
 *  opisuje budowe drona ze srobami.
 *
 */

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Wymiary.hh"


/*!
 *  \brief Klasa 'Dron' opisuje budowe drona ze srobami.
 *
 *  Prywatne:
 *     figura - dron jako prostopadloscian (bez srob)
 *     sroby  - tablica z dwoma srobami
 *
 *  Publiczne:
 *     Konstruktor Dron opisuje nam drona ze srobami.
 *     Metoda sterowanie wykonuje koncowy ruch drona.
 *     Metoda wez_figure dostarcza prostopadloscian do drona.
 */

class Dron {

/*!
 *  \brief Dron jako prostopadloscian (bez srob).
 */
 Prostopadloscian *figura;

/*!
 *  \brief Tablica z dwoma srobami.
 */
 Graniastoslup *sroby[2];


public:

/*!
 * \brief Laczy nam drona i sroby oraz powstaje koncowy ksztalt droan ze srobami.
 * Korzysta z Wymiary.hh, aby uzyskac wymiary drona.
 *
 * Argumenty:
 *    \param[in] figura - dron jako prostopadloscian (bez srob)
 *    \param[in] sroby  - tablica z dwoma srobami
 */
 Dron();

/*!
 * \brief Laczy w sobie operacje sterowania dronem. 
 *
 * Argumenty:
 *    \param[in] kat_obrotu   - kat obrotu drona (OZ)
 *    \param[in] kat_opadania - kat opadania drona (OY)
 *    \param[in] droga        - dlugosc wektora przesuniecia
 */
 void Sterowanie(double kat_obrotu, double kat_opadania, double droga);
 
 
/*!
 * \brief Dostarcza prostopadloscian do drona.
 */
 const Prostopadloscian &wez_figure() const {return *figura;}
};


//opisane w ciele klasy
Dron::Dron()
{
  figura = new Prostopadloscian(DLUGOSC,SZEROKOSC,WYSOKOSC,"bryly/figura.dat","bryly/figura_zap.dat");
  figura->zapis();
  figura->zapis_oryg();
  sroby[0] = new Graniastoslup((*figura)[5],3,"bryly/sroba1.dat","bryly/sroba1_zap.dat");
  sroby[1] = new Graniastoslup((*figura)[7],3,"bryly/sroba2.dat","bryly/sroba2_zap.dat");
  sroby[0]->zapis();
  sroby[0]->zapis_oryg();
  sroby[1]->zapis();
  sroby[1]->zapis_oryg();
}


//opisane w ciele klasy
void Dron::Sterowanie(double kat_obrotu, double kat_opadania, double droga)
{
  figura->zamien_kat_obrotu(kat_obrotu);
  figura->zamien_kat_opadania(kat_opadania);
  figura->przesuniecie(droga);
  figura->translacja();
  figura->zapis();

  sroby[0]->zamien_kat_obrotu(kat_obrotu);
  sroby[0]->zamien_kat_rotacji(5);
  sroby[0]->zamien_kat_opadania(kat_opadania);
  sroby[0]->przesuniecie(droga);
  sroby[0]->translacja();
  sroby[0]->zapis();

  sroby[1]->zamien_kat_obrotu(kat_obrotu);
  sroby[1]->zamien_kat_rotacji(5);
  sroby[1]->zamien_kat_opadania(kat_opadania);
  sroby[1]->przesuniecie(droga);
  sroby[1]->translacja();
  sroby[1]->zapis();
}
#endif