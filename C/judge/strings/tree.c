#include <stdio.h>
#include <ctype.h>

int checkNum() {
	char c;
	c = getc(stdin);
	ungetc(c, stdin);
	if (c == '-' || isdigit(c)) {
		return 1;
	} else {
		return 0;
	}
}

int readNum() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	char c;
	double avg;
	double pow;
	pow = 1;
	avg = 0;
	do {
		if (checkNum()) {
			avg += pow * readNum();
		} else {
			c = getc(stdin);
			if (c == '(') {
				pow = pow * 0.5;
			} else {
				if (c == ')') {
					pow = pow * 2;
				}
			}
		}
	} while (pow < 1);
	printf("%.2lf", avg);
	return 0;
}
