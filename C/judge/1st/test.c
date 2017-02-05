#include <stdio.h>

int main(){
	int c;
	int d;
	char c1;
	char d1;
	char r;
	char i;
	scanf("%d", &c);
	scanf("%d", &d);
	c1 = c;
	d1 = d;
	r = c1 >> d1;
	printf("%d\n", r);
	for (i=7;i>=0;i--){
		printf("%d", (c1 >> i)&1);
	}
	printf("\n");
	for (i=7;i>=0;i--){
		printf("%d", (r >> i)&1);
	}
	printf("\n");
	return 0;
}
