#include <iostream>
#include <limits>
#include <tuple>
#include <string>
#include <vector>
#include <map>

struct FruitOrder {
  std::string  fruit;
  double       numPounds;

  friend std::ostream& operator<<(std::ostream &out, const FruitOrder& order) {
    out << "('" << order.fruit << "', " << order.numPounds << ")";
    return out;
  }
};

using OrderList = std::vector<FruitOrder>;
using FruitPrices = std::map<std::string, double>;  // fruit -> price

class FruitShop {
  public:
    std::string getName() const {return shopName_;}

    FruitShop(const std::string& shopName, const FruitPrices& fruitPrices) 
      : shopName_(shopName), prices_(fruitPrices) {
        std::cout << "Welcome to " << shopName_ << " fruit shop" << std::endl;
      }

    double getPriceOfOrder(const OrderList& list) const {
      double cost = 0.;
      for (const auto& order : list) {
        bool found;
        double price;
        std::tie(found, price) = getCostPerPound(order.fruit);
        if (found) {
          cost += price * order.numPounds;
        }
      }
      return cost;
    }

  private:
    std::tuple<bool, double> getCostPerPound(const std::string& fruitName) const {
      if (prices_.find(fruitName) == prices_.end()) {
        std::cout << "Sorry we don't have " << fruitName << std::endl;
        return std::make_tuple(false, 0.);
      } else {
        return std::make_tuple(true, prices_.at(fruitName));
      }
    }

    std::string shopName_;
    FruitPrices prices_;
};

class ShopSmart {
  public:
    ShopSmart(const OrderList& order, const std::vector<FruitShop>& shops)
      : order_(order), shops_(shops) {
        double cheapestPrice = std::numeric_limits<double>::max();
        for (const auto& shop : shops_) {
          double price = shop.getPriceOfOrder(order_);
          if (price < cheapestPrice) {
            cheapestPrice = price;
            cheapestShop_ = shop.getName();
          }
        }
      }

    std::string getName() const {return cheapestShop_;}

  private:
    std::string             cheapestShop_;
    OrderList               order_;
    std::vector<FruitShop>  shops_;
};

int main(void) {
  FruitPrices pricesForShop1 = {{"apples", 2.0}, {"oranges", 1.0}};
  FruitPrices pricesForShop2 = {{"apples", 1.0}, {"oranges", 5.0}};
  FruitShop shop1("shop1", pricesForShop1);
  FruitShop shop2("shop2", pricesForShop2);
  std::vector<FruitShop> shops = {shop1, shop2};

  OrderList orders1 = {{"apples", 1.0}, {"oranges", 3.0}};
  std::cout << "For 1st order the best shop is "
    << ShopSmart(orders1, shops).getName() << std::endl;

  OrderList orders2 = {{"apples", 3.0}};
  std::cout << "For 2nd order the best shop is "
    << ShopSmart(orders2, shops).getName() << std::endl;

  return 0;
}
