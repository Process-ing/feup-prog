#include "XPM2.hpp"

#include <fstream>
#include <map>

using namespace std;

namespace prog {
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
            color_map.insert({ chr, Color(color_hex) });
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

    /**
     * @brief Creates a color map for the given image.
     * 
     * @param image Pointer to image
     * @param start Character to start the color mapping
     * @return Color map
     */
    map<Color, char> create_color_map(const Image* image, char start = 'a') {
        map<Color, char> color_map;
        char curr_char = start;
        
        for (int x = 0; x < image->width(); x++) {
            for (int y = 0; y < image->height(); y++) {
                Color color = image->at(x, y);
                if (color_map.find(color) == color_map.end()) {
                    color_map.insert({ color, curr_char });
                    curr_char++;
                }
            }
        }

        return color_map;
    }

    /**
     * @brief Inverts the keys and values of a map
     * 
     * @param amap Map to invert
     * @return Inverted map
     */
    template <typename T, typename U>
    map<U, T> invert(const map<T, U>& amap) {
        map<U, T> res;
        for (const pair<const T, U>& apair: amap)
            res.insert({ apair.second, apair.first });
        return res;
    }

    void saveToXPM2(const string& file, const Image* image) {
        ofstream file_stream(file);
        file_stream << "! XPM2\n";

        map<Color, char> color_map = create_color_map(image);
        file_stream << image->width() << ' ' << image->height() << ' '
                    << color_map.size() << " 1\n";

        for (pair<char, Color> char_color: invert(color_map))
            file_stream << char_color.first << " c "
                        << char_color.second.to_hex() << endl;
        
        for (int y = 0; y < image->height(); y++) {
            for (int x = 0; x < image->width(); x++) {
                file_stream << color_map[image->at(x, y)];
            }
            file_stream << endl;
        }
    }
}