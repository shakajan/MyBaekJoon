#include <stdbool.h>
#include <stdio.h>

int main(void) {
  bool white[100][100] = {
      0,
  };
  int caseNum, x, y, sum = 0;
  int i, j;
  scanf("%d", &caseNum);
  while (caseNum--) {
    scanf("%d %d", &x, &y);
    x-- || y--;
    for (i = x; i < x + 10; i++) {
      for (j = y; j < y + 10; j++) {
        white[i][j] = true;
      }
    }
  }
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      if (white[i][j]) {
        sum++;
      }
    }
  }
  printf("%d \n", sum);
  return 0;
}