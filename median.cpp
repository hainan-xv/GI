#include <iostream>
using namespace std;

double search(int A[], int m, int B[], int n, int k) {
  // k is 1 based
  if (m < n) {
    return search(B, n, A, m, k);
  }
  // now m >= n
  if (n == 0) {
    return A[k - 1];
  }
  if (k == 1) {
    return min(A[0], B[0]);
  }
  int db = k / 2, da = k - k / 2;
  if (db <= n) {
    int a = A[da - 1], b = B[db - 1];
    if (a == b) {
      return a;
    }
    else if (a > b) {
      return search(A, m - da, B + db, n - db, k - db);
    }
    else {
      return search(A + da, m - da, B, n - db, k - da);
    }
  }
  else { // k / 2 > n
    db = n;
    da = k - n;
    int a = A[da - 1], b = B[db - 1];
    if (a == b) {
      return a;
    }
    else if (a > b) {
      return search(A, m - da, B + db, n - db, k - db);
    }
    else {
      return search(A + da, m - da, B, n - db, k - da);
    }
  }
  
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
  int t = m + n;
  if (t % 2 == 1) {
    return search(A, m, B, n, t / 2);
  }
  else {
    return (search(A, m, B, n, t / 2) + search(A, m, B, n, t / 2 + 1)) / 2.0;
  }
}

int main() {
  int A[] = {1,2,3};
  int B[] = {4};
  cout << search(A, sizeof(A)/sizeof(int), B, sizeof(B)/sizeof(int), 4) << endl;
}
