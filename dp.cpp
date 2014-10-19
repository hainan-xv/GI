#include <iostream>
using namespace std;
#include <string>

int LCS(string a, string b) {  // assuming length < 99
/*
t[i][j] means the LCS of a[0 ... i-1] and b[0 ... j-1]
for example, t[0][0] means LCS of empty_string and empty_string
and t[1][1] means LCS of a[0] and b[0]
*/
  int t[100][100];
  for (int i = 0; i <= a.size(); i++) {
    t[i][0] = 0;
  }
  for (int i = 0; i <= b.size(); i++) {
    t[0][i] = 0;
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      if (a[i] == b[j]) {
        t[i+1][j+1] = t[i][j] + 1;  // +1 in the index
        //  because of our definition of t[i][j]
      }
      else {
        t[i+1][j+1] = max(t[i+1][j], t[i][j+1]);
      }
    }
  }
  return t[a.size()][b.size()];
}

int LIS(int *a, int n) {  // longest monotonically increasing sebsequence
  int *p = new int[n];
/*
  p[i] is the LIS that ends with a[i]
*/
  p[0] = 1;
  for (int i = 1; i < n; i++) {
    int Max = 1;
    for (int j = 0; j < i; j++) {
      if (a[i] > a[j]) {
        Max = max(Max, p[i] + 1);
      }
    }
    p[i] = Max;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans = max(ans, p[i]);
  }
  delete []p;

  return ans;
}


int main() {
  int t[] = {-1,11,12,13,4,5,67,1,2,3,4,5,6};
  cout << LIS(t, sizeof(t) / sizeof(int)) << endl;
/*
  string a, b;
  cin >> a >> b;
  cout << LCS(a, b) << endl;
//*/
}
