#pragma once

#include <iostream>
#include <map>

enum class Direction {
  North,
  South,
  East,
  West,
  Stop
}; 

static std::map<Direction, const char*> dirToStr = {
  {Direction::North, "North"},
  {Direction::South, "South"},
  {Direction::East,  "East"},
  {Direction::West,  "West"},
  {Direction::Stop,  "Stop"}
};

// The convention for positions, like a graph, is that (0,0) is the lower left corner, x increases
// horizontally and y increases vertically.  Therefore, north is the direction of increasing y, or (0,1).
struct Pos {
  int x, y;
};

class Pov {
  public:
    Pov(const Pos& pos, Direction dir) : pos_(pos), dir_(dir) {}

    bool operator==(const Pov& other) {
      return dir_ == other.dir_ && pos_.x == other.pos_.x && pos_.y == other.pos_.y;
    }
    friend std::ostream& operator<<(std::ostream& os, const Pov& pov) {
      os << "(x,y)=(" << pov.pos_.x << "," << pov.pos_.y << "), "
         << "dir=" << dirToStr[pov.dir_];
      return os;
    }

    void      position(const Pos& pos) {pos_ = pos;}
    void      direction(Direction direction) {dir_ = direction;}
    Pos       getPosition() {return pos_;}
    Direction getDirection() {return dir_;}

    Direction turnLeft();
    Direction turnRight();
    Direction reverse();

  private:
    Pos       pos_ {0, 0};
    Direction dir_ {Direction::Stop};
};
