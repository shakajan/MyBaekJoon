#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int d;
  struct node *next;
} node;

typedef struct point {
  bool visit;
  struct node *top;
} point;

void Push(node **, int);
int Pop(node **);
void SortStack(node **top);
int GetCount(node **top);
int comp(const void *, const void *);
void PrintStack(int, node **);
void DFS(point *, int);
void BFS(point *, int);

int main(void) {
  int N, M, V, i;
  int n1, n2;
  point *p = NULL;
  scanf("%d %d %d", &N, &M, &V);
  p = (point *)malloc((N + 1) * sizeof(point));
  for (i = 0; i <= N; i++) {
    p[i].top = NULL;
    p[i].visit = false;
  }

  while (M--) {
    scanf("%d %d", &n1, &n2);
    Push(&p[n1].top, n2);
    Push(&p[n2].top, n1);
  }
  for (i = 1; i <= N; i++) {
    SortStack(&p[i].top);
    PrintStack(i, &p[i].top);
  }

  DFS(p, V);
  BFS(p, V);

  free(p);
  return 0;
}

void SortStack(node **top) {
  int cnt = GetCount(top);
  int *sort;
  if (cnt == 0) {
    return;
  }
  sort = (int *)malloc(cnt * sizeof(int));
  for (int i = 0; i < cnt; i++) {
    sort[i] = Pop(top);
  }
  qsort(sort, cnt, sizeof(int), comp);
  for (int i = 0; i < cnt; i++) {
    Push(top, sort[i]);
  }
  free(sort);
  return;
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
  int out = tmp->d;
  *top = (*top)->next;
  free(tmp);
  return out;
}

int GetCount(node **top) {
  int cnt = 0;
  node *tmp = *top;
  while (tmp != NULL) {
    tmp = (tmp)->next;
    cnt++;
  }
  return cnt;
}

int comp(const void *a, const void *b) {
  if (*(int *)a < *(int *)b) {
    return 1;
  } else {
    return -1;
  }
}

void PrintStack(int i, node **top) {
  node *tmp = *top;
  printf("%d: ", i);
  while (tmp != NULL) {
    printf("%d ", tmp->d);
    tmp = tmp->next;
  }
  printf(" \n");
  return;
}

void DFS(point *p, int V) {}