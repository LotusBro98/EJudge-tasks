#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int triangle[100][100];
	int sum[100][100];
	int N, i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j <= i; j++)
			scanf("%d", &triangle[i][j]);

	for (j = 0; j < N; j++)
		sum[N-1][j] = triangle[N-1][j];

	for (i = N-2; i >= 0; i--)
	{
		for (j = 0; j <= i; j++)
		{
			sum[i][j] = max(sum[i+1][j], sum[i+1][j+1]) + triangle[i][j];
		}
	}

	printf("%d\n", sum[0][0]);

	return 0;
}
