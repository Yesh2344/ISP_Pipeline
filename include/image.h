#ifndef IMAGE_H
#define IMAGE_H

#include <vector>

// Simulated image structure with basic grayscale pixel data
struct Image {
    int width;
    int height;
    std::vector<int> pixels; // Pixel values range from 0 to 255
};

#endif // IMAGE_H