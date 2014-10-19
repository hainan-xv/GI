#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int SIZE = 5;

typedef struct _list {
  int val;
  _list *next;
} list;

list* initializeFromArray(int *a, int n) {
  list *cur = NULL;
  for (int i = n - 1; i >= 0; i--) {
    list *new_head = new list();
    new_head->next = cur;
    new_head->val = a[i];
    cur = new_head;
  }
  return cur;
}

void traverseList(list* head) {
  while (head != NULL) {
    cout << head->val << ' ';
    head = head->next;
  }
  cout << endl;
}

list* reverseList(list* head) {
  if (head == NULL) {
    return NULL;
  }
  else if (head->next == NULL) {
    return head;
  }
  list *a = head, *b = head->next, *c = b->next;
  a->next = NULL;
  while (c != NULL) {
    b->next = a;
    a = b;
    b = c;
    c = b->next;
  }
  b->next = a;
  return b;
}

int main() {
  int a[SIZE];
  for (int i = 0; i < SIZE; i++) {
    a[i] = i;
  }

  list *l = initializeFromArray(a, SIZE);

  traverseList(l);

  list *r = reverseList(l);

  traverseList(r);
}
