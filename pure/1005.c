#include <stdio.h>
#include <stdlib.h>

typedef struct link {
  int index;
  struct link *next;
} link;

typedef struct build {
  int total;
  int time;
  struct link *tail; // reverse-way link
} build;

void SetLink(build D[], int X, int Y);
void FreeLink(build D[], int N);
void GetTotalTime(build D[], int N, int W);
void SearchNode(build D[], int index);

// void PrintLink(build *, int); // for debugging

int main(void) {
  int T, N, K, X, Y, W;
  int i;
  build *D;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &N, &K);

    D = (build *)malloc(N * sizeof(build));

    for (i = 0; i < N; i++) {
      scanf("%d", &D[i].time);
      D[i].total = -1;
      D[i].tail = NULL;
    }

    while (K--) {
      scanf("%d %d", &X, &Y);
      SetLink(D, --X, --Y);
    }
    scanf("%d", &W);
    GetTotalTime(D, N, --W);
    printf("%d \n", (D + W)->total);
    FreeLink(D, N);
  }
}

void SetLink(build D[], int X, int Y) {
  link *tmp = (link *)malloc(sizeof(link));
  tmp->index = X;
  tmp->next = NULL;
  if (D[Y].tail != NULL) {
    tmp->next = D[Y].tail;
  }
  D[Y].tail = tmp;
}
/*
void PrintLink(build D[], int N) {
  // function for debugging
  int i;
  link *tmp;
  for (i = 0; i < N; i++) {
    printf("[%d] (total: %d) needs.. \n", i + 1, (D + i)->total);
    if (D[i].tail == NULL) {
      printf("No Condition. \n");
      continue;
    }
    tmp = D[i].tail;
    while (tmp != NULL) {
      printf("%d costs: %d s ", tmp->index + 1, (D + tmp->index)->time);
      if ((D + tmp->index)->total == -1) {
        printf("(not yet)\n");
      } else {
        printf("(tt: %d)\n", (D + tmp->index)->total);
      }
      tmp = tmp->next;
    }
  }
}
*/
void FreeLink(build D[], int N) {
  int i;
  link *tmp;
  for (i = 0; i < N; i++) {
    while (D[i].tail != NULL) {
      tmp = D[i].tail;
      D[i].tail = tmp->next;
      free(tmp);
    }
  }
  free(D);
}

void GetTotalTime(build D[], int N, int W) {
  int i;
  int min;
  int comp;
  link *tmp;

  for (i = 0; i < N; i++) {
    if (D[i].tail == NULL) {
      D[i].total = D[i].time;
    }
  }

  while (D[W].total == -1) {
    for (i = 0; i < N; i++) {
      if (D[i].total != -1) {
        continue;
      }
      min = -1;
      tmp = D[i].tail;
      while ((comp = (D + tmp->index)->total) != -1) {
        if (comp > min) {
          min = comp;
        }
        tmp = tmp->next;
        if (tmp == NULL) {
          break;
        }
      }

      if (min > -1) {
        D[i].total = D[i].time + min;
      }
    }
  }
}