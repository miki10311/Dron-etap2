#ifndef SMacierz_HH
#define SMacierz_HH

/*!
 *  \file
 *  \brief Definicja klasy SMacierz
 *
 *  Plik zawiera definicje klasy SMacierz, ktora
 *  jest szablonem do operacji na macierzach.
 *
 */

#include "Wektor.hh"
#include <algorithm>
#include <iostream>
#include <cmath>


/*!
 *  \brief Klasa 'SMacierz' opisuje nam pojecie macierzy i zawiera
 *  elementy niezbedne do wykonywania operacji na macierzach.
 *  
 *  Prywatne:
 *     tab - tablica (z klasy SWektor), dzieki ktorej zapisujemy macierz.
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Metoda Wyznacznik() liczy wyznacznik macierzy.
 *
 *     Przeciazenie operatora mnoznia realizuje mnozenie macierzy razy wektor.
 */
template <typename typ, int ROZMIAR>
class SMacierz {

/*!
* \brief Tablica, dzieki ktorej zapisujemy macierz
*/
  SWektor<typ,ROZMIAR> tab[ROZMIAR];

  public:

/*!
 * \brief Dostarcza zmienna, na ktorej mozemy pracowac. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Cala oryginalna zmienna. 
 */
  SWektor<typ,ROZMIAR> & operator[](int i);



/*!
 * \brief Dostarcza stala wartosc. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Sama wartosc.
 */
  SWektor<typ,ROZMIAR> operator[](int i) const;



/*!
 * \brief Realizuje liczenie wyznacznika macierzy metoda Gaussa.
 * Argumenty:
 *    brak
 *
 * Zmienne:
 *    kop=*this - kopia macierzy
 *    wynik     - zmienna przechowujaca aktualna wartosc wyznacznika
 *    ind       - zmienna zabezpieczajaca wyjscie poza macierz
 *
 * Zwraca:
 *    \return Liczbe, bedaca wyznacznikiem macierzy.
 */
  typ Wyznacznik();



/*!
 * \brief Realizuje mnozenie macierzy przez wektor.
 * Argumenty:
 *    \param[in] tab[i] - mamy dostep do macierzy dzieki przeciazeniu
 *    \param[in] wek    - wektor, przez ktory mnozymy macierz
 * Zwraca:
 *    \return Wektor, jako wynik mnozenia.
 */
  SWektor<typ,ROZMIAR> operator * (SWektor<typ,ROZMIAR> wek);
};




/*!
 * \brief Dostarcza zmienna, na ktorej mozemy pracowac. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Cala oryginalna zmienna. 
 */
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> & SMacierz<typ,ROZMIAR>::operator[](int i)
{
    return tab[i];
}



/*!
 * \brief Dostarcza stala wartosc. 
 * Argumenty:
 *    \param[in] i - indeks
 * Zwraca:
 *    \return Sama wartosc.
 */
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SMacierz<typ,ROZMIAR>::operator[](int i) const
{
    return tab[i];
}



/*!
 * \brief Funkcja sluzy do wypisywania watrosci Macierzy na standardowe wyjscie.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu ostream.
 */
template <typename typ, int ROZMIAR>
std::ostream & operator << (std::ostream &Strm, const SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm << Mac[i] << std::endl;
    }
    return Strm;
}


/*!
 * \brief Funkcja sluzy do przypisania watrosci Macierzy ze standartowego wejscia.
 * Argumenty:
 *    \param[in] operator     - zawiera symbol operatora                            
 *    \param[in] Strm, Mac    - zawieraja argumenty do prawidlowego dzialania przeciazenia operatora                                  
 * Zwraca:
 *    \return Obiekt typu istream.
 */
template <typename typ, int ROZMIAR>
std::istream& operator >> (std::istream &Strm, SMacierz<typ,ROZMIAR> &Mac)
{
    for (int i=0; i<ROZMIAR; i++)
    {
        Strm >> Mac[i];
    }
    return Strm;
}




//opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
SWektor<typ,ROZMIAR> SMacierz<typ,ROZMIAR>::operator * (SWektor<typ,ROZMIAR> wek)
{
    SWektor<typ,ROZMIAR> wynik;
    for (int i=0; i<ROZMIAR; i++)
    wynik[i]=tab[i]*wek;

    return wynik;
}



// opisane wyzej w ciele klasy
template <typename typ, int ROZMIAR>
typ SMacierz<typ,ROZMIAR>::Wyznacznik()
{
    SMacierz<typ,ROZMIAR> kop=*this;
    typ wynik=1;
    int ind=0;
    
    for (int i=0; i<ROZMIAR; i++)
    {
        while (kop[i][i]==0)
        {
            if (++ind==ROZMIAR)
            {     
                break;
            }
            else if (kop[i][i]==0)
            {
                std::swap(kop[i],kop[ind]);
                wynik=wynik*(-1); 
            }
        }
        
        if(kop[i][i]==0)
        return 0;
         
        for (int j=i+1; j<ROZMIAR; j++)
        {
            if(kop[i][i]==0)
            return 0;

            kop[j]=kop[j]-(kop[i]*kop[j][i]/kop[i][i]);
        
            if(kop[i][i]==0)
            return 0;
        
        }
        wynik=kop[i][i] * wynik;
    }
    return wynik;
}

#endif