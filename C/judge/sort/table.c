#include <stdlib.h>
#include <stdio.h>

struct Player {
  int n;
  int win[200];
};

int cmpPlayer(const void* p1, const void* p2) {
  struct Player* pl1 = *((struct Player**)p1);
  struct Player* pl2 = *((struct Player**)p2);
  return pl2->win[pl1->n];
}

void readPlayer(int n, struct Player** table) {
  struct Player* tp = malloc(sizeof(struct Player));
  tp->n = n;

  table[n] = tp;
  
  char c;
  int i = 0;
  do {
    c = getchar();
    if (c == '+') {
      table[n]->win[i] = 1;
      table[i]->win[n] = -1;
    } else if (c == '-') {
      table[n]->win[i] = -1;
      table[i]->win[n] = 1;
    } else if (c == '#'){
      table[n]->win[i] = 0;
    } else {
      i--;
    }
    i++;
  } while (c != '#');
}

void killPlayers(int N, struct Player** table) {
  int i;
  for (i = 0; i < N; i++) {
    free(table[i]);
  }
}

void printTable(int N, struct Player** table) {
  int i;
  int j;
  for (i = 0; i < N; i++) {
    printf("%d  ", table[i]->n + 1);
    for (j = 0; j < N; j++) {
      if (table[i]->win[j] > 0) {
        printf("+ ");
      } else if (table[i]->win[j] < 0) {
        printf("- ");
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void printOrder(int N, struct Player** table) {
  int i;
  for (i = 0; i < N; i++) {
    printf("%d ", table[i]->n + 1);
  }
  printf("\n");
}

int readTable(struct Player** table) {
  int N;
  int i;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    readPlayer(i, table);
  }
  return N;
}

int main() {
  struct Player* table[200];
  int N;
  
  N = readTable(table);
  //printf("\n");
  //printTable(N, table);

  qsort(table, N, sizeof(struct Player*), cmpPlayer);

  //printTable(N, table);
  printOrder(N, table);
  
  killPlayers(N, table);

  return 0;
}
