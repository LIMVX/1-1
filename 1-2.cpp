#define _USE_MATH_DEFINES

#include<cmath>
#include<iostream>

using namespace std;

/** 
* \brief Математическая функция, рассчитывающая значение объема
* \param const double R - значение радиуса
* \return Возвращает значение Volume - объема
**/
double getVolume(const double radius);

/** 
* \brief Математическая функция, рассчитывающая значение объема
* \param const double R - значение радиуса
* \return Возвращает значение SurfaceArea - площади
**/
double getSurfaceArea(const double radius);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
  cout <<"Введите число и нажмите Enter: \n";
  double radius;
  cin >> radius;
  const auto Volume = getVolume(radius);
  const auto SurfaceArea = getSurfaceArea(radius);
  cout <<" radius = "<< radius <<"\n Volume = "<< Volume <<" \n SurfaceArea = "<< SurfaceArea;
}

double getVolume(const double radius)
{
  return 4.0/3.0 * radius * M_PI;
}

double getSurfaceArea(const double radius)
{
  return 4 * M_PI * pow(radius, 2);
}