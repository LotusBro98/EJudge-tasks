#include <stdio.h>

char adjMat[2001][2001];
char markMat[2001];
int N;
int M;

void readAdjMat();

void markConnected(int start);

void printMarked();

int detectUnconnected(int start);

//---------
int main()
{
	readAdjMat();
	markConnected(1);
	printMarked();
	return 0;
}
//---------

void readAdjMat()
{
	int n;
	int m;
	int i, j;
	int from;
	int to;

	scanf("%d %d", &n, &m);
	N = n;
	M = m;
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			adjMat[i][j] = 0;
		}
		markMat[i] = 0;
	}
	
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &from, &to);
		adjMat[from][to] = 1;
	}

}

void markConnected(int start)
{
	int j;
	if (markMat[start] == 0)
	{
		markMat[start] = 1;
		for (j = 1; j <= N; j++)
		{
			if (adjMat[start][j]) markConnected(j);
		}
	}
}

void printMarked()
{
	int i;

	for (i = 1; i <= N; i++)
		printf("%d: %d\n", i, markMat[i]);
}
