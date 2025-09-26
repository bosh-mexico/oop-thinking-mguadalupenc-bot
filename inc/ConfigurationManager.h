#pragma once
#include <iostream>

class ConfigurationManager {
private:
    int speedThreshold;

public:
    ConfigurationManager(int threshold) : speedThreshold(threshold) {}

    void SetSpeedThreshold(int threshold) {
        if (threshold <= 0) {
            std::cout << "Invalid threshold!" << std::endl;
            return;
        }
        speedThreshold = threshold;
        std::cout << "[CONFIG] Threshold set to " << speedThreshold << " km/h" << std::endl;
    }

    int GetSpeedThreshold() const {
        return speedThreshold;
    }
};
