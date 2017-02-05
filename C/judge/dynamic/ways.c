#include <stdio.h>

int main()
{
	long long int ways[22][22];
	int N, M;
	int i, j;

	scanf("%d %d", &N, &M);
	N++;
	M++;

	//Initialise all cells with zeroes
	for (i = 0; i <= N; i++)
		for (j = 0; j <= M; j++)
			ways[i][j] = 0;
	
	//Each cell of the first row can be visited only by one way
	for (j = 1; j <=M; j++)
		ways[1][j] = 1;

	for (i = 2; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			ways[i][j] = ways[i-1][j] + ways[i][j-1];
		}
	}

	printf("%Ld\n", ways[N][M]);

	return 0;
}
