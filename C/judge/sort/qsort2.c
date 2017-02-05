#include <stdio.h>
#include <stdlib.h>

struct Point {
  int x;
  int y;
};

int cmp_Point(const void* p1, const void* p2) {
  int x1 = ((struct Point*)p1)->x;
  int y1 = ((struct Point*)p1)->y;
  int x2 = ((struct Point*)p2)->x;
  int y2 = ((struct Point*)p2)->y;
  int r = x1*x1 + y1*y1 - x2*x2 - y2*y2;
  if (r == 0) {
    r = x1 - x2;
    if (r == 0) {
      return y1 - y2;
    } else {
      return r;
    }
  } else {
    return r;
  }
}

int scanPoint(struct Point* tp) {
  return scanf("%d%d", &(tp->x), &(tp->y));
}

void printPoint(struct Point tp) {
  printf("%d %d\n", tp.x, tp.y);
}

int main() {
  int N;
  struct Point points[1000];

  scanf("%d", &N);

  int i;
  for (i = 0; i < N; i++) {
    scanPoint(&points[i]);
  }

  qsort(points, N, sizeof(struct Point), cmp_Point);

  for (i = 0; i < N; i++) {
    printPoint(points[i]);
  }
  return 0;
}
