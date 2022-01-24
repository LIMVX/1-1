#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, size_t size);

/**
 * \brief Найти сумму элементов, имеющих нечетные индексы
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
int getSumOddIndex(const int* myArray, size_t size);

/**
 * \brief Подсчитать количество элементов массива, значения которых больше заданного числа А и кратных 5
 * \param myArray массив
 * \param size размер массива.
 * \param A заданное число А
 * \return сумму.
 */
 int getQuantity(int* myArray, size_t size, const int A);

/**
 * \brief Разделить все элементы массива с четными номерами на первый элемент
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
 void divideEvenIndexByTheFirstElement(int* myArray, size_t size);

 /**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

/**
 * \brief Варианы ввода массива.
 */
enum class ArrayInputWay
{
    randomly,
    manually
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
  size_t size = GetSize();
  if (size == 0)
    return 1;

  cout << "Как вы хотите заполнить массив?\n";
  cout << static_cast<int>(ArrayInputWay::randomly) << " - randomly,\n";
  cout << static_cast<int>(ArrayInputWay::manually) << " -manually.\n";
  cout << "Ваш выбор: ";
  int choice;
  cin >> choice;

  const auto chosen = static_cast<ArrayInputWay>(choice);
  int* myArray = nullptr;

  auto minValue = 0;
  auto maxValue = 0;
  cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
  cin >> minValue >> maxValue;
  if (maxValue <= minValue)
  {
    cout << "Введен неправильный диапазон!" << endl;
  }

  switch (chosen)
  {
    case ArrayInputWay::randomly:
    {
      myArray = FillRandomArray(size, minValue, maxValue);
      break;
    }
    case ArrayInputWay::manually:
    {
      myArray = FillUserArray(size);
      break;
    }
  }
  ArrayPrint(myArray, size);
  cout << getSumOddIndex(myArray, size);
  int A;
  cin>>A; 

  cout << getQuantity(myArray, size, A);

  divideEvenIndexByTheFirstElement(myArray, size);
  ArrayPrint(myArray, size);

  if (myArray != nullptr)
    { 
      delete[] myArray;
      myArray = nullptr;
    }
  return 0;
}

size_t GetSize()
{
  int size = 0;
  cout << "Введите размер массива"<< endl;
  cin >> size;
  if (size <= 0)
  {
    cout<< "Введён неверный размер";
    return 0;
  }
  return size;
}

int getSumOddIndex(const int* myArray, size_t size)
{
  int sum = 0;
  cout<<" Сумма элементов с нечетными индексами ";
  for(size_t index = 0; index < size; index++)
  {
    if(index % 2 != 0)
    {
      sum = sum + myArray[index];
    }
  }
  return sum; 
}

int getQuantity(int* myArray, size_t size, const int A)
{
  int quantity = 0;
  for(size_t index = 0; index < size; index++)
  {
    if ((myArray[index] % 5 == 0) && (myArray[index] > A))
    {
      quantity++;
    }
  }
  return quantity;
}
 
void divideEvenIndexByTheFirstElement(int* myArray, size_t size)
{
  for(size_t index = 1; index < size; index++)
  {
    if((index % 2 == 0) && (myArray[0] != 0))
    {
      myArray[index] = myArray[index]/myArray[0];
    }
  }
  myArray[0] = myArray[0]/myArray[0];
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    srand(time(NULL));
    const auto area = abs(minValue) + abs(maxValue) + 1;
    auto* array = new int[size];
    for (size_t index = 0; index < size; index++) {
        array[index] = rand() % area + minValue;
    }

    return array;
}

int* FillUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}
