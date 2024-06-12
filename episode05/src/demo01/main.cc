#include <iostream>

template<typename T>
void Print(std::ostream& os, const T& t) {
  os << t << "|";
  os << std::endl;
}

template<typename T, typename... Args>
void Print(std::ostream& os, const T& t, const Args&... rest) {
  os << t << "|";
  Print(os, rest...);
}

int main() {
  Print(std::cout, "hello,world", 3, 3.14);
  return 0;
}
