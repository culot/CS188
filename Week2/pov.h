#pragma once

enum class Direction {
  North,
  South,
  East,
  West,
  Stop
}; 

class Pov {
  public:
    void      setDirection(Direction direction) {currentDirection_ = direction;}
    Direction getDirection() {return currentDirection_;}

    Direction turnLeft();
    Direction turnRight();
    Direction reverse();

  private:
    Direction currentDirection_ {Direction::Stop};
};
