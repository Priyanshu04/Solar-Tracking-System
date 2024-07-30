// Include the servo motor library
#include <Servo.h>

// Define the LDR sensor pins
#define LDR1 A0
#define LDR2 A1

// Define the error value. You can change it as you like
#define error 10

// Starting point of the servo motor
int Spoint = 90;

// Create an object for the servo motor
Servo servo;

void setup() {
  // Include servo motor PWM pin (using A4 as a digital pin)
  servo.attach(A4); // Use A4 for the servo signal
  
  // Set the starting point of the servo
  servo.write(Spoint);
  delay(1000);
}

void loop() {
  // Get the LDR sensor value
  int ldr1 = analogRead(LDR1);
  // Get the LDR sensor value
  int ldr2 = analogRead(LDR2);

  // Get the difference of these values
  int value1 = abs(ldr1 - ldr2);
  int value2 = abs(ldr2 - ldr1);

  // Check these values using a IF condition
  if ((value1 > error) || (value2 > error)) {
    if (ldr1 > ldr2 && Spoint > 0) {
      Spoint = Spoint - 1;
    }
    if (ldr1 < ldr2 && Spoint < 180) {
      Spoint = Spoint + 1;
    }
  }

  // Write values to the servo motor
  servo.write(Spoint);
  delay(80);
}
