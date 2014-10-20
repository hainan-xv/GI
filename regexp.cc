#include <iostream>
using namespace std;
#include <string>

/*
   . matches any single char
   a* matches "", "a", "aa", ...
   .* matches any string
   a matches "a"
*/

bool match(string a, int i, int sa,
           string r, int j, int sr) {
  if (sr - j == 1) {
    if (sa - i != 1) {
      return false;
    }
    else if (r[j] == '.') {
      return true;
    }
    else {
      return r[j] == a[i];
    }
  }
  else if (sr - j == 2 && r[j + 1] == '*') {
    if (r[j] == '.') {
      return true;
    }
    else {
      for (; i < sa; i++) {
        if (a[i] != r[j]) {
          return false;
        }
      }
      return true;
    }
  }
  else if (r[j + 1] == '*') {
    for (int k = i; k < sa; k++) {
      bool m1 = match(a, i, k, r, j, 2);
      bool m2 = match(a, k, sa, r, 2, sr);
      if (m1 && m2) {
        return true;
      }
    }
    return false;
  }
  else {  // length >= 2, second symbol not star
    if (r[j] == '.') {
      return match(a, i + 1, sa,
                   r, j + 1, sr);
    }
    else {
      if (a[i] != r[j]) {
        return false;
      }
      return match(a, i + 1, sa,
                   r, j + 1, sr);
    }
  }
}

bool match(string a, string reg) {
  return match(a, 0, a.size(), reg, 0, reg.size());
}

int main() {
  string a = "abcdefg";
  string exp = "a.*.f.";

  while (cin >> a >> exp) {
    if (match(a, exp)) {
      cout << "match" << endl;
    }
    else {
      cout << "not match" << endl;
    }
  }
}
