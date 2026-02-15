#include <iostream>
#include <ostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  bool contains4 = false;
  for (int num : vec)
    if (num == 4) {
      contains4 = true;
      break;
    }

  if (contains4) {
    std::cout << "There is 4 in the vector" << std::endl;
  } else {
    std::cout << "There is no 4 in the vector" << std::endl;
  }

  bool contains5 = false;
  for (int num : vec)
    if (num == 5) {
      contains5 = true;
      break;
    }

  if (contains5) {
    std::cout << "There is 5 in the vector" << std::endl;
  } else {
    std::cout << "There is no 5 in the vector" << std::endl;
  }

  bool contains10 = false;
  for (int num : vec)
    if (num == 5) {
      contains10 = true;
      break;
    }
  if (contains10) {
    std::cout << "There is 10 in the vector" << std::endl;
  } else {
    std::cout << "There is no 10 in the vector" << std::endl;
  }

  return 0;
}
