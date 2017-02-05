#include <stdio.h>

int main()
{
	int dec[101][101];
	int N;
	int n;
	int k;

	scanf("%d", &N);

	for (n = 0; n <= N; n ++)
		for (k = 0; k <= N; k++)
			dec[n][k] = 0;

	for (n = 0; n <= N; n++)
	{
		dec[n][0] = 0;
		dec[0][n] = 1;
	}

	for (n = 1; n <= N; n++)
	{
		for (k = 1; k <= N; k++)
		{
			if (k <= n)
			{
				dec[n][k] = dec[n][k-1] + dec[n-k][k];
			} else {
				dec[n][k] = dec[n][n];
			}
		}
	}

	printf("%d\n", dec[N][N]);

	return 0;
}
