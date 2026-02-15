
#include <string>
class MyVec {
private:
  int length = 0;
  int first;

public:
  MyVec() {};

  int size() { return length; }

  void push(int val) { length += 1; }
};

class XYZ : public MyVec {
public:
  XYZ() : MyVec() {}
};

struct Engine {
  void bar(int x) {}
};
struct Wheel {
  void bar(std::string y) {}
};

struct Car {
  Engine eng;
};

struct Car2 : public Engine, public Wheel {
  using Engine::bar;
  using Wheel::bar;
};

int main() {
  Car2 x = Car2();

  x.bar(42);
}
