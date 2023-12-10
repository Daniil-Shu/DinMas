#include <iostream>

using namespace std;

/**
 * @brief Метод, возвращающий заполненный пользователем массив.
 * @param size размер массива.
 * @return заполненный массив.
 */
int* inputArray(const size_t size);

/**
 * @brief ввод и проверка на корректное число элементов массива.
 * @return введенное число элементов массива.
 */
size_t inputSize();

/**
 * @brief вывод массива.
 * @param массив
 * @param size размер массива.
 */
void outputArray(int* array, const size_t size);

int main()
{
	size_t arraySize;

	arraySize = inputSize();

	int* array = nullptr;

	array = inputArray(arraySize);
	
	cout << "Введенный массив:\n";
	outputArray(array, arraySize);

	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
  
	return 0;
}

size_t inputSize()
{
	int size = -1;
	cout << "Введите размер массива: ";
	cin >> size;

	if (size <= 0)
	{
		throw runtime_error("Размер массива не может быть меньше нуля");
	}
	size_t result = static_cast<size_t>(size);

	return result;
}

int* inputArray(const size_t size)
{
	int* array = new int[size];

	cout<<"Введите данные массива:\n";

	for (size_t index = 0 ; index < size; index++) {
		if (!(cin >> array[index])) 
		{
			throw runtime_error("Ошибка при чтении данных");
		}
	}

	return array;
}

void outputArray(int* array, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}
}
