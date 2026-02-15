#include <algorithm>
#include <set>
#include <unordered_set>
#include <vector>

template <typename T> bool contains(const std::vector<T> &vec, const T &val) {
  return std::ranges::find(vec, val) != vec.end();
}

int main() {
  std::set<int> set{1, 2, 5, 10};
  std::unordered_set<int> uset{1, 2, 5, 10};
  std::vector<int> vec{1, 2, 5, 10};

  if (contains(vec, 1)) {
    // do something. Was linear
  }

  if (set.contains(1)) {
    // do something. was logarithmic
  }

  if (uset.contains(1)) {
    // do something. was constant
  }
}
