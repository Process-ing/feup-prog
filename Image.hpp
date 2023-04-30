#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>

namespace prog
{
  /**
   * @brief 2D grid that represents an image using vectors that hold RGB color values
   * 
   */
  class Image
  {
  private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> data_;
  public:
    /**
     * @brief Construct a new Image object
     * 
     * @param w Width
     * @param h Height
     * @param fill Fill color
     */
    Image(int w, int h, const Color &fill = {255, 255, 255});
    /**
     * @brief Destroy the Image object, in this case, it is not necessary
     * 
     */
    ~Image();
    int width() const;
    int height() const;
    /**
     * @brief Mutable function that returns the wanted color value
     * 
     * @param x 
     * @param y 
     * @return Color& Mutable value
     */
    Color &at(int x, int y);
    /**
     * @brief Constant function that returns the wanted color value
     * 
     * @param x 
     * @param y 
     * @return const Color& Constant value
     */
    const Color &at(int x, int y) const;
  };
}
#endif
