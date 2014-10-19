#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int SIZE = 52;

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

void freeList(list* head) {
  if (head == NULL) {
    return;
  }
  list *t = head->next;
  delete head;
  freeList(t);
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

list* quickSort(list* head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  list *pivot = head;
  head = head->next;

  list *less = NULL, *more = NULL;
  while (head != NULL) {
    list *head_next = head->next;
    if (head->val < pivot->val) {
      head->next = less;
      less = head;
    }
    else {
      head->next = more;
      more = head;
    }
    head = head_next;
  }

  less = quickSort(less);
  more = quickSort(more);
  pivot->next = more;
  
  list *tail = less;
  if (tail == NULL) {
    return pivot;
  }
  while (tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = pivot;
  return less;
}

int main() {
  int a[SIZE];
  for (int i = 0; i < SIZE; i++) {
    a[i] = i;
  }

  for (int i = 0; i < SIZE; i++) {
    swap(a[i], a[rand() % SIZE]);
  }

  list *l = initializeFromArray(a, SIZE);

  traverseList(l);

  list *r = reverseList(l);

  traverseList(r);

  list *s = quickSort(r);

  traverseList(s);

}
