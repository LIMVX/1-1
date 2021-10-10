#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение R
* \param const double R1 - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double R2 - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double R3 - константа, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает значение R
**/
double getR(const double R1, const double R2, const double R3);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
  cout<<" Введите три числа и нажмите Enter: \n ";
  double R1, R2, R3;
  cin >> R1 >> R2 >> R3;
  const auto R=getR(R1, R2, R3);
  cout<<" R1= "<< R1 <<" R2= "<< R2 <<" R3= "<< R3 <<" R= "<< R;
}

double getR(const double R1, const double R2, const double R3)
{
  return 1.0/(1.0/R1 + 1.0/R2 + 1.0/R3);
}