#ifndef WATERUTILITY_H
#define WATERUTILITY_H

#include "Utilities.h"
#include "Water.h"
#include <string>

class WaterUtility : public Utilities {
private:
    double storageUnits; // Storage units for water
    Water* water;        // Represents water resource
    int capacity;
    int puritylevels;

public:
    WaterUtility(Structure* s);

    // Handles water-related requests; if not handled, passes it down the chain
    void processRequest(const std::string &request) override;
    void extractWater();
    // Additional water-specific methods
};

#endif
