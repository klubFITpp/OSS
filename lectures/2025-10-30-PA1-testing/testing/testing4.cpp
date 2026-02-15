#include <cassert>
#include <climits>
#include <cstdio>
#include <iostream>
#include <ostream>

/// Returns
int avg2(int x, int y) {
  long x1 = x;
  long x2 = y;

  return (x1 + x2) / 2;
}

#ifndef __PROGTEST__

void run_tests() {
  // basic tests
  assert(avg2(0, 0) == 0);
  assert(avg2(0, 2) == 1);
  assert(avg2(-5, 5) == 0);
  assert(avg2(-15, 5) == -5);
  assert(avg2(INT_MAX, INT_MAX) == INT_MAX);
}
#endif

int main() {
#ifndef __PROGTEST__

  std::cout << "Running tests..." << std::endl;
  run_tests();
  std::cout << "All tests passed!" << std::endl;

#endif
}
