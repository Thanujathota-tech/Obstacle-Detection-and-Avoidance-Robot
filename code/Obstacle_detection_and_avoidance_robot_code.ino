#include <Adafruit_MotorShield.h>

#include <AFMotor.h>  // Adafruit Motor Shield Library

// Initialize Motors
AF_DCMotor M1(1);
AF_DCMotor M2(2);
AF_DCMotor M3(3);
AF_DCMotor M4(4);

#define Speed 180  // Motor Speed (0-255)
char value;  // Variable to store received Bluetooth data

void setup() {
  Serial.begin(9600);  // Start serial communication
  Serial.println("Bluetooth Control Test Started...");

  // Set initial motor speed
  M1.setSpeed(Speed);
  M2.setSpeed(Speed);
  M3.setSpeed(Speed);
  M4.setSpeed(Speed);
}

// Function to Move Forward
void moveForward() {
  Serial.println("Bluetooth Command: 'F' (Moving Forward)");
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  delay(2000);
  stopMotors();
}

// Function to Move Backward
void moveBackward() {
  Serial.println("Bluetooth Command: 'B' (Moving Backward)");
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
  delay(2000);
  stopMotors();
}

// Function to Turn Left
void turnLeft() {
  Serial.println("Bluetooth Command: 'L' (Turning Left)");
  M1.run(FORWARD);
  M2.run(FORWARD);
  M3.run(BACKWARD);
  M4.run(BACKWARD);
  delay(2000);
  stopMotors();
}

// Function to Turn Right
void turnRight() {
  Serial.println("Bluetooth Command: 'R' (Turning Right)");
  M1.run(BACKWARD);
  M2.run(BACKWARD);
  M3.run(FORWARD);
  M4.run(FORWARD);
  delay(2000);
  stopMotors();
}

// Function to Stop Motors
void stopMotors() {
  Serial.println("Bluetooth Command: 'S' (Stop)");
  M1.run(RELEASE);
  M2.run(RELEASE);
  M3.run(RELEASE);
  M4.run(RELEASE);
  delay(1000);
}

void loop() {
  if (Serial.available() > 0) {  // Check if Bluetooth data is available
    value = Serial.read();  // Read the received Bluetooth command

    if (value == 'F') moveForward();
    else if (value == 'B') moveBackward();
    else if (value == 'L') turnLeft();
    else if (value == 'R') turnRight();
    else if (value == 'S') stopMotors();
  }
}
