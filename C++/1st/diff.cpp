#include <iostream>

using namespace std;

template<
	typename T, 
	typename Tsize
>
void diff_of_arrays(T* minuend, T* subtrahend, T* difference, Tsize size, T defaultValue = 0)
{
	for (Tsize i = 0; i < size; i++)
		difference[i] = minuend[i] - subtrahend[i] + defaultValue;
}
