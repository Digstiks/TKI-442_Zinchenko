#include <iostream>
#include <string>
using namespace std;

/**
 * Set numbers in a array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void setNumArray(const size_t size, int* array);

/**
 * Get numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
void getArray(int* array, const size_t size);

/**
 * Get min numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int getMin(int* array, const size_t size);

/**
 * Get max numbers of array.
 * @param size Size of array.
 * @param array Dinamic array.
 */
int getMax(int* array, const size_t size);

int main()
{
	// Ввод размера массива
	cout << "Input size array: ";
	int n;
	cin >> n;

	if (n < 0)
	{
		cout << "Incorrect size. Value has to be greater zero." << '\n';
		cout << "Input size array: ";
	}

	cout << "Size array: " << n << '\n';

	// Создание массива с размером n
	int* arr = new int[n];
	setNumArray(n, arr);
	getArray(arr, n);

	cout << '\n' << "Minimum number of array: ";
	cout << getMin(arr, n);
	cout << '\n' << "Maximum number of array: ";
	cout << getMax(arr, n) << '\n';

	if (arr != nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}

	return 0;
}

void setNumArray(const size_t size, int* array)
{
	cout << '\n' << "Set nums array" << '\n';

	for (size_t i = 0; i < size; i++)
	{
		int x;
		cout << i + 1 << ": ";
		cin >> x;

		array[i] = x;
	}
}

void getArray(int* array, const size_t size)
{
	cout << '\n' << "Array:" << '\n';

	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << ' ';
	}

	cout << '\n';
}

int getMin(int* array, const size_t size)
{
	int minNum = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (minNum > array[i])
		{
			minNum = array[i];
		}
	}

	return minNum;
}

int getMax(int* array, const size_t size)
{
	int maxNum = array[0];

	for (size_t i = 0; i < size; i++)
	{
		if (maxNum < array[i])
		{
			maxNum = array[i];
		}
	}

	return maxNum;
}