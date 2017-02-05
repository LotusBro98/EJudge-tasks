#include <stdio.h>

int AizNpoK( int n, int k)
{
	int fact = 1;
	int first = n;
	int last = n - k + 1;
	int current;

	for (current = first; current >= last; current--)
		fact *= current;

	return fact;
}

int main()
{
	int n;
	int k;

	freopen("input.dat", "rt", stdin);
	freopen("output.ans", "wt", stdout);

	scanf("%d %d", &n, &k);
	printf("%d\n", AizNpoK( n, k ));

	fclose(stdin);
	fclose(stdout);

	return 0;
}
