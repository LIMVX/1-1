#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
/**
 * \brief Рассчитывает значение функции в заданной точке \a x.
 * \param x Заданная точка.
 * \return Значение функции в заданной точке \a x.
 */
double myFunc(double x);

/**
 * \brief Узнает, существует ли функция в заданной точке \a x.
 * \param x Заданная точка.
 * \return true, если значение функции в заданной точке \a x существует.
 */
bool isCalculated(double x);

/**
 * \brief Точка входа в программу.
 * \return В случаен успеха код 0.
 */
int main()
{
    const double X_START = 0.4;
    const double X_FINISH = 1.0;
    const double STEP = 0.05;
    double x = X_START;
    while(x <= X_FINISH)
    {
        if (isCalculated(x))
        {
            const double y = myFunc(x);
            cout << "x = " << setw(5) << left << setprecision(5) << x << " y = " << y << "\n";
        }
        else
        {
            cout << "x = " << x << " y = не существует" << "\n";
        }

        x += STEP;
    }
    return 0;
}

double myFunc(const double x)
{
    return x + sqrt(x) + cbrt(x) - 2.5;
}

bool isCalculated(const double x)
{
    return x >= 0;
}