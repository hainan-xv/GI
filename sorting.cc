#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void initialize(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = i;
  }
}

void randomize(int *a, int n) {
  for (int i = 0; i < n; i++) {
    int r = rand() % n;
    swap(a[i], a[r]);
  }
}

void print(int *a, int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << endl;
}

void checkSorted(int *a, int n) {
  for (int i = 1; i < n; i++) {
    if (a[i-1] > a[i]) {
      cout << "bad!!" << endl;
    }
  }
}

void insertionSort(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int m = a[i];
    while (j >= 0 && a[j] > m) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = m;
  }
  checkSorted(a, n);
}

int partition(int *a, int n) {
  int pivot = a[0];
  int div = 0;  // a[div] <= pivot and a[div + 1] > pivot
  for (int i = 1; i < n; i++) {
    if (a[i] <= pivot) {
      div++;
      swap(a[div], a[i]);
    }
  }
  swap(a[0], a[div]);
  return div;
}

int select(int *a, int n, int i) {  // size is n, select i'th
  if (i >= n || i < 0) {
    cout << "bad" << endl;
  }
  if (n == 1) {
    return a[0];
  }
  int p = partition(a, n);
  if (p == i) return a[p];
  else if (p < i) {
    return select(a + p + 1, n - p - 1, i - p - 1);
  }
  else {
    return select(a, p, i);
  }
}

void quickSort(int *a, int n) {
  if (n < 2) return;
  int p = partition(a, n);
  quickSort(a, p);
  quickSort(a + p + 1, n - p - 1);
}

void siftDown(int *a, int i, int n) {
  //  if a node is smaller than its children than sift down
  if (i >= n) return;
  int left = 2 * i + 1, right = left + 1;
  if (left >= n) {
    return;
  }
  else if (right >= n) {  // only have left child
    if (a[left] > a[i]) {
      swap(a[left], a[i]);
    }
  }
  else {  // have both children
    if (a[left] > a[right]) {
      if (a[left] > a[i]) {
        swap(a[left], a[i]);
        siftDown(a, left, n);
      }
    }
    else {
      if (a[right] > a[i]) {
        swap(a[right], a[i]);
        siftDown(a, right, n);
      }
    }
  }
}

void checkHeap(int *a, int n) {
  for (int i = 1; i < n; i++) {
    int parent = (i - 1) / 2;
    if (a[parent] < a[i]) {
      cout << a[parent] << ' ' << a[i] << ' ';
      cout << "bad!!" << endl;
    }
  }
}

void makeHeap(int *a, int n) {
  for (int i = n / 2; i >= 0; i--) {
    siftDown(a, i, n);
  }
  checkHeap(a, n);
}

void heapSort(int *a, int n) {
  makeHeap(a, n);
  int i = n - 1;
  while (i > 0) {
    swap(a[0], a[i]);
    siftDown(a, 0, i);
    i--;
  }
}

void merge(int *a, int mid, int n) {
  int *p = new int[n];
  int i = 0, j = mid;
  int cur = 0;
  while (i < mid && j < n) {
    if (a[i] < a[j]) {
      p[cur++] = a[i++];
    }
    else {
      p[cur++] = a[j++];
    }
  }
  while (i < mid) {
    p[cur++] = a[i++];
  }
  while (j < n) {
    p[cur++] = a[j++];
  }

  for (i = 0; i < n; i++) {
    a[i] = p[i];
  }

  delete []p;
}

void mergeSort(int *a, int n) {
  if (n < 2) return;
  int mid = n / 2;
  mergeSort(a, mid);
  mergeSort(a + mid, n - mid);
  merge(a, mid, n);
}

int main() {
  int size = 32;
  int *p = new int[size];
  initialize(p, size);
  print(p, size);
  randomize(p, size);
  print(p, size);
  cout << select(p, size, 3) << endl;
  cout << select(p, size, 13) << endl;
  cout << select(p, size, 23) << endl;
  cout << select(p, size, 8) << endl;
  mergeSort(p, size);
  print(p, size);
}
