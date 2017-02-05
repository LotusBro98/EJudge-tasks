#include <stdio.h>

int main()
{
	int graph[100][100];
	int dist[100];
	int flag[100];

	int N,M,i,j,k,w;
	int visited;
	int min;
	int start;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			graph[i][j] = 0;
		}
		dist[i] = -1;
		flag[i] = 0;
	}

	for (k = 0; k < M; k++)
	{
		scanf("%d %d %d", &i, &j, &w);
		graph[i][j] = w;
		graph[j][i] = w;
	}

	scanf("%d", &start);

	i = start;
	dist[start] = 0;
	for (visited = 0; visited < N; visited++)
	{
		for (j = 0; j < N; j++)
		{
			if ((graph[i][j] != 0) && (flag[j] == 0))
			{
				if (dist[j] == -1 || (dist[j] > (dist[i] + graph[i][j])))
				{
					dist[j] = dist[i] + graph[i][j];
				}
			}
		}
		flag[i] = 1;

		min = -1;
		k = -1;
		for (j = 0; j < N; j ++)
		{
			if ((flag[j] == 0) && (dist[j] != -1) && (min == -1 || dist[j] < min))
			{
				min = dist[j];
				k = j;
			}
		}
		i = k;
	}

	for (k = 0; k < N; k++)
	{
		printf("%d ", dist[k]);
	}
	printf("\n");

	return 0;
}
