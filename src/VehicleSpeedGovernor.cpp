#include "ConfigurationManager.h"
#include "VehicleInterface.h"
#include "DriverAlertSystem.h"
#include "EventLogger.h"
#include "VehicleSpeedGovernor.h"

int main() {
    ConfigurationManager config(100); // 100 km/h default
    VehicleInterface ecu;
    DriverAlertSystem alert;
    EventLogger logger;

    VehicleSpeedGovernor governor(config, ecu, alert, logger);

    config.SetSpeedThreshold(90);  // Set new threshold
    governor.UpdateVehicleSpeed(85);  // Below threshold
    governor.ShowStatus();

    governor.UpdateVehicleSpeed(95);  // Exceeds threshold
    governor.ShowStatus();

    return 0;
}
