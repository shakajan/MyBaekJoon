/*
https://www.acmicpc.net/problem/1920
searched list: binary search
https://namu.wiki/w/%EC%9D%B4%EC%A7%84%20%ED%83%90%EC%83%89
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void *, const void *);
int BinarySearch(int[], int, int, int);
int main(void) {
  int X, *A;
  int aNum, xNum, i;
  scanf("%d", &aNum);
  A = (int *)malloc(aNum * sizeof(int));
  for (i = 0; i < aNum; i++) {
    scanf("%d", &A[i]);
  }
  qsort(A, aNum, sizeof(int), comp);

  scanf("%d", &xNum);
  for (i = 0; i < xNum; i++) {
    scanf("%d", &X);
    printf("%d \n", BinarySearch(A, X, 0, aNum - 1));
  }
  free(A);
  return 0;
}

int comp(const void *a, const void *b) {
  if (*(int *)a > *(int *)b) {
    return 1;
  } else {
    return -1;
  }
}

int BinarySearch(int data[], int pick, int st, int ed) {
  int mid = (st + ed) / 2;
  if (st > ed) {
    return 0;
  }

  if (pick < data[mid]) {
    return BinarySearch(data, pick, st, mid - 1);
  } else if (data[mid] == pick) {
    return 1;
  } else {
    return BinarySearch(data, pick, mid + 1, ed);
  }
}