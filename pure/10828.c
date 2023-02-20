#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int d;
  struct node *next;
} node;

void Push(node **, int);
int Pop(node **);
int GetCount(node **top);
int Empty(node **);
int Top(node **);

int main(void) {
  char inputStr[6];
  int pushNum, T;
  node *top = NULL;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", inputStr);
    if (strcmp(inputStr, "push") == 0) {
      scanf("%d", &pushNum);
      Push(&top, pushNum);
    } else if (strcmp(inputStr, "pop") == 0) {
      Pop(&top);
    } else if (strcmp(inputStr, "size") == 0) {
      GetCount(&top);
    } else if (strcmp(inputStr, "empty") == 0) {
      Empty(&top);
    } else if (strcmp(inputStr, "top") == 0) {
      Top(&top);
    }
  }
  return 0;
}

void Push(node **top, int data) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->d = data;
  if (*top == NULL) {
    tmp->next = NULL;
    *top = tmp;
    return;
  }
  tmp->next = *top;
  *top = tmp;
}

int Pop(node **top) {
  node *tmp = *top;
  int out;
  if (tmp == NULL) {
    printf("-1 \n");
    return 0;
  }
  out = tmp->d;
  *top = (*top)->next;
  free(tmp);
  return printf("%d \n", out);
}

int GetCount(node **top) {
  int cnt = 0;
  node *tmp = *top;
  while (tmp != NULL) {
    tmp = (tmp)->next;
    cnt++;
  }
  return printf("%d \n", cnt);
}

int Empty(node **top) {
  if ((*top) == NULL) {
    return printf("1 \n");
  } else {
    return printf("0 \n");
  }
}
int Top(node **top) {
  if ((*top) == NULL) {
    return printf("-1 \n");
  } else {
    return printf("%d \n", (*top)->d);
  }
}
