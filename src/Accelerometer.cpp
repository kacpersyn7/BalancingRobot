#include "Accelerometer.hpp"

Accelerometer::Accelerometer(float yMin, float yMax) : 
        degCoefficient(180.0/(yMax - yMin)), 
        radCoefficient(factorToRad*180.0/(yMax - yMin))
{
    compass.init();
    compass.enableDefault();
}
float Accelerometer::getDeviationDeg(float setPoint)
{
    compass.read();
    return abs(degCoefficient * compass.a.y - setPoint);
}
float Accelerometer::getDeviationRad(float setPoint)
{
    compass.read();
    return abs(radCoefficient * compass.a.y - setPoint);
}