/*!
 *  \file
 *  \brief Definicja klasy Scena
 *
 *  Plik zawiera definicje klasy Scena, ktora
 *  jest ostatecznym zobrazowaniem przestrzeni dla drona.
 *
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <list>
#include "lacze_do_gnuplota.hh"
#include "Dno.hh"
#include "Woda.hh"
#include "Dron.hh"
#include "Wymiary.hh"
#include "Przeszkoda_Plaszczyzna.hh"
#include "Przeszkoda_Pret.hh"
#include "Przeszkoda_Prostopadloscian.hh"



/*!
 *  \brief Klasa 'Scena' jest ostatecznym zobrazowaniem przestrzeni dla drona.
 *  
 *  Prywatne:
 *     przeszkody - tablica z przeszkodami
 *     dno        - reprezentacja dna
 *     woda       - reprezentacja wody
 *     dron       - reprezentacja drona
 *     Lacze      - lacze do GNUPlota
 *
 *  Publiczne:
 *     Dwa przeciazenia operatorow indeksowania, abysmy mogli pracowac
 *     na potrzebnych danych nie zmieniajac oryginalu.
 *
 *     Przeciazenia operatorow arytmetycznych umozliwiaja:
 *     - dodawanie i odejmowanie wektorow
 *     - mnozenie macierzy przez wektor
 *     - mnozenie i dzielenie wektora przez liczbe
 *
 *     Konstruktor bezparametryczny, kopiujacy, destruktor - dodane,
 *                    aby zrealizowac zliczanie ilosci obiektow
 *
 *     Metody wezaktualna() i wezwszystkie() przekazuja dalej ilosc obiektow.
 *     Metody dodajPrzeszkode() i usunPrzeszkode, zgodnie ze swoimi nazwami
 *     dodaja i usuwaja przeszkody.
 */
class Scena {

/*!
* \brief Lista z przeszkodami dla drona
*/
std::list < std::shared_ptr<Przeszkoda> > przeszkody;

/*!
* \brief Reprezentacja dna
*/
Dno *dno;

/*!
* \brief Reprezentacja wody
*/
Woda *woda;

/*!
* \brief Reprezentacja drona
*/
Dron dron;

/*!
* \brief lacze do GNUPlota
*/
PzG::LaczeDoGNUPlota &Lacze;

public:


/*!
 * \brief Polaczenie Sceny z GNUPlotem. 
 *
 * Argumenty:
 *    \param[in] Lacze - lacze do GNUPlota
 */
 Scena(PzG::LaczeDoGNUPlota &Lacze);


/*!
 * \brief Sluzy do sterowania dronem
 *
 * Argumenty:
 *    \param[in] droga    - dlugosc wektora przesuniecia
 *    \param[in] opadanie - macierz obrotu zwiazana z opadaniem drona (OY)
 *    \param[in] obrot    - macierz obrotu zwiazana z zmiana kierunku drona (OZ)
 */
 void ruch(double opadanie, double obrot, double droga);



/*!
 * \brief Opisuje zachowanie drona podczas kolizji.
 *
 * Argumenty:
 *    \param[in] przeszkody - lista z przeszkodami
 *    \param[in] dron       - reprezentacja drona
 *    \param[in] woda       - reprezentacja wody
 *    \param[in] dno        - reprezentacja dna
 */
 bool kolizja();
 

/*!
 * \brief Dodaje wybrane przeszkody oddalone od srodka ukladu o zadany wektor.
 *
 * Argumenty:
 *    \param[in] przeszkody - lista z przeszkodami
 */
 void dodajPrzeszkode();


/*!
 * \brief Usuwa wybrane przeszkody z listy (wedlug podanego numeru w liscie).
 *
 * Argumenty:
 *    \param[in] przeszkody - lista z przeszkodami
 */
 void usunPrzeszkode();
};







//opisane w ciele klasy
void Scena::ruch(double obrot, double opadanie, double droga)
{
  dron.Sterowanie(obrot,opadanie,droga);
}


//opisane w ciele klasy
bool Scena::kolizja()
{
  for(std::list < std::shared_ptr<Przeszkoda> >::iterator iter=przeszkody.begin(); iter!=przeszkody.end(); iter++)
  {
    if((*iter)->kolizja(dron))
    {
      return true;
    } 
  }
  
  if(woda->kolizja(dron))
  {
    cout<<"KOLIZJA z woda!"<<endl;
    return true;
  }
  else if(dno->kolizja(dron))
  {
    cout<<"KOLIZJA z dnem!"<<endl;
    return true;
  }

  return false;
}


