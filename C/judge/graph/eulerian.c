#include <stdio.h>

int main()
{
	int v;
	int N;
	int i, j;
	int deg;
	int eul;

	scanf("%d", &N);

	eul = 1;
	for(i = 0; i < N; i++)
	{
		deg = 0;
		for (j = 0; j < N; j++)
		{
			scanf("%d", &v);
			if (i == j)
			{
				deg += v*2;
			} else {
				deg += v;
			}
		}
		if (deg % 2 != 0)
		{
			eul = 0;
			break;
		}
	}

	if (eul)
	{
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}
