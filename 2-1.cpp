#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
using namespace std;
/**
* \brief Математическая функция, рассчитывающая значение TrapezoidSurfaceArea - площадь трапеции
* \param height - высота трапеции
* \param trapezoidbase1 - основание трапеции 1
* \param trapezoidbase2 - основание трапеции 2
* \return Возвращает значение TrapezoidSurfaceArea - площадь трапеции
**/
double getTrapezoidArea( const double trapezoidbase1, const double trapezoidbase2, const double height);

/**
* \brief Математическая функция, рассчитывающая значение CircleSurfaceArea - площадь круга
* \param radius - радиус
* \return Возвращает значение CircleSurfaceArea - площадь круга
**/

double getCircleArea(const double radius);

enum class Measuares { TRAPEZOID_AREA = 1, CIRCLE_AREA };

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  cout << "Введите для" << "\nрасчета площади трапеции - "
  << static_cast<int>(Measuares::TRAPEZOID_AREA)
  << "\nрасчета площади круга - "
  << static_cast<int>(Measuares::CIRCLE_AREA)
  << "\n";

  int temp;
  cin >> temp;
  Measuares action = static_cast<Measuares>(temp);
  switch (action)
  {
    case Measuares::TRAPEZOID_AREA:
    {
      double trapezoidbase1;
      cin >> trapezoidbase1;
      double trapezoidbase2;
      cin >> trapezoidbase2;
      double height;
      cin >> height;
      const double trapezoidArea = getTrapezoidArea(trapezoidbase1, trapezoidbase2, height);
      cout << "Площадь трапеции = " << trapezoidArea;
      break;
    }
    case Measuares::CIRCLE_AREA:
    {
      double radius;
      cin >> radius;
      const double circleArea = getCircleArea(radius);
      cout << "Площадь круга = " << circleArea;
      break;
    }
    default:
    break;
  }
  return 0;
}
double getTrapezoidArea(const double trapezoidbase1, const double trapezoidbase2, const double height)
{
  return (trapezoidbase1 + trapezoidbase2) / 2 * height;
}
double getCircleArea( const double radius)
{
  return M_PI * pow(radius, 2);
}