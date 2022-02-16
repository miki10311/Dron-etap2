#ifndef SWektor_HH
#define SWektor_HH

/*!
 *  \file
 *  \brief Definicja klasy SWektor
 *
 *  Plik zawiera definicje klasy SWektor, ktora
 *  jest szablonem do operacji na wektorach.
 *
 */

#include <iostream>

using namespace std;

/*!
 *  \brief Klasa 'SWektor' opisuje nam pojecie wektora i zawiera
 *  elementy niezbedne do wykonywania operacji na wektorach.
 *  
 *  Prywatne:
 *     tab                - tablica, dzieki ktorej zapisujemy macierz
 *     static aktualna    - ilosc aktualnie widzianych obiektow
 *     static wszystkie   - ilosc obiektow w sumie
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciazenia operatorow arytmetycznych umozliwiaja:
 *     - dodawanie i odejmowanie wektorow
 *     - mnozenie macierzy przez wektor
 *     - mnozenie i dzielenie wektora przez liczbe
 *     - przypisanie calemu wektorowi jednej wielkosci
 *
 *     Konstruktor bezparametryczny, kopiujacy, destruktor - dodane,
 *                    aby zrealizowac zliczanie ilosci obiektow
 *
 *     Metody wezaktualna() i wezwszystkie() przekazuja dalej ilosc obiektow.
 *
 */
template <typename typ, int ROZMIAR>
class SWektor {

/*!
* \brief Tablica, dzieki ktorej zapisujemy macierz
*/
  typ tab[ROZMIAR];

/*!
* \brief Aktualna liczba obiektow
*/
  static int aktualna;

/*!
* \brief Ilosc obiektow w sumie
*/
  static int wszystkie;


  public:


/*!
 * \brief Zwieksza wartosc aktualnej i ogolnej liczby obiektow
 * oraz inicjalizuje tablice dla wektora. 
 * Argumenty:
 *    \param[in] aktualna   - aktualna liczba obiektow
 *    \param[in] wszystkie  - liczba obiektow w sumie
 *    \param[in] tab[i]     - wektor, ktory zerojemy
 */
  SWektor() //konstruktor bezparametryczny
  {
    for(int i=0; i<ROZMIAR; i++)
    {
      tab[0]=0;
    }

    ++aktualna;
    ++wszystkie;
  }


/*!
 * \brief Kopiuje wektor. 
 * Argumenty:
 *    \param[in] aktualna   - aktualna liczba obiektow
 *    \param[in] wszystkie  - liczba obiektow w sumie
 *    \param[in] tab[i]     - wektor, z ktorego kopiujemy
 *    \param[in] wek[i]     - wektor, do ktorego kopiujemy
 */
  SWektor(const SWektor<typ,ROZMIAR> & wek) //konstruktor kopiujacy
  {
    tab[0]=wek[0];
    tab[1]=wek[1];
    tab[2]=wek[2];
    ++aktualna;
    ++wszystkie;
  }


/*!
 * \brief Zmniejsza wartosc aktualnej liczby obiektow, aby byla ona prawdziwa. 
 * Argumenty:
 *    \param[in] aktualna   - aktualna liczba obiektow
 */
  ~SWektor() //dekstruktor
  {
    --aktualna;
  }


/*!
 * \brief Dostarczaja zwracana zmienna do uzytku w programie. 
 * Argumenty:
 *    \param[in] aktualna  - aktualna liczba obiektow
 * Zwraca:
 *    \return Aktualna liczbe obiektow.
 */
  static int wezaktualna(){return aktualna;}


/*!
 * \brief Dostarczaja zwracana zmienna do uzytku w programie. 
 * Argumenty:
 *    \param[in] wszystkie  - liczba obiektow w sumie
 * Zwraca:
 *    \return Liczbe obiektow w sumie.
 */
  static int wezwszystkie(){return wszystkie;}


/*!
 * \brief Dostarcza zmienna, na ktorej mozemy pracowac. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Cala oryginalna zmienna. 
 */
  typ & operator[](int i);
  

 
/*!
 * \brief Dostarcza stala wartosc. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Sama wartosc.
 */
  typ operator[](int i) const;




/*!
 * \brief Realizuje dodawanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Wektor, jako suma wektorow.
 */
  SWektor<typ,ROZMIAR> operator + (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje przypisanie calemu wektorowi jednej wielkosci.
 * Argumenty:
 *    \param[in] tab[i]  - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] wartosc - liczba ktora ma byc na wszystkich wspolrzednych wektora
 * Zwraca:
 *    \return Zwraca dereferencje operatora.
 */
  SWektor<typ,ROZMIAR> & operator = (double wartosc)
  {
    for(int i=0; i<ROZMIAR; ++i)
    {
      tab[i]=wartosc;
    }
    return *this;
  }

/*!
 * \brief Realizuje odejmowanie dwoch wektorow (jeden z macierzy).
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Wektor, jako roznica wektorow.
 */
  SWektor<typ,ROZMIAR> operator - (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje mnozenie wektora przez macierz.
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - wektor
 * Zwraca:
 *    \return Liczbe, jako wynik dzialania.
 */
  typ operator * (SWektor<typ,ROZMIAR> skl2);




/*!
 * \brief Realizuje mnozenie wektora (z macierzy) przez liczbe. 
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - liczba
 * Zwraca:
 *    \return Wektor, jako wynik dzialania.
 */
  SWektor<typ,ROZMIAR> operator * (typ skl2);




/*!
 * \brief Realizuje dzielenie wektora (z macierzy) przez liczbe. 
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] Skl2   - liczba
 * Zwraca:
 *    \return Wektor, jako wynik dzialania.
 */
  SWektor<typ,ROZMIAR> operator / (typ skl2);

};



/*!
 * \brief Funkcja sluzy do przypisania wartosci Wektora ze standartowego wejscia.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream & operator >> (std::istream &Strm, SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm >> Wek[i];
  
  return Strm;
}


//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
int SWektor<typ,ROZMIAR>::aktualna=0;


//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
int SWektor<typ,ROZMIAR>::wszystkie=0;

/*!
 * \brief Funkcja sluzy do wypisywania watrosci Wektora na standardowe wyjscie.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Wek    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SWektor<typ,ROZMIAR> &Wek)
{
  for (int i=0; i<ROZMIAR; i++)
  Strm << Wek[i] << "\t";
  
  return Strm;
}



//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator + (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]+skl2[i];
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator - (SWektor<typ,ROZMIAR> skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]-skl2[i];
  
  return wynik; 
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ SWektor<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> skl2)
{
  typ suma=0;
  for (int i=0; i<ROZMIAR; i++)
  suma+=tab[i]*skl2[i];
  
  return suma;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator * (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]*skl2;
  
  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
SWektor<typ,ROZMIAR> SWektor<typ,ROZMIAR>::operator / (typ skl2)
{
  SWektor<typ,ROZMIAR> wynik;
  for (int i=0; i<ROZMIAR; i++)
  wynik[i]=tab[i]/skl2;

  return wynik;
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ & SWektor<typ,ROZMIAR>::operator[] (int i)
{
  return tab[i];
}



//opisane wyzej w ciele klasy
template <typename typ,  int ROZMIAR>
typ  SWektor<typ,ROZMIAR>::operator[] (int i) const
{
  return tab[i];
}




#endif