#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение функции y
**/

double gety(const double x);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  const auto y = gety(x);
  cout<< "y = " << y;
}

double gety(const double x)
{
  for(double x = 0.4; x <= 1; x = x + 0.05)
  {
    return x + sqrt(x) + pow(x, 1.0/3.0) - 2.5;
  }
}