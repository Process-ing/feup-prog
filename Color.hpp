#ifndef __prog_Color_hpp__
#define __prog_Color_hpp__

namespace prog
{
  typedef unsigned char rgb_value;
  /**
   * @brief color representation as 3 integer values (red, green and blue)
   * @author joana_noites
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
       * @brief Construct a new Color object
       * 
       */
      Color();

      /**
       * @brief Construct a new Color object
       * 
       * @param c 
       */
      Color(const Color& c);

      /**
       * @brief Construct a new Color object
       * 
       * @param r 
       * @param g 
       * @param b 
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
