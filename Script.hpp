#ifndef __prog_Script_hpp__
#define __prog_Script_hpp__

#include <string>
#include <fstream>
#include "Image.hpp"

namespace prog
{
  class Script
  {
  public: 
    Script(const std::string &filename);
    ~Script();
    void run();
  private:
    // Current image.
    Image *image;
    // Input stream for reading script commands.
    std::ifstream input;
  private:
    // Private functions
    void clear_image_if_any();
    void open();
    void blank();
    void save();
    /**
     * @brief Implements to_gray_scale command
     * @details Transforms each individual pixel (r, g, b) to (v, v, v) where v = (r + g + b)/3
     * @author Joana Noites
     * 
     */
    void to_gray_scale();
  };
}
#endif
