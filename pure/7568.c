/*
  https://www.acmicpc.net/problem/7568
  make circle node -> success! I guess
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int height;
  int weight;
  int rank;
  struct node *next;
} node;

void GetStruct(node **, int);
node *GetNode(void);
void GetSize(node **, int);
void GetRank(node **, int);
void PrintRank(node **, int);
void FreeStruct(node **);

int main(void) {
  node *head = NULL;
  int personNum;
  scanf("%d", &personNum);
  GetStruct(&head, personNum);
  GetSize(&head, personNum);
  GetRank(&head, personNum);
  PrintRank(&head, personNum);
  FreeStruct(&head);
  return 0;
}

void GetStruct(node **head, int personNum) {
  node *tmp, *circuit;
  int i;
  tmp = GetNode();
  *head = tmp;
  circuit = tmp;
  for (i = 1; i < personNum; i++) {
    tmp = GetNode();
    circuit->next = tmp;
    circuit = tmp;
  }
  circuit->next = *head;
}

void GetSize(node **head, int personNum) {
  int i;
  node *circuit = *head;
  for (i = 0; i < personNum; i++) {
    scanf("%d %d", &circuit->weight, &circuit->height);
    circuit = circuit->next;
  }
}

void GetRank(node **head, int personNum) {
  int i, j;
  node *tmp, *circuit;
  tmp = *head;
  circuit = tmp->next;
  for (i = 0; i < personNum; i++) {
    for (j = 1; j < personNum; j++) {
      if (circuit->height > tmp->height && circuit->weight > tmp->weight) {
        tmp->rank += 1;
      }
      circuit = circuit->next;
    }
    tmp = tmp->next;
    circuit = tmp->next;
  }
}

node *GetNode(void) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->height = 0;
  tmp->weight = 0;
  tmp->rank = 1;
  tmp->next = NULL;
  return tmp;
}
void PrintRank(node **head, int personNum) {
  int i;
  node *circuit = *head;
  for (i = 0; i < personNum; i++) {
    printf("%d ", circuit->rank);
    circuit = circuit->next;
  }
  putchar('\n');
}

void FreeStruct(node **head) {
  const node *HEAD = *head;
  node *circuit;
  while (*head != HEAD) {
    circuit = *head;
    *head = circuit->next;
    free(circuit);
  }
}