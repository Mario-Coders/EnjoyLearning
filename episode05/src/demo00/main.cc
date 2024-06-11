#include <iostream>

// Guide class for global constants of template.
template <typename T>
struct IsMoreThatPtr {
  static constexpr bool value = sizeof(T) > sizeof(void*);
};

// Global constants of template.
template <typename T>
constexpr inline bool IsMoreThatPtr_v = IsMoreThatPtr<T>::value;

void TestIsMoreThatPtr() {
  std::cout << IsMoreThatPtr_v<int> << std::endl;
  std::cout << IsMoreThatPtr_v<long long> << std::endl;
  std::cout << IsMoreThatPtr_v<float> << std::endl;
  std::cout << IsMoreThatPtr_v<double> << std::endl;
}

int main(void) {
  TestIsMoreThatPtr();
  return 0;
}
