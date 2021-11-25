#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция которая расчитывает значение функции y в зависимости от значения переменной x 
* \param  a - переменная 1
* \param  x - переменная 2
* \return Возвращает значение функции 
**/

double getx(const double a, const double x, const double b);

/**
* \brief Математическая функция, рассчитывающая значение функции y 
* \param  a - переменная 1
* \param  x - переменная 2
* \return Возвращает значение функции y 
**/

double gety(const double a, const double x, const double b);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  const double a = 2.8;
  const double b = 1.2;
  double x;
  cin >> x;
  const auto y = gety(a, x, b);
  cout << "y = " << y;
}

double getx(const double a, const double x, const double b)
{
  if (x < b)
  {
    return a * pow(x, 2) + 4;
  }
  else 
  {
    return (a + 4 * x) * sqrt(pow(x, 2 * a));
  }
}

double gety(const double a, const double x, const double b)
{
  return getx(a, x, b); 
}