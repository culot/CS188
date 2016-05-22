#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>
#include <map>
#include <vector>
#include <string>

struct fruitOrder {
  std::string  fruit;
  double       numPounds;
};

using orderList = std::vector<fruitOrder>;

double buyLotsOfFruit(const orderList& list) {
  static const std::map<std::string, double> fruitPrices = {
    {"apples", 2.0},
    {"oranges", 1.50},
    {"pears", 1.75},
    {"limes", 0.75},
    {"strawberries", 1.00}
  };

  double totalCost = 0.0;
  for (const auto& order : list) {
    std::cout << "Buying " << order.numPounds << " pounds of " << order.fruit << std::endl;
    double pricePerPound = fruitPrices.at(order.fruit);
    totalCost += pricePerPound * order.numPounds;
  }

  std::cout << "Total cost: " << totalCost << std::endl;

  return totalCost;
}

int main(void) {

  double totalCost;

  orderList list1 = {{"apples", 2.0}, {"pears", 3.0}, {"limes", 4.0}};
  totalCost = buyLotsOfFruit(list1);
  assert(std::abs(totalCost - 12.25) < std::numeric_limits<double>::epsilon());

  orderList list2 = {{"apples", 4.0}, {"pears", 3.0}, {"limes", 2.0}};
  totalCost = buyLotsOfFruit(list2);
  assert(std::abs(totalCost - 14.75) < std::numeric_limits<double>::epsilon());

  orderList list3 = {{"apples", 1.25}, {"pears", 1.50}, {"limes", 1.75}};
  totalCost = buyLotsOfFruit(list3);
  assert(std::abs(totalCost - 6.4375) < std::numeric_limits<double>::epsilon());

  return 0;
}
