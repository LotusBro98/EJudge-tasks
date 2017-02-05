#include <stdio.h>

int countAllDivisors(int n) 
{
	int d;
	int i;

	d = 0;
	for (i = 1; i*i < n; i++) 
	{
		if (n % i == 0) d += 2;
	}
	if (i*i == n) d++;

	return d;
}

//A(n) = 1 + 2 + ... + n
int countDivisorsOfTriangleNum(int n)
{
	if (n % 2 == 0)
	{
		return countAllDivisors(n/2) * countAllDivisors(n+1);
	} else {
		return countAllDivisors(n) * countAllDivisors((n+1)/2);
	}
}

int main() 
{
	FILE* input;
	FILE* output;
	int N;
	int i;
	
	input = fopen("input.txt", "r");
	output = fopen ("output.txt", "w");

	fscanf(input, "%d", &N);

	i = 1;
	while (countDivisorsOfTriangleNum(i) <= N) 
	{
		i++;
	}

	int A = i * (i+1) / 2;
	fprintf(output, "%d\n", A);

	return 0;
}
