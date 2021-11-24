#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение numbersquared - число в степени 
* \param const double number1 - число 1
* \param const double number2 - число 2
* \param const double number3 - число 3
* \return Возвращает значение numbersquared - число в степени
**/

double getNumberSquared(const double number);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
  double number1, number2, number3;
  cin >> number1 >> number2 >> number3;
  const double numberSquared1 = getNumberSquared(number1);
  const double numberSquared2 = getNumberSquared(number2);
  const double numberSquared3 = getNumberSquared(number3);
  cout << " numbersquared1 = " << numberSquared1 << "\n numbersquared2 = " << numberSquared2 << "\n numbersquared3 = " << numberSquared3;
}

double getNumberSquared(const double number)
{
  if (number >= 0) 
  {
    return pow(number, 2);
  }
  else
  {
    return pow(number, 4);
  }
}