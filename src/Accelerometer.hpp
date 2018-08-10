#pragma once
#include <LSM303.h>
#include "StateVector.hpp"

class Accelerometer
{
public:
    Accelerometer(float yMin, float yMax, int derivativeTime);
    float getDeviationDeg();
    float getDeviationRad();
    void updateState(StateVector &);
private:
    static constexpr float factorToRad {0.0174532925};
    const float degCoefficient{};
    const float radCoefficient{};
    const int derivativeTime{};
    LSM303 compass{};  
};
