#include "Image.hpp"

namespace prog
{
  Image::Image(int w, int h, const Color &fill):
    width_(w), 
    height_(h), 
    data_(h, std::vector<Color>(w, fill)) {}

  Image::~Image() {}
  
  int Image::width() const
  {
    return width_;
  }
  int Image::height() const
  {
    return height_;
  }


  Color& Image::at(int x, int y)
  {
    return data_[y][x];
  }

  const Color& Image::at(int x, int y) const
  {
    return data_[y][x];
  }
}
