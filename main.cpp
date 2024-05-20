#include "Render-Engine.h" 
#include "Image-Converter.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_file>" << "\n";
        return 1;
    }
    const char* image_name = argv[1];

    get_image_data(image_name);

    render();
    
    return 0;
}