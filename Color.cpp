#include "Color.hpp"

namespace prog {
    Color::Color() {

    }
    Color::Color(const Color& other) {

    }
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {

    }
    rgb_value Color::red() const {
        return 0;
    }
    rgb_value Color::green() const {
        return 0;
    }
    rgb_value Color::blue() const {
        return 0;
    }


    rgb_value& Color::red()  {
        return red_;
    }
    rgb_value& Color::green()  {
      return green_;
    }
    rgb_value& Color::blue()  {
      return blue_;
    }
}
