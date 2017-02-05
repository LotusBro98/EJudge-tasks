#include <stdio.h>
#include <string.h>

char * replace_n (char * dst, const char * str, const char * from, const char * to, unsigned int n)
{
	int i;
	int fromLen = strlen(from);
	int toLen = strlen(to);
	char * strP0 = str;
	char * strP1;
	char * dstP = dst;

	for (i = 0; i < n; i++)
	{
		strP1 = strstr(strP0, from);

		if (strP1 != NULL)
		{
			strncpy(dstP, strP0, strP1 - strP0);
			dstP += strP1 - strP0;
			strP0 += strP1 - strP0 + fromLen;
			strcpy(dstP, to);
			dstP += toLen;
		} 
		else 
		{
			strcpy(dstP, strP0);
			strP0 = NULL;
			break;
		}
	}

	if (strP0 != NULL) strcpy(dstP, strP0);

	return dst;
}

int main()
{
	char dst[100];
	
	printf("_%s_\n", replace_n (dst, "wQWabchelloabc", "abc", "xy", 3));

	return 0;
}
