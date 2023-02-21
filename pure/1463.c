
// https://www.acmicpc.net/problem/1463

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int d;
  struct node *next;
} node;

void Push(node **, node **, int);
int Pop(node **);
int GetCount(node **);
int Empty(node **, node **);
int PrintQueue(node **);

int main(void) {
  int cnt = 0, num = 0, remain;
  node *head = NULL, *tail = NULL;
  scanf("%d", &num);
  Push(&head, &tail, num);
  while (1) {
    remain = GetCount(&head);
    // printf("%d remains.. \n", remain);
    do {
      num = Pop(&head);
      // printf("number: %d \n", num);
      if (num == 1) {
        while (Empty(&head, &tail) == false) {
          Pop(&head);
          // printf("%d Pop!\n", Pop(&head));
        }
        printf("%d \n", cnt);
        return 0;
      }

      if (num % 3 == 0) {
        // printf("Pushed: %d to %d \n", num, num / 3);
        Push(&head, &tail, num / 3);
      }
      if (num % 2 == 0) {
        // printf("Pushed: %d to %d \n", num, num / 2);
        Push(&head, &tail, num / 2);
      }
      // printf("Pushed: %d to %d \n", num, num - 1);
      Push(&head, &tail, num - 1);
    } while (--remain);
    // PrintQueue(&head);
    cnt++;
  }
  // printf("Wrong Executed \n");
  return 0;
}
void Push(node **head, node **tail, int data) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->d = data;
  tmp->next = NULL;
  if (*head == NULL || *tail == NULL) {
    *head = tmp;
    *tail = tmp;
    return;
  }
  (*tail)->next = tmp;
  *tail = tmp;
}

int Pop(node **head) {
  node *tmp = *head;
  int out;
  if (tmp == NULL) {
    return -1;
  }
  out = tmp->d;
  *head = tmp->next;
  free(tmp);
  return out;
}

int GetCount(node **head) {
  int cnt = 0;
  node *tmp = *head;
  while (tmp != NULL) {
    tmp = (tmp)->next;
    cnt++;
  }
  return cnt;
}

int Empty(node **head, node **tail) {
  if (*head == NULL || *tail == NULL) {
    return 1;
  } else {
    return 0;
  }
}
int PrintQueue(node **head) {
  node *tmp = *head;
  // printf("In Queue: ");
  while (tmp != NULL) {
    // printf("%d ", tmp->d);
    tmp = tmp->next;
  }
  // printf("\nPrintQueue Ended!\n");
  return 0;
}