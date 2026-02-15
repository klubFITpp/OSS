#include <cassert>
#include <climits>
#include <cstdio>
#include <iostream>
#include <ostream>

/// Remainder after dividing a number by two
int rem2(int num) { return (num < 0 ? -1 : 1) * num % 2; }

#ifndef __PROGTEST__

inline void my_assert(bool assertion) {
  if (!assertion)
    printf("Faied a test... %d\n", __LINE__);
}

void run_tests() {
  // basic tests
  assert(rem2(0) == 0);
  assert(rem2(1) == 1);
  assert(rem2(2) == 0);
  assert(rem2(3) == 1);
  assert(rem2(4) == 0);
  assert(rem2(5) == 1);
  assert(rem2(-1) == 1);
  assert(rem2(INT_MAX) == 1);
}

#endif

int main() {
#ifndef __PROGTEST__
  printf("Running tests...\n");
  std::cout << "Running tests..." << std::endl;
  run_tests();
  std::cout << "All tests passed!" << std::endl;
#endif

  // TODO: parse input (input_data_t in = parse_input())
  int input = 123;
  int result = rem2(123);

  // TODO: print in progtest format (print_results(result))
}
