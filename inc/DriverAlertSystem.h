#pragma once
#include <iostream>

class DriverAlertSystem {
public:
    void ProvideFeedback() {
        std::cout << "[ALERT] Speed limit reached!" << std::endl;
        // Beep is platform-specific. Use '\a' as basic alert.
        std::cout << "\a"; // Console beep
    }
};
