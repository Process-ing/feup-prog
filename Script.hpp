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
     * @brief Implement "replace" command.
     * @details The command "replace r1 g1 b1 r2 g2 b2" replaces all
     *          (r1, g1, b1) pixels by (r2, g2, b2).
     */
    void replace();

    /**
     * @brief Implements "h_mirror" command.
     * @details The command "h_mirror" mirrors the image horizontally.
     * @author Bruno Oliveira
     */
    void h_mirror();

    /**
     * @brief Implements "v_mirror" command.
     * @details The command "v_mirror" mirrors the image vertically.
     * @author Bruno Oliveira
     */
    void v_mirror();
  };
}
#endif
