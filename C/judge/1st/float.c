#include <stdio.h>
#include <stdlib.h>

void printBits(char byte){
	int i;
	char bit;
	for (i = 7; i >= 0; i--) {
		bit = (byte >> i) & 1;
		printf("%d", bit);
		if (i == 4 || i == 0) printf(" ");
	}
}

void printBytes(void* p, int n){
	for (; n > 0; n--) {
		printBits(*(char*)(p + n - 1));
	}
}


int main(){
	char s[64];
	void* p = calloc(1,sizeof(long double));
	
	scanf("%s", s);
	if (s[0] == 'l') {
		scanf("%s", s);
		scanf("%Lf", (long double*)p);
		//printBytes(p, 10);
		printBytes(p, sizeof(long double));
	} else if (s[0] == 'd') {
		scanf("%lf", (double*)p);
		printBytes(p, sizeof(double));
	} else {
		scanf("%f", (float*)p);
		printBytes(p, sizeof(float));
	}
	printf("\n");
	free(p);
	return 0;
}
