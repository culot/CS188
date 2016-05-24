#pragma once

#include <cstdlib>
#include <functional>
#include <vector>
#include <stack>
#include <queue>

namespace util
{

  template<class T>
  using Stack = std::stack<T>;

  template<class T>
  using Queue = std::queue<T>;

  template<class T>
    using PriorityQueue = std::priority_queue<T, std::vector<T>, std::greater<T>>;

  int manhattanDistance(const int x1, const int y1, const int x2, const int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
  }

}
