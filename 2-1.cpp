#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std; 

/**
* \brief Математическая функция, рассчитывающая значение TrapezoidSurfaceArea - площадь трапеции
* \param const double height - высота трапеции
* \param const double trapezoidbase1 - основание трапеции 1
* \param const double trapezoidbase2 - основание трапеции 2
* \return Возвращает значение TrapezoidSurfaceArea - площадь трапеции
**/

double getTrapezoidSurfaceArea(const double height, const double trapezoidbase1, const double trapezoidbase2);

/**
* \brief Математическая функция, рассчитывающая значение CircleSurfaceArea - площадь круга
* \param const double radius - радиус
* \return Возвращает значение CircleSurfaceArea - площадь круга
**/

double getCircleSurfaceArea(const double radius);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  double height, trapezoidbase1, trapezoidbase2, radius;
  cin >> height >> trapezoidbase1 >> trapezoidbase2 >> radius;
  const auto TrapezoidSurfaceArea = getTrapezoidSurfaceArea(height, trapezoidbase1, trapezoidbase2);
  const auto CircleSurfaceArea = getCircleSurfaceArea(radius)
  cout<< "TrapezoidSurfaceArea=" << TrapezoidSurfaceArea  << "\n CircleSurfaceArea=" << CircleSurfaceArea ;
}

double getTrapezoidSurfaceArea(const double height, const double trapezoidbase1, const double trapezoidbase2)
{
  return height * (trapezoidbase1 + trapezoidbase2) / 2.0;
}

double getCircleSurfaceArea(const double radius)
{
  return pow(radius, 2) * M_PI;
}