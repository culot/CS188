#include "pov.h"

Direction Pov::turnLeft() {
  switch (currentDirection_) {
    case Direction::North:
      currentDirection_ = Direction::West;
      break;
    case Direction::South:
      currentDirection_ = Direction::East;
      break;
    case Direction::East:
      currentDirection_ = Direction::North;
      break;
    case Direction::West:
      currentDirection_ = Direction::South;
      break;
    case Direction::Stop:
      currentDirection_ = Direction::Stop;
      break;
  }
  return currentDirection_;
}

Direction Pov::turnRight() {
  switch (currentDirection_) {
    case Direction::North:
      currentDirection_ = Direction::East;
      break;
    case Direction::South:
      currentDirection_ = Direction::West;
      break;
    case Direction::East:
      currentDirection_ = Direction::South;
      break;
    case Direction::West:
      currentDirection_ = Direction::North;
      break;
    case Direction::Stop:
      currentDirection_ = Direction::Stop;
      break;
  }
  return currentDirection_;
}

Direction Pov::reverse() {
  switch (currentDirection_) {
    case Direction::North:
      currentDirection_ = Direction::South;
      break;
    case Direction::South:
      currentDirection_ = Direction::North;
      break;
    case Direction::East:
      currentDirection_ = Direction::West;
      break;
    case Direction::West:
      currentDirection_ = Direction::East;
      break;
    case Direction::Stop:
      currentDirection_ = Direction::Stop;
      break;
  }
  return currentDirection_;
}
