#include <stdio.h>

int main() {
	char stack[100002];
	char* p;
	char c;
	char code;
	stack[0] = '#';
	p = stack + 1;
	c = getchar();
	while (c != EOF) {
		switch (c) {
			case '(':
				*p = ')';
				p++;
				break;
			case '[':
				*p = ']';
				p++;
				break;
			case '<':
				*p = '>';
				p++;
				break;
			case '{':
				*p = '}';
				p++;
				break;
			default:
				if (*(p-1) == c) {
					p--;
				} else {
					printf("NO\n");
					return 0;
				}
				break;
			case '\n':
			case EOF:
				c = EOF;
				break;
		}
		c = getchar();
	}
	if ((p - stack) == 1) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
