#include <stdio.h>

int main()
{
	int N, i, j;
	int a;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < i; j++)
		{
			scanf("%d", &a);
			if (a)
			{
				printf("%d %d\n", i, j);
			}
		}

		for (j = i; j < N; j++)
			scanf("%d", &a);
	}

	return 0;
}
