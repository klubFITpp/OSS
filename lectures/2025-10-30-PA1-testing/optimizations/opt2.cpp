#include <climits>
#include <iostream>
#include <ostream>
#include <vector>

int find_min(std::vector<int> vec) {
  int min = INT_MAX;

  for (int i = 0; i < vec.size(); i++) {
    if (min > vec[i])
      min = vec[i];
  }

  return min;
}

int find_min_sorted(std::vector<int> &vec) { return vec[0]; }

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};

  std::cout << "Minimum: " << find_min(vec) << std::endl;
  std::cout << "Faster minimum: " << find_min_sorted(vec) << std::endl;
}
