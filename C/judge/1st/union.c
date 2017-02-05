#include <stdio.h>
#include <string.h>

union u {
	char data[16];
	long double ldb;
	double db;
	float fl;
};

void printChar(char c){
	char i = 0;
	char b;
	for(; i<8; i++){
		b = (c >> (7-i)) & 1;
		printf("%d", b);
		if (i==3) printf(" ");
	}
	printf(" ");
	//printf(" %d\n", c);
}

int main(){
	char s[64];
	union u un;
	int i = 0;

	scanf("%s", s);
	if (strcmp(s, "long") == 0) {
		scanf("%s", s);
		scanf("%Lf", &(un.ldb));
		for (i=15; i>=0; i--) {
			printChar(un.data[i]);
		}

	} else {
		if (strcmp(s, "double") == 0) {
			scanf("%lf", &(un.db));
			for (i=7; i>=0; i--) {
				printChar(un.data[i]);
			}
		} else {
			scanf("%f", &(un.fl));
			for (i=3; i>=0; i--) {
				printChar(un.data[i]);
			}
		}
	}
	printf("\n");
	return 0;
}
