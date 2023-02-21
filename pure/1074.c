#include <stdio.h>

int GetVisitNum(int, int, int);

int main(void) {
  int N, row, col, answer;
  scanf("%d %d %d", &N, &row, &col);
  answer = GetVisitNum(N, row, col);
  printf("%d \n", answer);
  return 0;
}

int GetVisitNum(int N, int r, int c) {
  static int visit = 0;
  int nextArray = 1;
  int nextR, nextC;
  for (int i = 0; i < N; i++) {
    nextArray *= 2;
  }
  nextR = r / nextArray;
  nextC = c / nextArray;
  visit += nextC * nextArray * nextArray + (nextR * 2) * nextArray * nextArray;

  if (nextArray == 1) {
    return visit;
  } else {
    GetVisitNum(N - 1, r % nextArray, c % nextArray);
  }
}