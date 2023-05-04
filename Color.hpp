#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{
  typedef unsigned char rgb_value;

  /**
   * @brief Color representation as 3 integer values (red, green and blue).
   * @author Joana Noites
   * 
   */
  class Color
  {
    private:
      rgb_value red_;
      rgb_value green_;
      rgb_value blue_;
    public:
      /**
       * @brief Construct the color black (0, 0, 0).
       */
      Color();

      /**
       * @brief Construct a color by copying.
       * 
       * @param c Color to copy
       */
      Color(const Color& c);

      /**
       * @brief Construct a new Color object with provided parameters r, g and b.
       * 
       * @param r Red
       * @param g Green
       * @param b Blue
       */
      Color(rgb_value r, rgb_value g, rgb_value b);
      
      rgb_value red() const;
      rgb_value& red();
      rgb_value green() const;
      rgb_value& green();
      rgb_value blue() const;
      rgb_value& blue();
  };
}
#endif
