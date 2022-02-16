#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

/*!
 *  \file
 *  \brief Definicja typu Macierz3x3 i macierzy obrotow.
 *
 *  Plik zawiera definicje typu Macierz3x3, oraz
 *  definiuje macierze obrotow wzgledem trzech osi.
 *
 */

#include "Macierz.hh"

using namespace std; 

/*!
* \brief Definicja typu Macierz3x3
*/
typedef SMacierz<double,3> Macierz3x3;


/*!
 * \brief Funkcja zeruje poczatkowe wartosci w macierzy 3x3.
 *
 * Argumenty:
 *    \param[in] M - macierz, ktora zerujemy
 *
 */
inline void zeruj(Macierz3x3 &M)
{
    for(int kol=0; kol<3; ++kol)
    {
        for(int wie=0; wie<3; ++wie)
        {
            M[wie][kol]=0;
        }
    }
}


/*!
 * \brief Funkcja osZ opisuje macierz obrotu wzgledem osi OZ.
 *
 * Argumenty:
 *    \param[in] Mz  - macierz obrotu wzgledem osi OZ
 *    \param[in] kat - kat obrotu wzgledem osi OZ
 *
 */
inline void osZ(Macierz3x3 &Mz,double kat)
{
    zeruj(Mz);
    Mz[0][0]=cos(kat);
    Mz[0][1]=-sin(kat);
    Mz[1][0]=sin(kat);
    Mz[1][1]=cos(kat);
    Mz[2][2]=1;
}


/*!
 * \brief Funkcja osY opisuje macierz obrotu wzgledem osi OY.
 *
 * Argumenty:
 *    \param[in] My  - macierz obrotu wzgledem osi OY
 *    \param[in] kat - kat obrotu wzgledem osi OY
 *
 */
inline void osY(Macierz3x3 &My,double kat)
{
    zeruj(My);
    My[0][0]=cos(kat);
    My[0][2]=sin(kat);
    My[1][1]=1;
    My[2][0]=-sin(kat);  
    My[2][2]=cos(kat);  
}


/*!
 * \brief Funkcja osX opisuje macierz obrotu wzgledem osi OX.
 *
 * Argumenty:
 *    \param[in] Mx  - macierz obrotu wzgledem osi OX
 *    \param[in] kat - kat obrotu wzgledem osi OX
 *
 */
inline void osX(Macierz3x3 &Mx,double kat)
{
    zeruj(Mx);
    Mx[0][0]=1;
    Mx[1][1]=cos(kat);
    Mx[1][2]=-sin(kat);
    Mx[2][1]=sin(kat);  
    Mx[2][2]=cos(kat);  
}
#endif