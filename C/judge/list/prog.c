#include <stdio.h>
#include <string.h>
#define N 100

char get8(char * triad)
{
	char *lookup[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	int i = 0;
	while (strcmp(triad, lookup[i]) != 0) i++;
	return '0' + i;
}

char * convert (char * dst, const char * src)
{
	char triad[3] = "000";
	char *srcPointer = src;
	char *dstPointer = dst;
	int i;

	//Отдельно обрабатываем первую тройку, чтобы число оставшихся символов делилось на 3
	i = strlen(src) % 3;
	if (i != 0)
	{
		strncpy(triad + 3 - i, srcPointer, i);
		*dstPointer = get8(triad);
		dstPointer++;
		srcPointer += i;
	}

	while (*srcPointer != '\0')
	{
		strncpy(triad, srcPointer, 3);
		*dstPointer = get8(triad);
		dstPointer++;
		srcPointer += 3;
	}
	dstPointer = '\0';
	return dst;
}

int main()
{
	char d[100];
	printf("%s\n", convert(d, "11101101101"));
	return 0;
}
