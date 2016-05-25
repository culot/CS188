#pragma once

enum class Direction {
  North,
  South,
  East,
  West,
  Stop
}; 

class Move {
  public:
    void      setDirection(Direction direction) {current_ = direction;}
    Direction getDirection() {return current_;}

    Direction turnLeft();
    Direction turnRight();
    Direction reverse();

  private:
    Direction current_ {Direction::Stop};
};
