#include <stdio.h>

void make_alphabet(char * dst, const char * codeword)
{	
	char used[26];
	char oldAlpha[27] = "abcdefghijklmnopqrtsuvwxyz";
	int len; //длина слова после записи в алфавит

	//Записываем кодовое слово в начало
	int i;
	for (i = 0; i < 26; i++)
		used[i] = 0;
	
	i = 0;
	len = 0;
	while (codeword[i] != '\0')
	{
		if (!used[codeword[i] - 'a'])
		{
			used[codeword[i] - 'a'] = 1;
			dst[len] = codeword[i];
			len++;
		}
		i++;
	}
	//Записали

	//Составляем алфавит

	i = 0;
	//len = len
	while (i < 26)
	{
		if (!used[i])
		{
			dst[len] = oldAlpha[i];
			len++;
		}
		i++;
	}
	dst[26] = '\0';
}

int main()
{
	char a[27];
	make_alphabet(a, "wordodr");
	printf("%s\n", a);
	return 0;
}
