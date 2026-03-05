#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Span {
  std::string m_name;

public:
  Span(std::string name) : m_name(name) {
    std::cout << "[DEBUG] Entering function " << name << std::endl;
  }
  ~Span() { std::cout << "[DEBUG] Leaving function " << m_name << std::endl; }
};

int fact(int n) {
  std::stringstream sstm;
  sstm << "fact(" << n << ")";
  Span _ = Span(sstm.str());
  if (n <= 1)
    return 1;

  return n * fact(n - 1);
}

int main() {
  Span _ = Span("main");

  std::cout << fact(5) << std::endl;

  return 0;
}
