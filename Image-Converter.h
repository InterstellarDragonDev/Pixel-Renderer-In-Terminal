#ifndef IMAGE_CONVERTER_H
#define IMAGE_CONVERTER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <png.h>
#include "Render-Engine.h"

using namespace std;

// function declaration
std::vector<std::vector<png_byte>> read_png_file(const char* filename, int& width, int& height);

void get_image_data(const char* image_name) {
    int width, height;
    std::vector<std::vector<png_byte>> pixel_data = read_png_file(image_name, width, height);

    for (int y = 0; y < height; y++) {
        png_bytep row = pixel_data[y].data();
        for (int x = 0; x < width; x++) {

            // this checks if we have gone past the limits of the canvas
            if (x > WIDTH || y > HEIGHT) {
            break;
            }

            png_bytep px = &(row[x * 4]);
            // px[0] = red, px[1] = green, px[2] = blue, px[3] = alpha
            if ((int)px[3] == 0) {
               continue;  
            }
            Color pixel_colour = {(int)px[0], (int)px[1], (int)px[2]};
            pixel_matrix[y][x] = pixel_colour;
        }
    }
}


// Function to read PNG file and get pixel data
std::vector<std::vector<png_byte>> read_png_file(const char* filename, int& width, int& height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        throw std::runtime_error("Error: Could not open file.");
    }

    // Create and initialize the png_struct with the default error handling.
    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        fclose(fp);
        throw std::runtime_error("Error: png_create_read_struct failed.");
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        png_destroy_read_struct(&png, NULL, NULL);
        fclose(fp);
        throw std::runtime_error("Error: png_create_info_struct failed.");
    }

    if (setjmp(png_jmpbuf(png))) {
        png_destroy_read_struct(&png, &info, NULL);
        fclose(fp);
        throw std::runtime_error("Error: setjmp(png_jmpbuf(png)) failed.");
    }

    png_init_io(png, fp);
    png_read_info(png, info);

    width = png_get_image_width(png, info);
    height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);

    // Read any color_type into 8bit depth, RGBA format.
    if (bit_depth == 16)
        png_set_strip_16(png);

    if (color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(png);

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    if (png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);

    if (color_type == PNG_COLOR_TYPE_RGB ||
        color_type == PNG_COLOR_TYPE_GRAY ||
        color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

    if (color_type == PNG_COLOR_TYPE_GRAY ||
        color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    std::vector<std::vector<png_byte>> pixel_data(height, std::vector<png_byte>(png_get_rowbytes(png, info)));
    std::vector<png_bytep> row_pointers(height);

    for (int y = 0; y < height; y++) {
        row_pointers[y] = pixel_data[y].data();
    }

    png_read_image(png, row_pointers.data());

    fclose(fp);
    png_destroy_read_struct(&png, &info, NULL);

    return pixel_data;
}





#endif