#include <Servo.h>  // Include the official Servo library

Servo myServo;  // Create a servo object to control the motor

void setup() {
  myServo.attach(9);  // Attach the servo signal wire to Digital Pin 9
}

void loop() {
  // Move servo from 0 degrees to 180 degrees
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);  // Tell servo to go to 'angle'
    delay(15);             // Wait 15ms for the motor to physically reach the position
  }

  // Move servo back from 180 degrees to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);  // Tell servo to go to 'angle'
    delay(15);
  }
}