//opisane w ciele klasy
Scena::Scena(PzG::LaczeDoGNUPlota &Lacze) : Lacze(Lacze)
{
  Wektor3D polozenie;
  przeszkody.push_back(std::make_shared<Przeszkoda_Prostopadloscian>(10,10,10,"bryly/prost1.dat","bryly/prost_zap1.dat"));
  std::list < std::shared_ptr<Przeszkoda> >::iterator itera=przeszkody.end();
  itera--;
  (*(itera))->zapis_oryg();
  polozenie[0]=0;
  polozenie[1]=30;
  polozenie[2]=-5;
  (*(itera))->zmien_translacje(polozenie);
  (*(itera))->translacja();
  (*(itera))->zapis();

  przeszkody.push_back(std::make_shared<Przeszkoda_Plaszczyzna>(0,10,10,"bryly/plasz3.dat","bryly/plasz_zap3.dat"));
  std::list < std::shared_ptr<Przeszkoda> >::iterator ite=przeszkody.end();
  ite--;
  (*(ite))->zapis_oryg();
  polozenie[0]=25;
  polozenie[1]=5;
  polozenie[2]=5;
  (*(ite))->zmien_translacje(polozenie);
  (*(ite))->translacja();
  (*(ite))->zapis();
  
  przeszkody.push_back(std::make_shared<Przeszkoda_Pret>(0,10,10,"bryly/pret2.dat","bryly/pret_zap2.dat"));
  std::list < std::shared_ptr<Przeszkoda> >::iterator iter=przeszkody.end();
  iter--;
  (*(iter))->zapis_oryg();
  polozenie[0]=25;
  polozenie[1]=20;
  polozenie[2]=0;
  (*(iter))->zmien_translacje(polozenie);
  (*(iter))->translacja();
  (*(iter))->zapis();


  dno = new Dno(100,-30,10,"bryly/dno.dat","bryly/dno_zap.dat");
  woda = new Woda(100,30,10,WYS_FAL,"bryly/woda.dat","bryly/woda_zap.dat");    
  dno->zapis();
  dno->zapis_oryg();
  woda->zapis();
  woda->zapis_oryg();

  Lacze.DodajNazwePliku("bryly/dno_zap.dat");
  Lacze.DodajNazwePliku("bryly/woda_zap.dat");
  Lacze.DodajNazwePliku("bryly/figura_zap.dat");
  Lacze.DodajNazwePliku("bryly/prost_zap1.dat");
  Lacze.DodajNazwePliku("bryly/pret_zap2.dat");
  Lacze.DodajNazwePliku("bryly/plasz_zap3.dat");
  Lacze.DodajNazwePliku("bryly/sroba1_zap.dat");
  Lacze.DodajNazwePliku("bryly/sroba2_zap.dat");
}


//opisane w ciele klasy
void Scena::dodajPrzeszkode()
{
  char typ;
  cout<< "Wybierz rodzaj przeszkody do dodania: "<<endl;
  cout<< "c-aby dodac prostopadloscian"<<endl;
  cout<< "d-aby dodac pret"<<endl;
  cout<< "f-aby dodac plaszczyzne"<<endl;

  while(1)
  {
  cin>>typ;
  if(typ=='c')
  przeszkody.push_back(std::make_shared<Przeszkoda_Prostopadloscian>(10,10,10,"bryly/prost"+to_string(przeszkody.size()+1)+".dat","bryly/prost_zap"+to_string(przeszkody.size()+1)+".dat"));
  else if(typ=='d')
  przeszkody.push_back(std::make_shared<Przeszkoda_Pret>(0,10,10,"bryly/pret"+to_string(przeszkody.size()+1)+".dat","bryly/pret_zap"+to_string(przeszkody.size()+1)+".dat"));
  else if(typ=='f')
  przeszkody.push_back(std::make_shared<Przeszkoda_Plaszczyzna>(0,10,10,"bryly/plasz"+to_string(przeszkody.size()+1)+".dat","bryly/plasz_zap"+to_string(przeszkody.size()+1)+".dat"));
  else
  {
    cout<<"Nie rozpoznano typu przeszkody!"<<endl;
    break;
  }

  cout<< "Wprowadz wspolrzedne polozenia srodka przeszkody: "<<endl;
  Wektor3D polozenie;
  for(int i=0; i<3; ++i)
  {
    cin>>polozenie[i];
  }

  std::list < std::shared_ptr<Przeszkoda> >::iterator iter=przeszkody.end();
  iter--;
  (*(iter))->zapis_oryg();
  (*(iter))->zmien_translacje(polozenie);
  (*(iter))->translacja();
  (*(iter))->zapis();
  string nowa=(*(iter))->get_nazwa();
  Lacze.DodajNazwePliku(nowa.c_str());
  Lacze.Rysuj();
  cout<<"Dodano przeszkode! "<<endl;
  break;
  }
}


//opisane w ciele klasy
void Scena::usunPrzeszkode()
{
  std::list < std::shared_ptr<Przeszkoda> >::iterator iter=przeszkody.begin();

  iter--;
  for(unsigned int i=1; i-1<przeszkody.size(); ++i)
  {
    iter++;
    string nowa=(*(iter))->get_nazwa();
    cout<<"Przeszkoda nr "<<i<<" ze sciezka dostepu: "<<nowa.c_str()<<endl;
  }
  iter++;

  unsigned int numer;
  cout<<"Podaj numer przeszkody z listy: "<<endl;
  cin>>numer;

  if(numer>przeszkody.size() || numer<=0)
  {
    cout<<"Takiej liczby nie ma na liście powyżej! "<<endl;
  }
  else
  {
    for(unsigned int i=0; i<numer; ++i)
    {
      iter++;
    }

    string nowa=(*(iter))->get_nazwa();
    Lacze.UsunNazwePliku(nowa.c_str());
    przeszkody.erase(iter);
    cout<<"Usunieto przeszkode! "<<endl;
  }
}
