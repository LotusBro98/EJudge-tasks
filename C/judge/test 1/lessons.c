#include <stdio.h>

int calcTimeM(int lesson) {
  int time = 9*60 + lesson / 2 * 110;
  if (lesson % 2 == 0) {
    return time - 15;
  } else {
    return time + 45;
  }
}

void printTime(int timeM) {
  int h = timeM / 60; 
  int m = timeM % 60;
  printf("%d %d", h, m);
}

int main() {
  int lesson;
  scanf("%d", &lesson);
  printTime(calcTimeM(lesson));
  return 0;
}
