#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y 
* \param const double a - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение функции y 
**/

double gety(const double a, const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  const double a = 2.8;
  double x;
  cin >> x;
  const auto y = gety(a, x);
  cout << "y = " << y;
}

double gety(const double a, const double x)
{
  if (x < 1.2)
  {
    return a * pow(x, 2) + 4;
  }
  else 
  {
    return (a + 4 * x) * sqrt(pow(x, 2 * a));
  }
}