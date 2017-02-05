#include <stdio.h>
#include <stdlib.h>


//Exit codes:
//0 - OK
//1 - bad arguments
//2 - can't open
//3 - can't write
int checkEverything(int argc, char * argv[])
{
	FILE * in;
	FILE * out;

	if (argc > 2)
	{
		in = fopen(argv[1], "rb");
		if (in != NULL)
		{
			fclose(in);
			out = fopen(argv[2], "wb");
			if (out != NULL)
			{
				fclose(out);
				return 0;
			} else return 3;
		} else return 2;
	} else return 1;
}

//! Rewinds the file !
long calcSize(FILE * file)
{
	int size;
	fseek(file, 0, SEEK_END);
	size = ftell(file);
	rewind(file);
	size -= ftell(file);
	return size;
}

int copyBlock(FILE * in, FILE * out, long int * pos, long int fileSize)
{
	const int size0 = 1024;
	int size = size0;
	void * p;

	//Ask system for memory, and if it don't gives, ask just for a half of that, and so on...
	//
	while ((size > 0) && ((p = malloc(size)) == NULL)) size = size / 2;


	//If we have less than <size> bytes left to copy
	//
	if (size > (fileSize - *pos)) size = fileSize - *pos;


	if (p != NULL)
	{
		fread (p, size, 1, in );
		if (!ferror(in))
		{
			fwrite(p, size, 1, out);

			*pos += size;
			free(p);

			if (size == 0)
			{
				return 0;     // 0 <=> Well done!
			} else return -1; //-1 <=> keep copying
		} else return 2;
	} else return 3;
}

int main(int argc, char * argv[])
{
	FILE * in;
	FILE * out;
	int code;
	long size;
	long pos;
	void * p;

	code = checkEverything(argc, argv);
	
	if (code == 0)
	{
		in  = fopen(argv[1], "rb");
		out = fopen(argv[2], "wb");

		size = calcSize(in);
		pos = 0;
		code = -1;
		while (code == -1)
		{
			code = copyBlock(in, out, &pos, size);
		}

		fclose(in);
		fclose(out);

		if (code == 0)
		{
			return 0;
		} else return code;
	} else return code;
}
