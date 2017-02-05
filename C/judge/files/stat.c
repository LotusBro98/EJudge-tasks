#include <stdio.h>

int safeOut(char * file, char * text)
{
	FILE * out = fopen(file, "w");

	if (out != NULL)
	{
		fprintf(out, "%s", text);
		printf("%s", text);
		return 0;
	} else {
		printf("%s%s%s", "It is something wrong with file ", file, " ...\n Try reinstalling your operating system :)\n");
		return 2;
	}
}

int safeOutNum(char * file, long n)
{
	FILE * out = fopen(file, "w");

	if (out != NULL)
	{
		fprintf(out, "%ld\n", n);
		printf("%ld\n", n);
		return 0;
	} else {
		printf("%s%s%s", "It is something wrong with file ", file, " ...\n Try reinstalling your operating system :)\n");
		return 2;
	}
}

long calcSize(FILE * file)
{
	long begin;
	long end;
	
	rewind(file);
	begin = ftell(file);

	fseek(file, 0, SEEK_END);
	end = ftell(file);

	return end - begin;
}

int main(int argc, char * argv[])
{
	char filename[256];
	FILE * file;
	int code;
	long size;

	if (argc == 2)
	{
		sscanf(argv[1], "%s", filename);
		file = fopen(filename, "r");
		if (file != NULL)
		{
			size = calcSize(file);
			code = safeOutNum("output.txt", size);
			return code ? code : 0;
		} else {
			code = safeOut("output.txt", "Can't open file\n");
			return code ? code : 2;
		}
	} else {
		code = safeOut("output.txt", "Usage: stat filename\n");
		return code ? code : 1;
	}
}
