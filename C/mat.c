#include <stdio.h>

int det(int m[3][3]){
	return m[0][0]*m[1][1]*m[2][2] +  m[1][0]*m[2][1]*m[0][2] + m[0][1]*m[1][2]*m[2][0]
	     - m[0][2]*m[1][1]*m[2][0] -  m[0][1]*m[1][0]*m[2][2] - m[0][0]*m[1][2]*m[2][1];
}


void readRow(int b[3]){
	scanf("%d%d%d", &b[0], &b[1], &b[2]);
}

void readMat(int m[3][3]){
	readRow(m[0]);
	readRow(m[1]);
	readRow(m[2]);
	//scanf("%d%d%d", &m[0][0], &m[0][1], &m[0][2]);
	//scanf("%d%d%d", &m[1][0], &m[1][1], &m[1][2]);
	//scanf("%d%d%d", &m[2][0], &m[2][1], &m[2][2]);
}

void combineMat(int Ak[3][3], int A[3][3], int b[3], int k){
	int i;
	int j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (j == k) {
				Ak[i][j] = b[i];
			} else {
				Ak[i][j] = A[i][j];
			}
		}
	}
}

int main() {
	int A[3][3];
	int b[3];
	int Ak[3][3];

	printf("Введтие матрицу A(3x3):\n");
	readMat(A);
	printf("Введите столбец свободных членов b(3):\n");
	readRow(b);

	printf("Сведения о матрице: \n\n");

	printf("det(A) = %d\n\n", det(A));

	int detA = det(A);
	if (detA != 0) {
		int i;
		int detAk;
		for (i = 0; i < 3; i++) {
			combineMat(Ak,A,b,i);
			detAk = det(Ak);
			printf("X%d = %d/%d = %f;\n", i+1,detAk,detA, ((float)detAk/(float)detA));
		}
	}
	
	return 0;
}
