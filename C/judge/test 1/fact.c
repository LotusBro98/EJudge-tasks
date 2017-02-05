#include <stdio.h>
#include <stdlib.h>

struct _Decimal {
  char a[200];
  int N;
};
typedef struct _Decimal Decimal;

void clearDec(Decimal* A) {
  int i;
  for (i = 0; i < 200; i++) {
    A->a[i] = 0;
  }
  A->N = 0;
}

Decimal* intToDec(int n) {
  Decimal* dp = malloc(sizeof(Decimal));
  clearDec(dp);
  while (n > 0) {
    dp->a[dp->N] = n%10;
    (dp->N)++;
    n = n / 10;
  }
  if (dp->N == 0) {
    dp->a[0] = 0;
    dp->N = 0;
  } else {
	(dp->N)--;
  }
  return dp;
}

void printDec(Decimal* dp) {
  int i;
  for(i = dp->N; i >= 0; i--) {
    printf("%d", dp->a[i]);
  }
  printf("\n");
}

void addDec(Decimal* A, Decimal* B) {
  char q;
  char s;
  int i;
  int N = A->N;
  if (B->N > N) N = B->N;
  N++;
  q = 0;
  for (i = 0; i < N; i++) {
	s = A->a[i] + B->a[i];
	A->a[i] = (s+q) % 10;
	q = (s+q) / 10;
  }
  if (q == 0) {
	N--;
  } else {
	A->a[N] = q;
  }
  while (N>0 && A->a[N] == 0) N--;
  A->N = N;
}

void mulDec(Decimal* A, int n) {
  char q;
  char m;
  int i;
  int N;
  N = A->N;
  N++;
  q = 0;
  for (i = 0; i < N; i++) {
	m = A->a[i] * n;
	A->a[i] = (m+q) % 10;
	q = (m+q) / 10;
  }
  if (q == 0) {
	N--;
  } else {
	A->a[N] = q;
  }
  while (N>0 && A->a[N] == 0) N--;
  A->N = N;
}

Decimal* copyDec(Decimal* B) {
  int i;
  Decimal* A = intToDec(0);
  for (i = 0; i<=B->N; i++) {
	A->a[i] = B->a[i];
  }
  A->N = B->N;
  return A;
}

void shiftLeft(Decimal* A, int n) {
  int i;
  for (i = A->N; i>=0; i--) {
	A->a[i+n] = A->a[i];
  }
  for (i = 0; i < n; i++) {
	A->a[i] = 0;
  }
  A->N += n;
}

void multiplyDec(Decimal* A, int b1, int b0) {
	Decimal* S0 = copyDec(A);
	mulDec(S0,b0);

	Decimal* S1 = copyDec(A);
	shiftLeft(S1,1);
	mulDec(S1,b1);


	clearDec(A);
	addDec(A,S0);
	addDec(A,S1);

	free(S0);
	free(S1);
}

Decimal* fact(int n) {
  Decimal* A = intToDec(1);
  int i;
  
  if (n == 100) {
	shiftLeft(A,2);
	n--;
  }
  for(i = 1; i <= n; i++) {
	multiplyDec(A,i/10,i%10);
  }
  return A;
}

int digitSum(Decimal* A) {
  int i;
  int sum = 0;
  for(i = 0; i<=A->N; i++) {
	sum += A->a[i];
  }
  return sum;
}

int main() {
  int n;
  scanf("%d", &n);
  Decimal* A = fact(n);
  //printDec(A);
  printf("%d\n", digitSum(A));
  free(A);
  return 0;
}
