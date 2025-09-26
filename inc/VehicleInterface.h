#pragma once
#include <iostream>

class VehicleInterface {
public:
    void OverrideAcceleration() {
        std::cout << "[ECU] Acceleration overridden to maintain threshold." << std::endl;
    }
};
