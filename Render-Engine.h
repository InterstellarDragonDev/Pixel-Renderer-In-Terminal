#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H



#include <unordered_map>
#include <iostream>
#include <unistd.h> 
#include <utility>
#include <cstdlib>
#include <vector>
#include <string>


struct Color {
    int r, g, b;
};

int WIDTH = 0;
int HEIGHT = 0;

const Color NULL_COLOR = {-1, -1, -1};

std::vector<std::vector<Color>> pixel_matrix;


//* ----------------------------------------------------------------------------------------------------------------------------- Functions start here

// a little function that randomly generates a colour (used for testing purposes)
Color random_color(){
   return {(rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1} ;
}

// this resizes the pixel matrix when loading the image
void resize_pixel_matrix(int num_rows, int num_cols) {
    pixel_matrix.resize(num_rows);

    for (auto& row : pixel_matrix) {
        row.resize(num_cols);
    }
}

// Function to compare two Color structs
bool operator==(const Color& c1, const Color& c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

void initialize() {

    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            pixel_matrix[y][x] = NULL_COLOR; 
        }
    }   
}

void print_single_pixel(Color CLin) {
    // ANSI escape code for setting text color with RGB values   
    std::cout << "\033[38;2;" << CLin.r << ";" << CLin.g << ";" << CLin.b << "m" << "██" << "\033[0m";
}

void render() {
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            if (pixel_matrix[y][x] == NULL_COLOR) {
                std::cout << "  ";
                continue;
            }
            print_single_pixel(pixel_matrix[y][x]); 
        }
        std::cout << "\n";
    }
}


#endif