#include <stdio.h>

//i - current man
//i + di - other man whose best time this function is calculating
//dt - time that i man needs to buy ticket for i + di man
void calcNewBestTime(int * time, int i, int di, int dt)
{
	int thisTime = *(time + i);
	int oldTime = *(time + i + di);
	if ((oldTime <= 0) || ((thisTime + dt) < oldTime))
	{
		*(time + i + di) = thisTime + dt;
	}
}

void printTime(int * time, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(time + i));
	}
	printf("\n");
}

int main()
{
	int time[5005];
	int N, i;
	int a, b, c;

	scanf("%d", &N);

	time[0] = 0;
	for (i = 1; i < N + 2; i++)
	{
		time[i] = -1;
	}

	scanf("%d %d %d", &a, &b, &c);
	time[0] = a;
	time[1] = b;
	time[2] = c;
	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		calcNewBestTime(time, i, 1, a);
		calcNewBestTime(time, i, 2, b);
		calcNewBestTime(time, i, 3, c);
		//printTime(time, i+4);
	}

	printf("%d\n", time[N-1]);

	return 0;
}
