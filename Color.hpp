#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

#include <string>

namespace prog
{
  typedef unsigned char rgb_value;

  /**
   * @brief Color representation as 3 integer values (red, green and blue).
   */
  class Color
  {
    private:
      rgb_value red_;
      rgb_value green_;
      rgb_value blue_;
    public:
      /**
       * @brief Constructs the color black (0, 0, 0).
       * @author Joana Noites
       */
      Color();

      /**
       * @brief Constructs a color by copy.
       * @author Joana Noites
       * 
       * @param c Color to copy
       */
      Color(const Color& other);

      /**
       * @brief Constructs a new Color object with provided rgb values red,
       *        green and blue.
       * @author Joana Noites
       * 
       * @param red Red value
       * @param green Green value
       * @param blue Blue value
       */
      Color(rgb_value red, rgb_value green, rgb_value blue);

      /**
     * @brief Constructs a Color object with its hexadecimal representation.
     * @author Bruno Oliveira & João Mendes
     * 
     * @param hex String with hexadecimal value of the color, in the format
     *            #XXXXXX
     */
      Color(const std::string& hex);
      
      rgb_value red() const;
      rgb_value& red();
      rgb_value green() const;
      rgb_value& green();
      rgb_value blue() const;
      rgb_value& blue();

      /**
       * @brief Operator '=='.
       * @author Bruno Oliveira
       * 
       * @param other Color to compare.
       * 
       * @return Whether all RGB values match those of other.
       */
      bool operator==(const Color& other) const;

      /**
       * @brief Operator '!='.
       * @author Bruno Oliveira
       * 
       * @param other Color to compare.
       * 
       * @return Whether any RGB value differs from other's respective.
       */
      bool operator!=(const Color& other) const;

      /**
       * @brief Transforms a color into its corresponding hexidecimal representation.
       * @author Bruno Oliveira & Joana Noites
       * 
       * @return String with hexadecimal value of the color, in the format #XXXXXX.
       */
      std::string to_hex() const;
  };
}
#endif
