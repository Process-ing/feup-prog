#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__
#include "Color.hpp"
#include <vector>

namespace prog
{
  /**
   * @brief 2D grid that represents an image using vectors that hold RGB color values.
   * @author João Mendes
   */
  class Image
  {
  private:
    int width_;
    int height_;
    std::vector<std::vector<Color>> data_;

  public:
    /**
     * @brief Construct a new Image object with the given width and height
     *        and filled with color fill.
     * 
     * @param w Width.
     * @param h Height.
     * @param fill Fill color.
     */
    Image(int w, int h, const Color &fill = {255, 255, 255});

    ~Image();
    int width() const;
    int height() const;

    /**
     * @brief Mutable function that returns the color at (x, y).
     * 
     * @param x 
     * @param y 
     * @return Color& Reference to the color at (x, y).
     */
    Color &at(int x, int y);

    /**
     * @brief Constant function that returns the color at (x, y).
     * 
     * @param x 
     * @param y 
     * @return const Color& Color at (x, y).
     */
    const Color &at(int x, int y) const;
  };
}
#endif
