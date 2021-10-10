#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение V
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double R - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение V
**/
double getV(const double R);

/**
* \brief Математическая функция, рассчитывающая значение V
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double y - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double R - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение V
**/
double getS(const double R);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
  cout <<"Введите число и нажмите Enter: \n";
  double R;
  cin >> R;
  const auto V=getV(R);
  const auto S=getS(R);
  cout <<" R= "<< R <<"\n V= "<< V <<" \n S= "<< S;
}

double getV(const double R)
{
  return 4.0/3.0 * R * M_PI;
}

double getS(const double R)
{
  return 4 * M_PI * pow(R, 2);
}