#include <stdio.h>

int calcElem(int i, int j, int * A, int mA, int * B, int mB)
{
	int sum = 0;
	int k;
	for (k = 0; k < mA; k++)
	{
		sum += *(A + i*mA + k) * *(B + k*mB + j);
	}
	return sum;
}

int multiply(int * A, int nA, int mA, int * B, int nB, int mB, int * C)
{
	int i;
	int j;

	if (mA == nB)
	{
		for (i = 0; i < nA; i++)
		{
			for (j = 0; j < mB; j++)
			{
				*(C + i*mB + j) = calcElem(i, j, A, mA, B, mB);
			}
		}
		return 0;
	} else {
		return -1;
	}
}

int readMat(int * A, int n, int m)
{
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", (A + i*m + j));
		}
	}
	return 0;
}

int printMat(int * A, int n, int m)
{
	int i;
	int j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", *(A + i*m + j));
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int A[100][100];
	int B[100][100];
	int C[100][100];

	int nA;
	int mA;
	int nB;
	int mB;
	int code;

	scanf("%d%d%d%d", &nA, &mA, &nB, &mB);

	readMat(&A[0][0], nA, mA);
	readMat(&B[0][0], nB, mB);

	code = multiply(&A[0][0], nA, mA, &B[0][0], nB, mB, &C[0][0]);

	printf("\n");
	if (code == 0)
	{
		printMat(&C[0][0], nA, mB);
	} else {
		printf("-1");
	}
	return 0;
}
