#include "XPM2.hpp"

#include <fstream>
#include <map>

using namespace std;

namespace prog {
    /**
     * @brief Converts a hex value to the corresponding color.
     * 
     * @param hex String with hexadecimal value of the color, in the format
     *            #xxxxxx
     * @return The color 
     */
    Color hex_to_color(const string& hex) {
        int red = stoi(hex.substr(1, 2), nullptr, 16),
            green = stoi(hex.substr(3, 2), nullptr, 16),
            blue = stoi(hex.substr(5, 2), nullptr, 16);
        return Color(red, green, blue);
    }

    Image* loadFromXPM2(const string& file) {
        string line;
        ifstream file_stream(file);
        if (!getline(file_stream, line) || line != "! XPM2")
            return nullptr;
        
        int width, height, colors, char_per_color;
        file_stream >> width >> height >> colors >> char_per_color;
        if (char_per_color != 1)
            return nullptr;
        
        Image* new_image = new Image(width, height);
        map<char, Color> color_map;
        for (int i = 0; i < colors; i++) {
            char chr, c;
            string color_hex;
            file_stream >> chr;
            file_stream.ignore(1);
            file_stream >> c >> color_hex;
            if (c != 'c') {
                delete new_image;
                return nullptr;
            }
            color_map.insert({ chr, hex_to_color(color_hex) });
        }

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                char chr;
                file_stream >> chr;
                new_image->at(x, y) = color_map[chr];
            }
        }

        return new_image;
    }

    void saveToXPM2(const string& file, const Image* image) {
        
    }
}