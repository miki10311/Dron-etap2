#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

/*!
 *  \file
 *  \brief Definicja klasy Przeszkoda
 *
 *  Plik zawiera definicje klasy Przeszkoda,
 *  ktora stanowi zalazek przeszkod.
 *
 */

#include "Bryla.hh"
#include "Dron.hh"
#include <memory>


/*!
 *  \brief Klasa 'Przeszkoda' jest zalazkiem do przeszkod i kolizji z nimi.
 *
 *  Argumenty:
 *     sr_prze_x - wspolrzedna x srodka przeszkody
 *     sr_prze_y - wspolrzedna y srodka przeszkody
 *     sr_prze_z - wspolrzedna z srodka przeszkody
 *
 *  Public:
 *     Konstruktor Przeszkoda jest zalazkiem przeszkod.
 *     Metoda kolizja jest podstawa do opisu kolizji przeszkody z dronem.
 *     Metoda wez_srodek_kol zwraca nam aktualna wartosc srodka drona do kolizji.
 */
class Przeszkoda: public Bryla {


protected:

/*!
* \brief Wspolrzedna x srodka przeszkody
*/
double sr_prze_x;

/*!
* \brief Wspolrzedna y srodka przeszkody
*/
double sr_prze_y;

/*!
* \brief Wspolrzedna z srodka przeszkody
*/
double sr_prze_z;


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
 * \brief Opisuje nam budowe przeszkody.
 *
 * Argumenty:
 *    \param[in] dlugosc     - dlugosc przeszkody
 *    \param[in] szerokosc   - szerokosc przeszkody
 *    \param[in] wysokosc    - wysokosc przeszkody
 *    \param[in] nazwa_kopii - nazwa pliku tekstowego z kopia robocza
 *    \param[in] nazwa_oryg  - nazwa pliku tekstowego z oryginalem
 */
 Przeszkoda(double dlugosc, double szerokosc, double wysokosc,string nazwa_oryg, string nazwa_kopii){};
 
 
 
/*!
 * \brief Poczatkowe ustwienie informacji o kolizji jako falsz.
 *
 * Argumenty:
 *    \param[in] dron - nasz dron, u ktorego sprawdzamy kolizje
 */
 virtual bool  kolizja(Dron dron)=0;
};
#endif