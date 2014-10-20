#include <iostream>
using namespace std;
#include <string>

void ps(int cur, const string &s, string& t) {
  if (cur == s.size()) {
    cout << t << endl;
    return;
  }
  t += s[cur];
  ps(cur + 1, s, t);
  t.resize(t.size() - 1);
  ps(cur + 1, s, t);
}

void printAllSubstr(string s) {
  string t;
  ps(0, s, t);
}

void perm(int cur, int n, int* p) {
  if (cur == n) {
    for (int i = 0; i < n; i++) {
      cout << p[i] << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = cur; i < n; i++) {
    swap(p[cur], p[i]);
    perm(cur + 1, n, p);
    swap(p[cur], p[i]);
  }
}

void permutation(int n) {
  int *p = new int[n];
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  perm(0, n, p);
  delete []p;
}

bool legal(int *p, int c) {
  for (int i = 0; i < c; i++) {
    if (p[i] == p[c]) {
      return false;
    }
  }
  return true;
}

void bt(int cur, int n, int *p) {
  if (cur == n) {
    for (int i = 0; i < n; i++) {
      cout << p[i] << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    p[cur] = i;
    if (legal(p, cur)) {
      bt(cur + 1, n, p);
    }
  }
}

void permutation_backtrack(int n) {
  // I wanted to do the n-queen stuff but it has more complex legal check
  // the legal check for permuation is easier
  int *p = new int[n];
  bt(0, n, p);
  delete []p;
}

bool legalqueen(int *p, int c) {
  for (int i = 0; i < c; i++) {
    if (p[i] - p[c] == i - c || p[i] - p[c] == c - i || p[i] == p[c]) {
      return false;
    }
  }
  return true;
}

void nq(int cur, int n, int *p) {
  if (cur == n) {
    for (int i = 0; i < n; i++) {
      cout << p[i] << ' ';
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    p[cur] = i + 1;
    if (legalqueen(p, cur)) {
      nq(cur + 1, n, p);
    }
  }
}

void nqueen(int n) {
  int *p = new int[n];
  nq(0, n, p);
  delete []p;
}

int main() {

  int n;
  cin >> n;
//  permutation_backtrack(n);
  nqueen(n);
/*
  string s = "abc";
  printAllSubstr(s);
//*/
}
