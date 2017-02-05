#include <stdio.h>

int main()
{
	int graph[100][100];
	int N, M;
	int i, j, k;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			graph[i][j] = 0;
		}
	}
	
	for (k = 0; k < M; k++)
	{
		scanf("%d %d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	return 0;
}
