#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void invertString(char* str) {
	int n = strlen(str);
	int i;
	char c;
	for (i = 0; i < n/2; i++) {
		c = str[i];
		str[i] = str[n-1-i];
		str[n-1-i] = c;
	}
}

char c;

void readChar() {
	scanf("%c", &c);
}

void readWord(char* str) {
	int i = 0;
	if (isalpha(c)) {
		do {
			str[i] = c;
			readChar();
			i++;
		} while (isalpha(c));
	} else {
		str[i] = c;
		readChar();
		i++;
	}
	str[i] = '\0';
}

int main() {
	char str[1024];
	readChar();
	do {
		readWord(str);
		invertString(str);
		printf("%s", str);
	} while (str[0] != '\n');
	return 0;
}
