#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение a
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение a
**/
double getA(const double x, const double y);

/**
* \brief Математическая функция, рассчитывающая значение b
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение b
**/
double getB(const double x, const double y);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
	const double x = 0.335;
	const double y = 0.025;
	const auto a = getA(x, y);
	const auto b = getB(x, y);
	cout << " x = " << x << "\n y = " << y << "\n a = " << a << "\n b = " << b;
	return 0;
}

double getA(const double x, const double y)
{
  return 1 + x + pow(x,2)/2 + pow(x, 3)/3 + pow(x, 4)/4;
}

double getB(const double x, const double y) 
{
  return x * (sin(pow(x, 3)) + pow(cos(y), 2));
} 