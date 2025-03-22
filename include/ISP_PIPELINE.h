#ifndef ISP_PIPELINE_H
#define ISP_PIPELINE_H

#include "Image.h"

// ISP Pipeline class encapsulating the main modules
class ISP_Pipeline {
private:
    int exposure;         // Simulated exposure setting
    bool otaUpdateAvailable;

public:
    ISP_Pipeline();
    
    // Simulate capturing an image from a CMOS sensor
    Image captureImage();
    
    // Auto-exposure control that adjusts exposure based on average brightness
    void autoExposureControl(Image &img);
    
    // Adaptive denoising that smooths pixel values
    void adaptiveDenoise(Image &img);
    
    // Simulated OTA update check and performance
    void checkAndPerformOTAUpdate();
    
    // Main loop running the ISP pipeline continuously
    void runPipeline();
};

#endif // ISP_PIPELINE_H