#include <stdio.h>
#include <string.h>

int table[1001][1001];
char s1[1000];
char s2[1000];
char result[1000];

void buildTable() {
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int i;
	int j;
	for (i = 0; i <= n1; i++)
		table[i][0] = 0;
	for (j = 0; j <= n2; j++)
		table[0][j] = 0;

	for (i = 1; i <= n1; i++) {
		for (j = 1; j <= n2; j++) {
			if (s1[i-1] == s2[j-1]) {
				table[i][j] = table[i-1][j-1] + 1;
			} else {
				int up = table[i-1][j];
				int left = table[i][j-1];
				if (up > left) {
					table[i][j] = up;
				} else {
					table[i][j] = left;
				}
			}
		}
	}
}

void printTable() {
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int i;
	int j;
	printf("    0 ");
	for (j = 1; j <= n2; j++) 
		printf(" %c ", s2[j-1]);
	printf("\n");
	for (i = 0; i <= n1; i++) {
		if (i == 0) {
			printf("0 ");
		} else {
			printf("%c ", s1[i-1]);
		}
		for (j = 0; j <= n2; j++) {
			printf("%3d", table[i][j]);
		}
		printf("\n");
	}
}

void reconstruct() {
	int i = strlen(s1);
	int j = strlen(s2);
	int n = table[i][j];
	if (n > 0) {
		result[n] = '\0';
		while (n > 0) {
			if (table[i-1][j] == n) {
				i--;
			} else if (table[i][j-1] == n) {
				j--;
			} else {
				n--;
				result[n] = s1[i-1];
				i--;
				j--;
			}
		}
	} else {
		strcpy(result, "Empty");
	}
}

int main() {
	scanf("%s", s1);
	scanf("%s", s2);
	buildTable();
	//printTable();
	reconstruct();
	printf("%s\n", result);
	return 0;
}
