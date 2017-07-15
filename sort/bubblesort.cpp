#include <array>
#include <iostream>

using namespace std;

template<size_t size>
void bubble_sort(array<size_t, size> &numbers);

int main(int argc, const char **argv)
{
	array<size_t, 5> numbers = {11, 3, 4, 6, 1};
	
	cout << "Example of bubble sort !!" << endl;
	cout << "11, 3, 4, 6, 1 sort " << endl << endl;

	bubble_sort(numbers);

	for(auto &&number : numbers)
	{
		cout << number << " ";
	}

	cout << endl;

	return 0;
}

template<size_t size>
void bubble_sort(array<size_t, size> &numbers)
{
	for(size_t i = 0, max_size = size-1; i < max_size; ++i)
	{
		for(size_t j = 0; j < max_size - i; ++j)
		{
			if(numbers[j] <= numbers[j+1])
			{
				continue;
			}

			swap(numbers[j], numbers[j+1]);
		}
	}
}

