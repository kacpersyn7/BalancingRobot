#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>
#include <AFMotor.h>
#include "Accelerometer.hpp"
#include "Constants.hpp"

int main(int argc, char const *argv[])
{
    AF_DCMotor motor(3, MOTOR34_64KHZ);
    Accelerometer accelerometer(constants::yMin, constants::yMax);
    Serial.begin(9600);
    Wire.begin();
    motor.setSpeed(40);
    while(1)
    {
        motor.run(FORWARD);
        delay(500);
        motor.run(RELEASE);
        delay(500);
        accelerometer.getDeviationDeg(0.0);
        // compass.read();
        // float deviation = factor_to_deg * compass.a.y;
        // Serial.println(deviation);
        motor.run(BACKWARD);
        delay(500);
    }
    return 0;
}
