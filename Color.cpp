#include "Color.hpp"

#include <iomanip>
#include <sstream>

using namespace std;

namespace prog {
    Color::Color() {
        red_ = 0;
        green_ = 0;
        blue_ = 0;
    }
    
    Color::Color(const Color& other) {
        red_ = other.red_;
        green_ = other.green_;
        blue_ = other.blue_;
    }
    
    Color::Color(rgb_value red, rgb_value green, rgb_value blue) {
        red_ = red;
        green_ = green;
        blue_ = blue;
    }

    Color::Color(const string& hex) {
        red_ = stoi(hex.substr(1, 2), nullptr, 16);
        green_ = stoi(hex.substr(3, 2), nullptr, 16);
        blue_ = stoi(hex.substr(5, 2), nullptr, 16);
    }

    rgb_value Color::red() const {
        return red_;
    }
    rgb_value Color::green() const {
        return green_;
    }
    rgb_value Color::blue() const {
        return blue_;
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

    bool Color::operator==(const Color& other) const {
        return red_ == other.red_ && green_ == other.green_ && blue_ == other.blue_;
    }

    bool Color::operator<(const Color& other) const {
        return (red_ < other.red_)
            || (red_ == other.red_ && ((green_ < other.green_)
            || (green_ == other.green_ && blue_ < other.blue_)));
    }

    string Color::to_hex() const {
        ostringstream hex;

        hex << '#' << setfill('0') << std::hex << setw(2) << (int)red_
            << std::hex << setw(2) << (int)green_
            << std::hex << setw(2) << (int)blue_;

        return hex.str();
    }
}

