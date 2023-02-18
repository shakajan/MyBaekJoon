// https://www.acmicpc.net/problem/1007

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
  int x;
  int y;
} point;

long double rec(point[], int[], int, int, int);

int main(void) {
  int testCase = 0;
  int i = 0, n = 0, r = 0;
  point *data = NULL;
  int *pick = NULL;
  scanf("%d", &testCase);
  while (testCase--) {
    scanf("%d", &n);
    r = n / 2;
    data = (point *)malloc(n * sizeof(point));
    pick = (int *)malloc(r * sizeof(int));
    for (i = 0; i < n; i++) {
      scanf("%d %d", &data[i].x, &data[i].y);
    }

    printf("%.10LF \n", rec(data, pick, n, r, 0));
    free(data);
    free(pick);
  }
  return 0;
}

long double rec(point data[], int pick[], int n, int r, int pre) {
  static int count = -1;
  static long double min = -1;
  point start = {0, 0}, end = {0, 0};
  long double comp = 0;
  long double vecX = 0, vecY = 0;
  if (count == -1) {
    min = -1;
  }

  count++;
  for (int i = pre; i < n; i++) {
    if (count < r - 1) {
      pick[count] = i;
      rec(data, pick, n, r, i + 1);
    } else if (count == r - 1) {
      comp = 0;
      pick[count] = i;
      for (int j = 0, k; j < n; j++) {
        k = 0;
        for (k = 0; k < r; k++) {
          if (j == pick[k]) {
            start.x += data[j].x;
            start.y += data[j].y;
            break;
          }
        }
        if (k == r) {
          end.x += data[j].x;
          end.y += data[j].y;
        }
      }
      vecX = (double)(end.x - start.x);
      vecY = (double)(end.y - start.y);
      comp = sqrt(vecX * vecX + vecY * vecY);
      end.x = 0;
      end.y = 0;
      start.x = 0;
      start.y = 0;
      if (min < 0 || comp < min) {
        min = comp;
      }
    }
  }
  count--;
  if (count == -1) {
    return min;
  }
}