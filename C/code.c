#include <stdio.h>
#include <string.h>

void putAndShift(char * s, char c){
	int i;
	for (i = 0; i < (strlen(s)-1); i++){
		s[i] = s[i+1];
	}
	s[strlen(s)-1] = c;
}

int main(){
	char s[6] = "      ";
	char c;
	int code;

	code = scanf("%c", &c);
	while ((code == 1) && (c != '\n')){
		putAndShift(s,c);
		if ((strncmp(s," bomb",5) == 0) && (c < 'a' || c > 'z')){
			printf("YES\n");
			return 0;
		}
		scanf("%c", &c);
	}
	printf("NO\n");
	return 0;
}
