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
     * @brief implements "invert" command.
     * @details The command "invert" switches every color to its inverse counterpart.
     * @author João Mendes
     * 
     */
    void invert();

    /**
     * @brief Implements to_gray_scale command
     * @details Transforms each individual pixel (r, g, b) to (v, v, v) where v = (r + g + b)/3
     * @author Joana Noites
     */
    void to_gray_scale();

    /**
     * @brief Implements "replace" command.
     * @details The command "replace r1 g1 b1 r2 g2 b2" replaces all
     *          (r1, g1, b1) pixels by (r2, g2, b2).
     * @author Bruno Oliveira
     */
    void replace();

    /**
     * @brief Implements "fill" command.
     * @details The command "fill x y w h r g b" assign the color (r, g, b) to
     *          all pixels contained in the rectangle defined by top-left corner
     *          (x, y), width w, and height h.
     * @author João Mendes
     */
    void fill();

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

    /**
     * @brief Implements "add" command.
     * @details The command "add filename r g b x y" copies all pixels from
     *          the image given in PNG file "filename" (except the ones with
     *          "neutral" color) to the rectangle with top-left corner (x, y)
     *          of the current image.
     * @authors Joana Noites & João Mendes
     */
    void add();

    /**
     * @brief Implements "crop" command.
     * @details The command "crop x y w h" crops the image to the rectangle
     *          defined by top-left corner (x, y), width w and height h.
     * @author Bruno Oliveira
     */
    void crop();

    /**
     * @brief Implements "rotate_left" command.
     * @details The command "rotate_left" rotates the image to the left by
     *          90 degrees.
     * @author Joana Noites
     */
    void rotate_left();

    /**
     * @brief Implements "rotate_right" command.
     * @details The command "rotate_right" rotates the image to the right by
     *          90 degrees.
     * @author Joana Noites
     * 
     */
    void rotate_right();


    /**
     * @brief Implements "median_filter" command.
     * @details The command "median_filter ws" applies a median filter with
     *          window size ws >= 3 to the current image.
     * @author Bruno Oliveira
     */
    void median_filter();

    /**
     * @brief Implements "xpm2_open" command.
     * @details The command "xpm2_open filename" reads an image stored in the
     *          XPM2 file with name filename.
     * @author Bruno Oliveira & João Mendes
     */
    void xpm2_open();

    /**
     * @brief Implements "xpm2_save" command.
     * @details The command "xpm2_save filename" saves an image to a XPM2 file
     *          with name filename.
     * @author Bruno Oliveira & Joana Noites
     */
    void xpm2_save();
  };
}
#endif
