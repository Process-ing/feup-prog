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
     * @brief Function object type for lexicographic comparison of Color objects.
     * @note This struct is defined for the sole purpose of using Color
     *       objects as map keys.
     * @author Bruno Oliveira & Joana Noites
     */
    class SortColorLex {
      public:
        /**
         * @brief Compares colors c1 and c2 by lexicographic order, as two
         *        triples (r, g, b).
         * 
         * @param c1 First Color object
         * @param c2 Second Color object
         * @return True if c1 < c2 by lexicographic order, false otherwise
         */
        bool operator()(const Color& c1, const Color& c2) const {
            return (c1.red() < c2.red())
                || (c1.red() == c2.red() && ((c1.green() < c2.green())
                || (c1.green() == c2.green() && c1.blue() < c2.blue())));
        }
    };

    /**
     * @brief Creates a color map Color->char for the given image.
     * 
     * @param image Pointer to image
     * @param start Character to start the color mapping
     * @return Color map
     */
    map<Color, char, SortColorLex> create_color_map(const Image* image, char start = 'a') {
        map<Color, char, SortColorLex> color_map;
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
     * @brief Inverts a color map, from Color->char to char->Color.
     * 
     * @param color_map Color map to invert
     * @return Inverted color map
     */
    map<char, Color> invert_color_map(const map<Color, char, SortColorLex>& color_map) {
        map<char, Color> res;
        for (const pair<const Color, char>& color_char: color_map)
            res.insert({ color_char.second, color_char.first });
        return res;
    }

    void saveToXPM2(const string& file, const Image* image) {
        ofstream file_stream(file);
        file_stream << "! XPM2\n";

        map<Color, char, SortColorLex> color_map = create_color_map(image);
        file_stream << image->width() << ' ' << image->height() << ' '
                    << color_map.size() << " 1\n";

        for (pair<char, Color> char_color: invert_color_map(color_map))
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