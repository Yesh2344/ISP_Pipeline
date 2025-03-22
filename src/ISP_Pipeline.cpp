#include "../include/ISP_Pipeline.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

ISP_Pipeline::ISP_Pipeline() : exposure(50), otaUpdateAvailable(false) {
    std::cout << "Initializing ISP Pipeline modules..." << std::endl;
    // Seed the random generator for simulation purposes
    srand(static_cast<unsigned>(time(0)));
}

Image ISP_Pipeline::captureImage() {
    Image img;
    img.width = 640;
    img.height = 480;
    img.pixels.resize(img.width * img.height);
    
    // Simulate sensor reading: pixel brightness influenced by the current exposure
    for (size_t i = 0; i < img.pixels.size(); i++) {
        // For simulation, generate a random pixel value influenced by exposure
        int pixelValue = rand() % (exposure + 1);
        if (pixelValue > 255) pixelValue = 255;
        img.pixels[i] = pixelValue;
    }
    std::cout << "[Capture] Image captured with exposure: " << exposure << std::endl;
    return img;
}

void ISP_Pipeline::autoExposureControl(Image &img) {
    long sum = 0;
    for (int pixel : img.pixels) {
        sum += pixel;
    }
    int avgBrightness = img.pixels.empty() ? 0 : static_cast<int>(sum / img.pixels.size());
    std::cout << "[Auto-Exposure] Average brightness: " << avgBrightness << std::endl;
    
    // Simple control: if brightness is too low, increase exposure; if too high, decrease
    if (avgBrightness < 50) {
        exposure += 5;
        if (exposure > 255) exposure = 255;
        std::cout << "[Auto-Exposure] Increasing exposure to: " << exposure << std::endl;
    } else if (avgBrightness > 200) {
        exposure -= 5;
        if (exposure < 0) exposure = 0;
        std::cout << "[Auto-Exposure] Decreasing exposure to: " << exposure << std::endl;
    } else {
        std::cout << "[Auto-Exposure] Exposure remains unchanged." << std::endl;
    }
}

void ISP_Pipeline::adaptiveDenoise(Image &img) {
    std::cout << "[Denoise] Applying adaptive denoising algorithm." << std::endl;
    // In a real algorithm, you'd apply spatial filtering or a deep learning method.
    // Here, we simply reduce each pixel's value by 5% to simulate noise reduction
    for (size_t i = 0; i < img.pixels.size(); i++) {
        img.pixels[i] = static_cast<int>(img.pixels[i] * 0.95);
    }
}

void ISP_Pipeline::checkAndPerformOTAUpdate() {
    // Randomly decide if an update is available (5% chance)
    if (rand() % 100 < 5) {
        otaUpdateAvailable = true;
    }

    if (otaUpdateAvailable) {
        std::cout << "[OTA Update] Firmware update available. Performing update..." << std::endl;
        // Simulate update delay
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "[OTA Update] Firmware update completed successfully." << std::endl;
        otaUpdateAvailable = false;
    } else {
        std::cout << "[OTA Update] No firmware update available." << std::endl;
    }
}

void ISP_Pipeline::runPipeline() {
    // For demonstration, we run 10 iterations
    for (int iteration = 0; iteration < 10; iteration++) {
        std::cout << "\n--- Pipeline Iteration: " << iteration + 1 << " ---" << std::endl;
        
        // 1. Capture an image
        Image img = captureImage();
        
        // 2. Adjust exposure based on current image brightness
        autoExposureControl(img);
        
        // 3. Apply adaptive denoising
        adaptiveDenoise(img);
        
        std::cout << "[Pipeline] Processing complete for iteration " << iteration + 1 << std::endl;
        
        // 4. Check for OTA firmware updates
        checkAndPerformOTAUpdate();
        
        // 5. Wait for the next frame (simulate ~30 frames per second)
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    std::cout << "Pipeline execution finished after 10 iterations." << std::endl;
}