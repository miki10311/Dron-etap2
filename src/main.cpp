#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>

#include "lacze_do_gnuplota.hh"
#include "Scena.hh"

using namespace std;


int main()
{
  PzG::LaczeDoGNUPlota Lacze;
  Scena scena(Lacze);
  Lacze.ZmienTrybRys(PzG::TR_3D);
  Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.

  Lacze.UstawZakresX(-50, 60);
  Lacze.UstawZakresY(-50, 60);
  Lacze.UstawZakresZ(-40, 60);

  Lacze.UstawRotacjeXZ(80, 60); // Tutaj ustawiany jest widok

  Lacze.Rysuj(); // Teraz powinno pojawic sie okienko gnuplota

  char symbol;
  double droga, kat, opadanie;
  Wektor3D liczba_obiektow;

  cout<<"Menu:"<<endl;
  cout<<"r - ruch dronem pod zadanym katem na zadana odleglosc"<<endl;
  cout<<"o - obrot drona w poziomie"<<endl;
  cout<<"d - dodaj przeszkode"<<endl;
  cout<<"u - usun przeszkode"<<endl;
  cout<<"m - wyswietl menu"<<endl;
  cout<<"k - koniec"<<endl;

  while (1)
  {
    cout<<endl<<endl;
    cout<<"Aktualna liczba obiektow: "<<liczba_obiektow.wezaktualna()<<endl;
    cout<<"Ogolna liczba obiektow: "<<liczba_obiektow.wezwszystkie()<<endl;
    cout<<"Podaj opcje z menu: "<<endl;
    cin >> symbol;

    switch (symbol)
    {
    
    case 'r':
      cout<<"Podaj kat opadania: ";
      cin>>opadanie;

      cout<<"Podaj droge: ";
      cin>>droga;

      if (droga>=0)
      {
        for (double i=0; i<droga && !scena.kolizja(); i++)
        {
          scena.ruch(0, opadanie, 1);
          Lacze.Rysuj();
          usleep(200000);
        }
      }
      else
      {
        cout<<"Droga nie moze byc ujemna!"<<endl;
        break;
      }
      cout<<"Wykonano poprawnie."<<endl;
      break;
      
      
    
    case 'o':
      cout<<"Podaj kat obrotu: ";
      cin>>kat;

      if (kat>=0)
      {
        for (double i=0; i<kat; i++)
        {
          scena.ruch(1, 0, 0);
          Lacze.Rysuj();
          usleep(200000);
        }
      }
      else
      {
        cout<<"Kat obrotu nie moze byc ujemny!"<<endl;
        break;
      }
      cout<<"Wykonano poprawnie."<<endl;
      break;

    
    case 'u':
      scena.usunPrzeszkode();
      Lacze.Rysuj();
      break;


    case 'd':
      scena.dodajPrzeszkode();
      break;


    case 'm':
      cout<<"Menu:"<<endl;
      cout<<"r - ruch dronem pod zadanym katem na zadana odleglosc"<<endl;
      cout<<"o - obrot drona w poziomie"<<endl;
      cout<<"d - dodaj przeszkode"<<endl;
      cout<<"u - usun przeszkode"<<endl;
      cout<<"m - wyswietl menu"<<endl;
      cout<<"k - koniec"<<endl;
      break;


    case 'k':
      return 0;
      break;


    default:
      cout<<"ZLA OPCJA!!!"<<endl;
    }
  }
}
