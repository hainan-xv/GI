#include <iostream>
using namespace std;
#include <stack>

typedef struct _treeNode {
  _treeNode() {
    val = "";
    L = R = NULL;
  }
  string val;
  _treeNode *L;
  _treeNode *R;
} treeNode;

void preOrder(treeNode *root) {
  stack<treeNode*> s;
  s.push(root);
  while (s.size() != 0) {
    treeNode *t = s.top();
    s.pop();
    cout << t->val << ' ';
    if (t->R != NULL) {
      s.push(t->R);
    }
    if (t->L != NULL) {
      s.push(t->L);
    }
  }
  cout << endl;
}

void inOrder(treeNode *root) {
  stack<treeNode*> s;
  treeNode *t = root;
  while (t != NULL) {
    s.push(t);
    t = t->L;
  }
  while (s.size() != 0) {
    treeNode *h = s.top();
    s.pop();
    cout << h->val << ' ';
    t = h->R;
    while (t != NULL) {
      s.push(t);
      t = t->L;
    }
  }
  cout << endl;
}

void postOrder(treeNode *root) {
  stack<treeNode*> s;
  treeNode *t = root;
  while (t != NULL) {
    s.push(t);
    if (t->L != NULL) {
      t = t->L;
    }
    else {
      t = t->R;
    }
  }
  while (s.size() != 0) {
    treeNode *h = s.top();
    s.pop();
    cout << h->val << ' ';
    if (s.size() != 0) {
      t = s.top();
      if (t->R == h) {
        continue;
      }
      t = t->R;
      while (t != NULL) {
        s.push(t);
        if (t->L != NULL) {
          t = t->L;
        }
        else {
          t = t->R;
        }
      }
    }
  }
  cout << endl;
}

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

  preOrder(root);
  inOrder(root);
  postOrder(root);

  string ans = toString(root);

  cout << ans << endl;

  treeNode *newTree = fromString(ans);
  cout << toString(newTree) << endl;
}
