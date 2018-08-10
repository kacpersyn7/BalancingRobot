#include "Accelerometer.hpp"

Accelerometer::Accelerometer(float yMin, float yMax, int derivativeTime) : 
        degCoefficient(180.0/(yMax - yMin)), 
        radCoefficient(factorToRad*180.0/(yMax - yMin)),
        derivativeTime(derivativeTime)
{
    compass.init();
    compass.enableDefault();
}
float Accelerometer::getDeviationDeg()
{
    compass.read();
    return degCoefficient * compass.a.y;
}
float Accelerometer::getDeviationRad()
{
    compass.read();
    return radCoefficient * compass.a.y;
}
void Accelerometer::updateState(StateVector & state)
{
    float previousAngle = getDeviationRad();
    delay(derivativeTime);
    state.angle = getDeviationRad();
    state.angleDerivative = (previousAngle - state.angle)/derivativeTime;
}