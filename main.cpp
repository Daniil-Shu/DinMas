#include <iostream>
#include <stdexcept>

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
	try
	{
		size_t arraySize = inputSize();
	
		int* array = inputArray(arraySize);
		
		cout << "Введенный массив:\n";
		outputArray(array, arraySize);

		if (array != nullptr)
		{
			delete[] array;
			array = nullptr;
		}
	} catch (logic_error e){
		cout << e.what() << '\n';
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
		throw logic_error("Размер массива не может быть меньше нуля");
	}

	return static_cast<size_t>(size);
}

int* inputArray(const size_t size)
{
	int* array = new int[size];

	cout<<"Введите данные массива:\n";

	for (size_t index = 0 ; index < size; index++) {
		if (!(cin >> array[index])) 
		{
			throw logic_error("Ошибка при чтении данных");
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