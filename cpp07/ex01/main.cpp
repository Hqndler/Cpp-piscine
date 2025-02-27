#include "iter.hpp"

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  int tabc[] = { 67, 104, 101, 108, 111, 117};
  double tab2[] = { 10.1, 11.2, 12.3, 13.4, 14.5 };
  const std::string tab3[] = { "OMG", "ça", "fonctionne", "de", "fou"};

  iter(tab, 5, print<int>);
  std::cout << std::endl;
  iter(tabc, 6, print<char>);
  std::cout << std::endl;
  iter(tab2, 5, print<float>);
  std::cout << std::endl;
  iter(tab3, 5, print<std::string>);
  std::cout << std::endl;

  return 0;
}