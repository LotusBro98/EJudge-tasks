#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE * file;
	FILE * out;
	long size;

	if (argc >= 2)
	{
		file = fopen(argv[1], "rb");
		if (file != NULL)
		{
			
			out = fopen("output.txt", "wt");
			fclose(out);
			
			fseek(file, 0, SEEK_END);
			size = ftell(file);
			//rewind(file);
			//size -= ftell(file);
			fclose(file);

			out = fopen("output.txt", "wt");
			fprintf(out, "%ld\n", size);
			fclose(out);
			return 0;
		} else {
			out = fopen("output.txt", "wt");
			fprintf(out, "Can't open file ");
			fprintf(out, "%s\n", argv[1]);
			fclose(out);
			return 2;
		}
	} else {
		out = fopen("output.txt", "wt");
		fprintf(out, "Usage: stat filename\n");
		fclose(out);
		return 1;
	}
}
