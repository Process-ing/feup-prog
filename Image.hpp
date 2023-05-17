#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>

namespace prog
{
  /**
   * @brief 2D grid that represents an image using vectors that hold RGB color values.
   */
  class Image
  {
  private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> data_;

  public:
    /**
     * @brief Construct a new Image object with the given width w and height h
     *        and filled with color fill.
     * @author João Mendes
     * 
     * @param w Width
     * @param h Height
     * @param fill Fill color
     */
    Image(int w, int h, const Color &fill = { 255, 255, 255 });

    ~Image();
    int width() const;
    int height() const;

    /**
     * @brief Returns a mutable reference to the color in pixel (x, y).
     * @author João Mendes
     * 
     * @param x Coordinate x
     * @param y Coordinate y
     * @return Mutable reference to the color.
     */
    Color &at(int x, int y);

    /**
     * @brief Returns a constant reference to the color in pixel (x, y).
     * @author João Mendes
     * 
     * @param x Coordinate x
     * @param y Coordinate y
     * @return Constant reference to the color.
     */
    const Color &at(int x, int y) const;
  };
}
#endif
