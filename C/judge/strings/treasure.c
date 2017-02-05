#include <stdio.h>
#include <string.h>

char seq(const char* s1, const char* s2) {
	return strcmp(s1, s2) == 0;
}


int main() {
	char s[256];
	int x = 0;
	int y = 0;
	int a;
	
	scanf("%s", s);
	while (!seq(s, "Treasure!")) {
		scanf("%d", &a);
		if (seq(s, "North")) {
			y += a;
		} else {
			if (seq(s, "South")) {
				y -= a;
			} else {
				if (seq(s, "West")) {
					x -= a;
				} else {
					if (seq(s, "East")) {
						x += a;
					}
				}
			}
		}
		scanf("%s", s);
	}
	printf("%d %d", x, y);
	return 0;
}
