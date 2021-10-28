#define _USE_MATH_DEFINES

#include<cmath>
#include<iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение resistance - общее сопротивление при параллельном соединении
* \param const double resistance1 - сопротивление 1
* \param const double resistance2 - сопротивление 2
* \param const double resistance3 - сопротивление 3
* \return Возвращает значение R - общее сопротивление при параллельном соединении
**/
double getresistance(const double resistance1, const double resistance2, const double resistance3);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
  cout<<" Введите три числа и нажмите Enter: \n ";
  double resistance1, resistance2, resistance3;
  cin >> resistance1 >> resistance2 >> resistance3;
  const auto resistance = getresistance(resistance1, resistance2, resistance3);
  cout<<" resistance1= "<< resistance1 <<" resistance2= "<< resistance2 <<" resistance3= "<< resistance3 <<" resistance= "<< resistance;
}

double getresistance(const double resistance1, const double resistance2, const double resistance3)
{
  return 1.0/(1.0/resistance1 + 1.0/resistance2 + 1.0/resistance3);
}