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

const int WIDTH = 200;
const int HEIGHT = 200;

const Color NULL_COLOR = {-1, -1, -1};

std::unordered_map<char, Color> colour_map = {
    {'R', {255, 0, 0}},      // Bright red
    {'G', {0, 255, 0}},      // Bright green
    {'B', {0, 0, 255}},      // Bright blue
    {'Y', {255, 255, 0}},    // Yellow
    {'M', {255, 0, 255}},    // Magenta
    {'C', {0, 255, 255}},    // Cyan
    {'g', {100, 100, 100}},      // Grey
};

Color pixel_matrix[WIDTH][HEIGHT];


//* ----------------------------------------------------------------------------------------------------------------------------- Functions start here

Color random_color(){
   return {(rand() % 255) + 1, (rand() % 255) + 1, (rand() % 255) + 1} ;
}

// Function to compare two Color structs
bool operator==(const Color& c1, const Color& c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
}

void initialize() {
    // this sets a new seed for the random number generation
    srand((unsigned) time(0));

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

// prints out the test to make sure pixel rendering is working
void test_pixels() {
    std::cout << "rendering test: ";
    for(auto i:colour_map) {
        std::cout << i.first << " : ";
        print_single_pixel(i.second);
        std::cout << " ";
    }
    std::cout << "\n";
}



#endif