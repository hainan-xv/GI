#include <iostream>
using namespace std;

namespace array {
class stack {
 public:
  stack(){
    size = 0;
    capacity = 16;
    p = new int[capacity];
  }

  ~stack() {
    delete []p;
  }

  void resize() {
    capacity *= 2;
    int *p2 = new int[capacity];
    for (int i = 0; i < size; i++) {
      p2[i] = p[i];
    }
    delete []p;
    p = p2;
  }

  void push(int i) {
    if (size == capacity) {
      resize();
    }
    p[size++] = i;
  }

  int top() {
    if (size == 0) {
      cout << "bad" << endl;
      return -1;
    }
    return p[size - 1];
  }

  void pop() {
    if (size == 0) {
      cout << "bad" << endl;
      return;
    }
    size--;
  }

  int Size() {
    return size;
  }

 private:
  int *p;
  int size;
  int capacity;
};

}  // namespace array

int main() {
  using namespace array;
  stack s;

  for (int i = 0; i < 99; i++) {
    s.push(i);
  }
  
  while (s.Size() != 0) {
    cout << s.top() << ' ';
    s.pop();
  }
}
