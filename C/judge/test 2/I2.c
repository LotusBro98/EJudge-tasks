#include <stdio.h>

char marked[2001];

int main()
{
	int i;
	int n;
	int m;
	int from;
	int to;
	int count = 0;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++)
		marked[i] = 0;

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &from, &to);
		marked[to-1] = 1;
	}

	for (i = 0; i < n; i++)
		if (marked[i] == 0) count++;

	if (count == 0) count = 1;
	printf("%d\n", count);

	return 0;
}
