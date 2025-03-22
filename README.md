# Image Processing Pipeline (ISP)

A simplified simulation of an Image Signal Processing pipeline that demonstrates key concepts in image capture and processing.

## Overview

This project implements a basic ISP pipeline that simulates:
- Image capture with configurable exposure
- Auto-exposure control based on image brightness
- Adaptive denoising for noise reduction
- Over-the-Air (OTA) firmware update checks

The code demonstrates a modular approach to image processing, using a simplified grayscale image model. It's designed for educational purposes to illustrate the core components of an ISP system.

## Project Structure

```
├── include/
│   ├── Image.h              # Image data structure definition
│   └── ISP_Pipeline.h       # ISP pipeline class declaration
├── src/
│   ├── ISP_Pipeline.cpp     # Implementation of ISP pipeline modules
│   └── main.cpp             # Entry point for running the pipeline
```

## Classes and Modules

### Image Structure

The `Image` structure provides a simple representation of a grayscale image:
- `width` and `height` define the image dimensions
- `pixels` is a vector of integer values (0-255) representing pixel brightness

