#pragma once
#include <iostream>
#include "ConfigurationManager.h"
#include "VehicleInterface.h"
#include "DriverAlertSystem.h"
#include "EventLogger.h"

class VehicleSpeedGovernor {
private:
    int currentSpeed;
    bool isGovernorActive;

    ConfigurationManager& configManager;
    VehicleInterface& vehicleInterface;
    DriverAlertSystem& alertSystem;
    EventLogger& logger;

public:
    VehicleSpeedGovernor(ConfigurationManager& config, 
                         VehicleInterface& vehicle,
                         DriverAlertSystem& alert,
                         EventLogger& log)
        : currentSpeed(0), isGovernorActive(false),
          configManager(config), vehicleInterface(vehicle),
          alertSystem(alert), logger(log) {}

    void UpdateVehicleSpeed(int newSpeed) {
        currentSpeed = newSpeed;
        std::cout << "[DATA] Vehicle speed updated: " << currentSpeed << " km/h" << std::endl;
        CheckAndEnforceSpeedLimit();
    }

    void CheckAndEnforceSpeedLimit() {
        int threshold = configManager.GetSpeedThreshold();

        if (currentSpeed > threshold) {
            isGovernorActive = true;
            vehicleInterface.OverrideAcceleration();
            alertSystem.ProvideFeedback();
            logger.Log(currentSpeed, threshold);
        } else {
            isGovernorActive = false;
        }
    }

    void ShowStatus() const {
        std::cout << "[STATUS] Current Speed: " << currentSpeed 
                  << ", Threshold: " << configManager.GetSpeedThreshold() 
                  << ", Governor Active: " << (isGovernorActive ? "Yes" : "No") 
                  << std::endl;
    }
};
