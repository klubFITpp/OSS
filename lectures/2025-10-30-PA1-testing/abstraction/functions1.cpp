#include <iostream>
#include <ostream>
#include <vector>

bool contains_int(std::vector<int> vec, int val) {
  for (auto num : vec)
    if (num == val)
      return true;

  return false;
}

bool contains_double(std::vector<double> vec, double val) {
  for (auto num : vec)
    if (num == val)
      return true;

  return false;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<double> vec_dbl = {1.0, 0.5, 3, 4, 5};

  if (contains_int(vec, 4)) {
    std::cout << "There is 4 in the vector" << std::endl;
  } else {
    std::cout << "There is no 4 in the vector" << std::endl;
  }

  if (contains_int(vec, 5)) {
    std::cout << "There is 5 in the vector" << std::endl;
  } else {
    std::cout << "There is no 5 in the vector" << std::endl;
  }

  if (contains_int(vec, 10)) {
    std::cout << "There is 10 in the vector" << std::endl;
  } else {
    std::cout << "There is no 10 in the vector" << std::endl;
  }

  if (contains_double(vec_dbl, 0.5)) {
    std::cout << "There is 1/2 in the double vector" << std::endl;
  } else {
    std::cout << "There is no 1/2 in the double vector" << std::endl;
  }

  return 0;
}
