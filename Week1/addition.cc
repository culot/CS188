#include <iostream>
#include <cassert>
#include <limits>

// Return the sum of lhs and rhs
template<class T>
T add(const T& lhs, const T& rhs) {
  T sum = lhs + rhs;

  std::cout << "Passed lhs=[" << lhs << "] and rhs=[" << rhs
    << "], returning lhs + rhs =[" << sum << "]" << std::endl;

  return sum;  
}

int main(void) {
  double sum;

  sum = add(1, 1);
  assert(sum - 2 < std::numeric_limits<double>::epsilon());

  sum = add(2, 3);
  assert(sum - 5 < std::numeric_limits<double>::epsilon());

  sum = add(10., -2.1);
  assert(sum - 7.9 < std::numeric_limits<double>::epsilon());

  return 0;
}
