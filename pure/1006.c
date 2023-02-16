/*
https://www.acmicpc.net/problem/1006
1. Count possible connection(s) of each section. (possible count: 0, 1, 2, 3)
2. Reduce count(s) by connecting each section from small order. (from 1 to 3)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct {
    unsigned char r : 1;
    unsigned char l : 1;
    unsigned char v : 1;
    unsigned char : 5;
  } with;
  unsigned short cnt;
  unsigned short enemy;
  struct node *R;
  struct node *L;
  struct node *V; // vertical link pointer (up || down)
} node;

void GetStruct(node *, int);
node *GetNode(void);        // function in GetStruct()
void GetEnemy(node *, int); // function in GetStruct()
void GetRelation(node *head, int ally);

int main(void) {
  int testCase, nodeNum, ally;
  node *head = NULL;
  ;
  scanf("%d", &testCase);
  while (testCase--) {
    scanf("%d %d", &nodeNum, &ally);
    GetStruct(head, nodeNum);
  }
  return 0;
}

void GetStruct(node *head, int nodeNum) {
  node *tmp, *maker;
  int i;

  tmp = GetNode();
  maker = head = tmp;
  tmp = GetNode();
  maker->V = tmp;
  maker->V->V = maker;
  for (i = 1; i < nodeNum; i++) {
    tmp = GetNode();
    maker->R = tmp;
    maker->R->L = maker;
    tmp = GetNode();
    maker->R->V = tmp;
    maker->R->V->V = maker->R;
    maker->V->R = tmp;
    maker->V->R->L = maker->V;
    maker = maker->R;
  }
  maker->R = head;
  maker->V->R = head->V;
  head->L = maker;
  head->V->L = maker->V;

  GetEnemy(head, nodeNum);
}

node *GetNode(void) {
  node *tmp = (node *)malloc(sizeof(node));
  tmp->L = NULL;
  tmp->R = NULL;
  tmp->V = NULL;
  tmp->enemy = 0;
  return tmp;
}

void GetEnemy(node *head, int nodeNum) {
  int i;
  node *tmp;

  tmp = head;
  for (i = 0; i < nodeNum; i++) {
    scanf("%hd", &tmp->enemy);
    tmp = tmp->R;
  }

  tmp = head->V;
  for (i = 0; i < nodeNum; i++) {
    scanf("%hd", &tmp->enemy);
    tmp = tmp->R;
  }
}

void GetRelation(node *head, int ally) { return; }