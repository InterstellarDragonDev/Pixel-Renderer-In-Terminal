#include <iostream>
#include "Render-Engine.h" 
#include "Image-Converter.h"

//* compile command: g++ -o build/pixel_engine main.cpp Render-Engine.h Image-Converter.h -lm -lpthread -lX11 -lpng -Wall -Wextra

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_file>" << "\n";
        return 1;
    }
    const char* image_name = argv[1];

    initialize();

    get_image_data(image_name);

    render();
    //std::vector<std::vector<png_byte>> pixel_data = read_png_file(image_name, width, height);

    // Process the pixel data
    // for (int y = 0; y < height; y++) {
    //     png_bytep row = pixel_data[y].data();
    //     for (int x = 0; x < width; x++) {
    //         png_bytep px = &(row[x * 4]);
    //         // px[0] = red, px[1] = green, px[2] = blue, px[3] = alpha
    //         std::cout << "Pixel at (" << x << ", " << y << "): R=" << (int)px[0] << " G=" << (int)px[1] << " B=" << (int)px[2] << " A=" << (int)px[3] << std::endl;
    //     }
    // }
    
    return 0;
}