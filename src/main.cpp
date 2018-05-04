#include <Arduino.h>
#include <Servo.h>
#include <LSM303.h>
#include <Wire.h>
#define Y_MIN -16238.0
#define Y_MAX 15900.0
constexpr float factor_to_deg = 180.0/(Y_MAX - Y_MIN);
constexpr float factor_to_rad = factor_to_deg * 0.0174532925;
LSM303 compass;
void setup() {
    Serial.begin(9600);
    Wire.begin();
    compass.init();
    compass.enableDefault();
}

void loop() {
    delay(1000);
    compass.read();
    float deviation = factor_to_deg * compass.a.y;
    Serial.println(deviation);
    delay(1000);
}