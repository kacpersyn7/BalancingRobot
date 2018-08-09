#pragma once
#include <LSM303.h>

class Accelerometer
{
public:
    Accelerometer(float yMin, float yMax);
    float getDeviationDeg(float setPoint);
    float getDeviationRad(float setPoint);
private:
    static constexpr float factorToRad {0.0174532925};
    const float degCoefficient{};
    const float radCoefficient{};
    LSM303 compass{};  
};
