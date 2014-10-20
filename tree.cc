#include <iostream>
using namespace std;

typedef struct _treeNode {
  _treeNode() {
    val = "";
    L = R = NULL;
  }
  string val;
  _treeNode *L;
  _treeNode *R;
} treeNode;

/*
3 ()()

//*/
string toString(treeNode *root) {
  if (root == NULL) {
    return "()";
  }
  string ans;
  ans += "(";
  ans += root->val;
  ans += ' ';
  ans += toString(root->L);
  ans += toString(root->R);
  ans += ")";
  return ans;
}

treeNode* fromString(string s, int &cur) {
  s[cur] == '(';
  cur++;
  if (s[cur] == ')') {
    cur++;
    return NULL;
  }
  treeNode *root = new treeNode();

  while (s[cur] != ' ') {
    root->val += s[cur++];
  }
  cur++;
  s[cur] == '('; 
  root->L = fromString(s, cur);
  root->R = fromString(s, cur);
  s[cur++] == ')';

  return root;
}  

treeNode* fromString(string s) {
  int i = 0;
  return fromString(s, i);
}

int main() {
  treeNode *root = new treeNode();
  treeNode *a = new treeNode();
  treeNode *b = new treeNode();
  root->val = "root";
  a->val = "a";
  b->val = "b";
  root->L = a;
  root->R = b;

  string ans = toString(root);

  cout << ans << endl;

  treeNode *newTree = fromString(ans);
  cout << toString(newTree) << endl;
}
