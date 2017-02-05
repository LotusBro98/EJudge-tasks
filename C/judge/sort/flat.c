#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Flat {
  int number;
  char currency;     //D < E < P
  char money[100];
};

int cmpFlat(const void* fp1, const void* fp2) {
  struct Flat* flat1 = *((struct Flat**)fp1);
  struct Flat* flat2 = *((struct Flat**)fp2);
  int d = flat1->currency - flat2->currency;
  if (d == 0) {
    d = strlen(flat2->money) - strlen(flat1->money);
    if (d == 0) {
      return strcmp(flat2->money, flat1->money);
    } else return d;
  } else return d;
}

int readMoney(char* money) {
  char c;
  int code;
  do {
    code = scanf("%c", &c);
    if (code == 1) {
      if (c != '0') {
        ungetc(c,stdin);
        break;
      }
    } else return 1;
  } while (code == 1);

  scanf("%s", money);

  return 0;
}

int readFlat(struct Flat* fp) {
  int code;
  code = scanf("%d ", &(fp->number));
  if (code != 1) return 1;
  code = scanf("%c", &(fp->currency));
  if (code != 1) return 1;

  code = readMoney(fp->money);
  if (code != 0) return 1;
  return 0;
}

void printFlat(struct Flat* fp) {
  printf("%d %c%s\n", fp->number, fp->currency, fp->money);
}

void clearList(int N, struct Flat** list) {
  int i;
  for (i = 0; i < N; i++) {
    free(list[i]);
  }
}

int main() {
  struct Flat* list[10000];
  int i;
  int N;
  int code;

  i = 0;
  do {
    list[i] = malloc(sizeof(struct Flat));
    code = readFlat(list[i]);
    if (code == 0) {
      i++;
    } else {
      free(list[i]);
    }
  } while (code == 0);
  N = i;

  qsort(list, N, sizeof(struct Flat*), cmpFlat);

  for (i = 0; i < N; i++) {
    //printFlat(list[i]);
    printf("%d ",list[i]->number);
  }
  printf("\n");

  clearList(N, list);
  
  return 0;
}
