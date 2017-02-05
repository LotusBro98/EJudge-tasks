#include <stdio.h>

int main()
{
	int n = 0;
	int N, i, a;

	scanf("%d", &N);

	for (i = 0; i < N*N; i++)
	{
		scanf("%d", &a);
		n += a;
	}

	printf("%d", n / 2);

	return 0;
}
