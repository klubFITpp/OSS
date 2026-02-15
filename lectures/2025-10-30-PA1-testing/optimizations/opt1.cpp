#include <iostream>
#include <ostream>

int main() {

  for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
  }

  // vs
  for (int i = 0; i < 10; ++i) {
    std::cout << i << std::endl;
  }
}

// ++i
int pre_inc(int &val) {
  val = val + 1;
  return val;
}

// i++
int post_inc(int &val) {
  int pre = val;
  val = val + 1;
  return pre;
}

// https://godbolt.org/
