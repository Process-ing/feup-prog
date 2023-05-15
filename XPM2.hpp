#ifndef __prog_XPM2_hpp__
#define __prog_XPM2_hpp__

#include <string>
#include "Image.hpp"

namespace prog {
    /**
     * @brief Reads an image stored in the XPM2 file format.
     * @author Bruno Oliveira & João Mendes
     * 
     * @param file Name of the file
     * @return Pointer to respective dinamically allocated Image
     */
    Image* loadFromXPM2(const std::string &file);

    /**
     * @brief Saves an image in a XPM2 file.
     * @author Bruno Oliveira & Joana Noites
     * 
     * @param file Name of the file
     * @param img Pointer to image
     */
    void saveToXPM2(const std::string& file, const Image* img);
}
#endif
