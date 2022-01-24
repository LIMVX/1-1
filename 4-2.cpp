#include <cmath>
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
 *\brief Вычисление нового размера массива.
 *\param size размер массива.
 *\return Размер нового массива.
*/
size_t NewSize(const int* myArray, size_t size);

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
 * \brief Поиск последнего отрицательного элемента
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
int getLastNegativeElement(int* myArray, size_t size);

/**
 * \brief Заменить последний отрицательный элемент массива предпоследним элементом массив
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
void replace(int* myArray, size_t size);

/**
 * \brief Удалить из него все элементы, первая цифра которых четная
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
 int* deleteElements(int* myArray, size_t size);

/**
 * \brief Из элементов массива D сформировать массив A той же размерности
 * \param myArray массив
 * \param size размер массива.
 * \return сумму.
 */
 int* createNewArray(int* myArray, size_t size);

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
    cout << static_cast<int>(ArrayInputWay::manually) << " - manually.\n";
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
    cout << "Массив с заменённым последним отрицательным элементом на предпоследний: " << endl;

    replace(myArray, size);
    ArrayPrint(myArray, size);


    int* newArray2 = new int[NewSize(myArray, size)];
    cout << "Массив с удалёнными элементами" << endl;
    newArray2 = deleteElements(myArray, size);
    ArrayPrint(newArray2, size);

    if (newArray2 != nullptr) {

        delete[] newArray2;
        newArray2 = nullptr;

    }

    cout << "Заменённый массив по формулам" << endl;
    newArray2 = createNewArray(myArray, size);
    ArrayPrint(newArray2, size);

    if (myArray != nullptr) {

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
size_t NewSize(const int* myArray, size_t size) 
{
    size_t count = 0;
    for (size_t index = 0; index < size; index++) 
    {
      int first;
      while(myArray[index]>0)
      {
        first = myArray[index] % 10;

      }
      if (myArray[index] / 10 % 2 == 0) 
      {
        count++;
      }
    }
    size = size - count;
    return size;
}

int getLastNegativeElement(int* myArray, size_t size)
{
  int lastNegativeElementIndex = 0;

  for (size_t index = 0; index < size; index++) 
  {
    if (myArray[index] < 0) 
    {
      lastNegativeElementIndex = index;
    }
  }
  return lastNegativeElementIndex;
}

void replace(int* myArray, size_t size)
{
  int lastNegativeElementIndex = getLastNegativeElement(myArray, size);
  myArray[lastNegativeElementIndex] = myArray[size - 2];
}

int* createNewArray(int* myArray, size_t size)
{
    int temprary = 0;
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }
    int* newArray = new int[size];
    for (size_t index = 0, newindex = 0; index < size; index++) 
    {
        if (index % 2 == 0) 
        {
            newArray[newindex] = pow(myArray[index], 2);
        }
        else 
        {
            newArray[newindex] = 2.0 * myArray[index];
        }
        newindex++;
    }

    return newArray;
}

int* deleteElements(int* myArray, size_t size)
{
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    size_t count = 0;
    for (size_t index = 0; index < size; index++) 
    {
        if (myArray[index] / 10 % 2 == 0) 
        {
            count++;
        }
    }

    int* newArray = new int[size - count];
    for (size_t index = 0, newindex = 0; index < size; index++) 
    {
        if (!(myArray[index] / 10 % 2 == 0)) 
        {
            newArray[newindex] = myArray[index];
            newindex++;
        }
    }
    return newArray;
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