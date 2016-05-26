#include "pov.h"

Direction Pov::turnLeft() {
  switch (dir_) {
    case Direction::North:
      dir_ = Direction::West;
      break;
    case Direction::South:
      dir_ = Direction::East;
      break;
    case Direction::East:
      dir_ = Direction::North;
      break;
    case Direction::West:
      dir_ = Direction::South;
      break;
    case Direction::Stop:
      dir_ = Direction::Stop;
      break;
  }
  return dir_;
}

Direction Pov::turnRight() {
  switch (dir_) {
    case Direction::North:
      dir_ = Direction::East;
      break;
    case Direction::South:
      dir_ = Direction::West;
      break;
    case Direction::East:
      dir_ = Direction::South;
      break;
    case Direction::West:
      dir_ = Direction::North;
      break;
    case Direction::Stop:
      dir_ = Direction::Stop;
      break;
  }
  return dir_;
}

Direction Pov::reverse() {
  switch (dir_) {
    case Direction::North:
      dir_ = Direction::South;
      break;
    case Direction::South:
      dir_ = Direction::North;
      break;
    case Direction::East:
      dir_ = Direction::West;
      break;
    case Direction::West:
      dir_ = Direction::East;
      break;
    case Direction::Stop:
      dir_ = Direction::Stop;
      break;
  }
  return dir_;
}
