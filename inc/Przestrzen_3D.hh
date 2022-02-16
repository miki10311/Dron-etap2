#ifndef PRZESTRZEN_3D_HH
#define PRZESTRZEN_3D_HH

/*!
 *  \file
 *  \brief Definicja klasy Przestrzen_3D
 *
 *  Plik zawiera definicje klasy Przestrzen_3D, ktora
 *  opisuje operacje ruchu w przestrzeni trojwymiarowej.
 *
 */

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>
#include <cmath>
#include <fstream>


/*!
 *  \brief Klasa 'Przestrzen_3D' pisuje operacje ruchu 
 *  w przestrzeni trojwymiarowej.
 *  
 *  Chronione:
 *     punkty       - wektor 3D opisujacy wierzcholki bryly
 *     Translacja   - wektor 3D, o ktory przesowamy bryly
 *     srodek       - wektor 3D opisujacy srodek podstawy bryly 
 *     obrot        - macierz obrotu zwiazana z zmiana kierunku drona (OZ)
 *     opadanie     - macierz obrotu zwiazana z opadaniem drona (OY)
 *     rotacja      - macierz obrotu zwiazana z obrotem srob (OX)
 *     kat_obrotu   - kat obrotu drona (OZ)
 *     kat_opadania - kat opadania drona (OY)
 *     kat_rotacji  - kat obrotu srob (OX)
 *     nazwa_oryg   - nazwa pliku tekstowego z oryginalem
 *     nazwa_kopii  - nazwa pliku tekstowego z kopia robocza
 *
 *  Publiczne:
 *     Przeciazenie operatoroa indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *     
 *     Metody: zamien_kat_obrotu, zamien_kat_opadania, zamien_kat_rotacji
 *     zamieniaja poszczegolne katy podawane w stopniach na radiany.
 *
 *     Metoda: przesuniecie sluzy nam do wyznacznia wektora translacji.
 *     Metoda: translacja sluzy nam do zastosowania wektora translacji.
 *     Metoda: zmien_translacje sluzy nam do poprawnego ustawiania przeszkod.
 * 
 */
class Przestrzen_3D {

protected:

/*!
* \brief Wektor 3D opisujacy wierzcholki bryly
*/
 vector<Wektor3D> punkty;

/*!
* \brief Wektor 3D, o ktory przesowamy bryly
*/
 Wektor3D Translacja;

/*!
* \brief Wektor 3D opisujacy srodek bryly 
*/
 Wektor3D srodek;

/*!
* \brief Macierz obrotu zwiazana z zmiana kierunku drona (OZ) 
*/
 Macierz3x3 obrot;

/*!
* \brief Macierz obrotu zwiazana z opadaniem drona (OY)
*/
 Macierz3x3 opadanie;

/*!
* \brief Macierz obrotu zwiazana z obrotem srob (OX)
*/
 Macierz3x3 rotacja;

/*!
* \brief Kat obrotu drona (OZ)
*/
 double kat_obrotu;

/*!
* \brief Kat opadania drona (OY)
*/
 double kat_opadania;

/*!
* \brief Kat obrotu srob (OX)
*/
 double kat_rotacji;

/*!
* \brief Nazwa pliku tekstowego z oryginalem 
*/
 string nazwa_oryg;

/*!
* \brief Nazwa pliku tekstowego z kopia robocza
*/
 string nazwa_kopii;



public:


/*!
 * \brief Dostarcza nazwe kopii roboczej. 
 *
 * Zwraca:
 *    \return Nazwe pliku na ktorym wykonujemy operacje. 
 */
 string get_nazwa() {return nazwa_kopii;}


/*!
 * \brief Dostarcza wartosc, na ktorej mozemy pracowac. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Caly oryginalny wektor wierzcholkow. 
 */
 Wektor3D & operator [](int i) {return punkty[i];}


/*!
 * \brief Zamienia wartosc kata obrotu (OZ) drona ze stopni na radiany. 
 * Argumenty:
 *    \param[in] kat - kat obrotu drona w stopniach
 */
 void zamien_kat_obrotu(double kat);


/*!
 * \brief Zamienia wartosc kata opadania (OY) drona ze stopni na radiany. 
 * Argumenty:
 *    \param[in] kat - kat obrotu drona w stopniach
 */
 void zamien_kat_opadania(double kat);


/*!
 * \brief Zamienia wartosc kata rotacji (OX) sroby ze stopni na radiany. 
 * Argumenty:
 *    \param[in] kat - kat obrotu sroby w stopniach w stopniach
 */
 void zamien_kat_rotacji(double kat);


/*!
 * \brief Sluzy nam do wyznacznia wektora translacji.
 * Argumenty:
 *    \param[in] droga        - dlugosc wektora przesuniecia
 *    \param[in] opadanie     - macierz obrotu zwiazana z opadaniem drona (OY)
 *    \param[in] obrot        - macierz obrotu zwiazana z zmiana kierunku drona (OZ)
 *    \param[in] rotacja      - macierz obrotu zwiazana z obrotem srob (OX)
 *    \param[in] kat_obrotu   - kat obrotu drona (OZ)
 *    \param[in] kat_opadania - kat opadania drona (OY)
 *    \param[in] kat_rotacji  - kat obrotu srob (OX)
 *    \param[in] Translacja   - wektor 3D, o ktory przesowamy bryly
 */
 void przesuniecie(double droga);


/*!
 * \brief Sluzy nam do zastosowania wektora translacji.
 * Argumenty:
 *    \param[in] punkty     - wektor 3D opisujacy wierzcholki bryly
 *    \param[in] Translacja - wektor 3D, o ktory przesowamy bryly
 *    \param[in] srodek     - wektor 3D opisujacy srodek podstwy bryly 
 *    \param[in] nazwa_oryg - nazwa pliku tekstowego z oryginalem
 *    \param[in] obrot      - macierz obrotu zwiazana z zmiana kierunku drona (OZ)
 *    \param[in] rotacja    - macierz obrotu zwiazana z obrotem srob (OX)
 */
 void translacja();


/*!
 * \brief Metoda jest potrzebna do rozmieszczania przeszkod. 
 * Argumenty:
 *    \param[in] nowa_translacja - wektor o ktory ma zostac przesunieta nowa przeszkoda
 */
 void zmien_translacje(const Wektor3D &nowa_translacja)
 {
    Translacja=nowa_translacja;
 }
};

//opisane w ciele klasy
void Przestrzen_3D::zamien_kat_obrotu(double kat)
{
    kat_obrotu+=kat*M_PI/180;
}

//opisane w ciele klasy
void Przestrzen_3D::zamien_kat_opadania(double kat)
{
    kat_opadania=kat*M_PI/180;
}

//opisane w ciele klasy
void Przestrzen_3D::zamien_kat_rotacji(double kat)
{
    kat_rotacji+=kat*M_PI/180;
}


//opisane w ciele klasy
void Przestrzen_3D::przesuniecie(double droga)
{
    Wektor3D pom;
    pom[0]=droga;
    osY(opadanie,kat_opadania);
    osZ(obrot,kat_obrotu);
    osX(rotacja,kat_rotacji);
    
    Translacja=Translacja+(opadanie*(obrot*(pom)));
}


//opisane w ciele klasy
void Przestrzen_3D::translacja()
{
    ifstream plik;
    plik.open(nazwa_oryg);
    for(int i=0; i<(int)punkty.size(); i++)
    {
        plik>>punkty[i];
    }
    plik.close();
    
    for(int i=0; i<(int)punkty.size(); i++)
    {
        punkty[i]=obrot*((rotacja*(punkty[i]-srodek))+srodek)+Translacja;
    }
}
#endif