#include <memory.h>
#include <stdio.h>

#define MAX 10000

int main(void) {
  int caseNum = 0;
  int i, n;
  int arr[MAX];
  memset(arr, 0, MAX * sizeof(int));
  scanf("%d", &caseNum);

  for (i = 0; i < caseNum; i++) {
    scanf("%d", &n);
    arr[n - 1] += 1;
  }

  for (i = 0; i < MAX; i++) {
    while (arr[i] > 0) {
      arr[i] -= 1;
      printf("%d \n", i + 1);
    }
  }
  return 0;
}