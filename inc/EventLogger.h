#pragma once
#include <iostream>

class EventLogger {
public:
    void Log(int currentSpeed, int threshold) {
        std::cout << "[LOG] Governor activated at speed " << currentSpeed 
                  << " km/h (Threshold: " << threshold << ")" << std::endl;
    }
};
