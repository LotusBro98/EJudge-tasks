#include <stdio.h>

int a14[8][8];
int f[8][2];

void print()
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%d ", a14[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//incas s proverkas
void inc(int x, int y)
{
	if (x >= 0 && y >= 0 && x < 8 && y < 8)
	{
		a14[x][y]++;
	}
}

//pomechaes the kletkas
void incAs(int fX, int fY) //fX, fY - coords of fresyas
{
	int i;
	for (i = 0; i < 8; i++)
	{
		if (i != fX)
		{
			inc(i, fY);
			inc(i, i - fX + fY);
			inc(i, fX - i + fY);
		}
		if ( i != fY)
		{
			inc(fX, i);
		}
	}
}

int main()
{
	int i, j;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			a14[i][j] = 0;

	for (i = 0; i < 8; i++)
	{
		scanf("%d %d", &f[i][0], &f[i][1]);
		incAs(f[i][0] - 1, f[i][1] - 1);
		print();
	}

	for (i = 0; i < 8; i++)
		if (a14[f[i][0] - 1] [f[i][1] - 1] != 0)
		{
			printf("YES\n");
			return 0;
		}
	
	printf("NO\n");
	return 0;
}
