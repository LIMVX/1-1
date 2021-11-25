#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param x - переменная
* \return Возвращает значение функции y
**/

double gety(const double x);

/**
* \brief Узнает, существует ли функция в заданной точке \a x.
* \param x Заданная точка.
* \return true, если значение функции в заданной точке \a x существует.
*/
bool isCalculated(double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  const double x = 0.4;
  const auto y = gety(x);
}

double gety(const double x)
{
  for(double x = 0.4; x <= 1; x = x + 0.05)
  {
    cout << "y = " << x + sqrt(x) + pow(x, 1.0/3.0) - 2.5 << endl;
  }
  return 1;
}

bool isCalculated(const double x)
{
  return x >= 0;
}