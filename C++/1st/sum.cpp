#include <iostream>

using namespace std;

template<typename T>
T summ_of_numbers(T first, T second)
{
	return first + second;
}

int main()
{
	int first;
	double second;
	cin >> first >> second;
	cout << summ_of_numbers(first, second) << endl;
	return 0;
}
