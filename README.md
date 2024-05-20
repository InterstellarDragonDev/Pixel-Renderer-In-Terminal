# Pixel-Renderer-In-Terminal
A simple renderer that converts PNG images to unicode characters displayed in the terminal

## Slightly important things:
1) You will need the "png.h" library to compile. Just google how to install

## Install and Compile
```
git clone https://github.com/InterstellarDragonDev/Pixel-Renderer-In-Terminal.git
cd Pixel-Renderer-In-Terminal/
mkdir build
make
```
this will compile a executable file
*you might have to give it execute permissions with `chmod +x pixel_engine`*

## How to use
run the executable with the first parameter being the image file
e.g) `./pixel_engine test_image.png`
> [!IMPORTANT]
> Only works with png's no other file format is supported

> [!NOTE]
> You may want to set your terminal font to something low (I tested with it set to 1). there is technically no limit to the size that can be rendered but that doesn't mean all images will render properly if they can't fit into the window without warping



