#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void* p1, const void* p2) {
  return (*((int*)p1) - *((int*)p2));
}

int main() {
  int N;
  int i;
  int iNec;
  int iChe;
  int a[1000];
  int t[1000];
  int che[1001];
  int nec[1001];
  scanf("%d", &N);
  
  i = 0;
  iNec = 0;
  iChe = 0;
  int d;
  for (; i < N; i++) {
    scanf("%d", &d);
    if (d % 2 == 0) {
      che[iChe] = d;
      a[i] = iChe;
      t[i] = 0;
      iChe++;
    } else {
      nec[iNec] = d;
      a[i] = iNec;
      t[i] = 1;
      iNec++;
    }
  }
  
  qsort(che, iChe, sizeof(int), cmp_int);
  
  for (i = 0; i < N; i++) {
    if (t[i] == 0) {
      printf("%d ", che[a[i]]);
    } else {
      printf("%d ", nec[a[i]]);
    }
  }
  return 0;
}
