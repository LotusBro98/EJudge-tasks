#include <stdio.h>

int main (int argc, char* argv[], char* envp[]) 
{
	int n;
	int i;

	sscanf (argv[1], "%d", &n);
	
	for (i = 0; i < n; i++) 
	{
		printf ("%s\n", envp[i]);
	}
	return 0;
}
