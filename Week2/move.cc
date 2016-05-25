#include "move.h"

Direction Move::turnLeft() {
  switch (current_) {
    case Direction::North:
      current_ = Direction::West;
      break;
    case Direction::South:
      current_ = Direction::East;
      break;
    case Direction::East:
      current_ = Direction::North;
      break;
    case Direction::West:
      current_ = Direction::South;
      break;
    case Direction::Stop:
      current_ = Direction::Stop;
      break;
  }
  return current_;
}

Direction Move::turnRight() {
  switch (current_) {
    case Direction::North:
      current_ = Direction::East;
      break;
    case Direction::South:
      current_ = Direction::West;
      break;
    case Direction::East:
      current_ = Direction::South;
      break;
    case Direction::West:
      current_ = Direction::North;
      break;
    case Direction::Stop:
      current_ = Direction::Stop;
      break;
  }
  return current_;
}

Direction Move::reverse() {
  switch (current_) {
    case Direction::North:
      current_ = Direction::South;
      break;
    case Direction::South:
      current_ = Direction::North;
      break;
    case Direction::East:
      current_ = Direction::West;
      break;
    case Direction::West:
      current_ = Direction::East;
      break;
    case Direction::Stop:
      current_ = Direction::Stop;
      break;
  }
  return current_;
}
