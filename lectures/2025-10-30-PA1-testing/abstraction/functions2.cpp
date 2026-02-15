#include <iostream>
#include <ostream>
#include <vector>

template <typename T> bool contains(std::vector<T> vec, T val) {
  for (auto num : vec)
    if (num == val)
      return true;

  return false;
}

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<double> vec_dbl = {1.0, 0.5, 3, 4, 5};

  if (contains(vec, 4)) {
    std::cout << "There is 4 in the vector" << std::endl;
  } else {
    std::cout << "There is no 4 in the vector" << std::endl;
  }

  if (contains(vec, 5)) {
    std::cout << "There is 5 in the vector" << std::endl;
  } else {
    std::cout << "There is no 5 in the vector" << std::endl;
  }

  if (contains(vec, 10)) {
    std::cout << "There is 10 in the vector" << std::endl;
  } else {
    std::cout << "There is no 10 in the vector" << std::endl;
  }

  if (contains(vec_dbl, 0.5)) {
    std::cout << "There is 1/2 in the double vector" << std::endl;
  } else {
    std::cout << "There is no 1/2 in the double vector" << std::endl;
  }

  return 0;
}
