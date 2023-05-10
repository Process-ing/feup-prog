#include <iostream>
#include <fstream>
#include "Script.hpp"
#include "PNG.hpp"
#include "XPM2.hpp"

using namespace std;

namespace prog {
    // Use to read color values from a script file.
    istream& operator>>(istream& input, Color& c) {
        int r, g, b;
        input >> r >> g >> b;
        c.red() = r;
        c.green() = g;
        c.blue() = b;
        return input;
    }

    Script::Script(const string& filename) :
            image(nullptr), input(filename) {

    }
    void Script::clear_image_if_any() {
        if (image != nullptr) {
            delete image;
            image = nullptr;
        }
    }
    Script::~Script() {
        clear_image_if_any();
    }

    void Script::run() {
        string command;
        while (input >> command) {
            cout << "Executing command '" << command << "' ..." << endl;
            if (command == "open") {
                open();
                continue;
            }
            if (command == "blank") {
                blank();
                continue;
            }
            // Other commands require an image to be previously loaded.
            if (command == "save") {
                save();
                continue;
            } 
            if (command == "to_gray_scale") {
                to_gray_scale();
                continue;
            }
            if (command == "replace") {
                replace();
                continue;
            }
            if (command == "h_mirror") {
                h_mirror();
                continue;
            }
            if (command == "v_mirror") {
                v_mirror();
                continue;
            }
            if (command == "crop") {
                crop();
                continue;
            }
            if (command == "rotate_left") {
                rotate_left();
                continue;
            }
            if (command == "rotate_right") {
                rotate_right();
                continue;
            }
        }
    }

    void Script::open() {
        // Replace current image (if any) with image read from PNG file.
        clear_image_if_any();
        string filename;
        input >> filename;
        image = loadFromPNG(filename);
    }

    void Script::blank() {
        // Replace current image (if any) with blank image.
        clear_image_if_any();
        int w, h;
        Color fill;
        input >> w >> h >> fill;
        image = new Image(w, h, fill);
    }

    void Script::save() {
        // Save current image to PNG file.
        string filename;
        input >> filename;
        saveToPNG(filename, image);
    }

    void Script::to_gray_scale() {
        int r, g, b;
        int v;

        for (int x = 0; x < image->width(); x++) {
            for (int y = 0; y < image->height(); y++) {
                r = image->at(x, y).red();
                g = image->at(x, y).green();
                b = image->at(x, y).blue();
                
                v = (r + g + b) / 3;
                image->at(x, y) = Color(v, v, v);
            }
        }
    }
     
    void Script::replace() {
        int r1, g1, b1, r2, g2, b2;
        input >> r1 >> g1 >> b1 >> r2 >> g2 >> b2;
        Color c1(r1, g1, b1), c2(r2, g2, b2);

        for (int x = 0; x < image->width(); x++) {
            for (int y = 0; y < image->height(); y++) {
                if (image->at(x, y) == c1)
                    image->at(x, y) = c2;
            }
        }
    }

    void Script::h_mirror() {
        for (int x = 0; x < image->width() / 2; x++) {
            for (int y = 0; y < image->height(); y++) {
                Color temp = image->at(x, y);
                image->at(x, y) = image->at(image->width() - 1 - x, y);
                image->at(image->width() - 1 - x, y) = temp;
            }
        }
    }

    void Script::v_mirror() {
        for (int x = 0; x < image->width(); x++) {
            for (int y = 0; y < image->height() / 2; y++) {
                Color temp = image->at(x, y);
                image->at(x, y) = image->at(x, image->height()- 1 - y);
                image->at(x, image->height() - 1 - y) = temp;
            }
        }
    }

    void Script::crop() {
        int x, y, w, h;
        input >> x >> y >> w >> h;
        Image* new_image = new Image(w, h);

        for (int nx = 0; nx < w; nx++) {
            for (int ny = 0; ny < h; ny++)
                new_image->at(nx, ny) = image->at(x + nx, y + ny);
        }

        clear_image_if_any();
        image = new_image;
    }
    
    void Script::rotate_left(){
        int w, h;
        w = image->width();
        h = image->height();
        Image* new_image = new Image(h, w);

        for (int x = 0; x < w; x++){
            for (int y = 0; y < h; y++){
                new_image->at(y, w - 1 - x) = image->at(x, y);
            }
        }

        clear_image_if_any();
        image = new_image;
    }

    void Script::rotate_right() {
        int w, h;
        w = image->width();
        h = image->height();
        Image* new_image = new Image(h, w);

        for (int x = 0; x < w; x++){
            for (int y = 0; y < h; y++){
                new_image->at(h - 1 - y, x) = image->at(x, y);
            }
        }

        clear_image_if_any();
        image = new_image;
    }
}
