//LED blink
//Code (in development) to implement an obstacle-avoidance algorithm for a battery powered car.

void setup()
{
  pinMode(9, OUTPUT);
}

void loop()           
{   

    digitalWrite(9, HIGH);    // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(9, LOW);     // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second

}

LED gradual increase in brightness

int ledPin = 9;                     // Define the LED pin at D9
int value;
void setup () {
    pinMode (ledPin, OUTPUT);       // initialize ledpin as an output.
}
void loop () {

    for (value = 0; value <255; value = value + 1) {
    analogWrite (ledPin, value);    // LED lights gradually light up
    delay (1);                      // delay 5MS
    }

    for (value = 255; value> 0; value = value-1) {
    analogWrite (ledPin, value);    // LED gradually goes out
    delay (1);                      // delay 5MS
    }
}

PWM simulating breathing effect

int ledPin = 9;                     // Define the LED pin at D9
int value;
void setup () {
    pinMode (ledPin, OUTPUT);       // initialize ledpin as an output.
}
void loop () {
    for (value = 0; value <255; value = value + 1) {
    analogWrite (ledPin, value);    // LED lights gradually light up
    delay (30);                      // delay 5MS
    }
    for (value = 255; value> 0; value = value-1) {
    analogWrite (ledPin, value);    // LED gradually goes out
    delay (30);                      // delay 5MS
    }
}

// Servo control (rotation)
#define servoPin 9 //servo PIN number

int pos; //the angle variable of the servo motor
int pulsewidth; //pulse width variable of servo

void setup() {
  pinMode(servoPin, OUTPUT); //set the pins of servo to output
  procedure(60); //set the angle of servo to 0 degree
}

void loop() {

  for (pos = 1; pos <= 180; pos +=1) {

    //goes from 0 degrees to 180 degrees
    procedure(pos);
    delay(5);

  }

  for (pos = 180; pos >= 1; pos -=1) {

    //goes from 180 degrees to 0 degrees
    procedure(pos);
    delay(5);
  }
}

//function to control servo
void procedure(int myangle) {

  pulsewidth = myangle * 11 + 500; //calculate the value of pulse width

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulsewidth);
  digitalWrite(servoPin, LOW);

  delay((20 - pulsewidth / 1000)); // the cycle is 20 ms

}

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position
void setup() {
    myservo.attach(9);                   // attaches the servo on pin 9 to the servo object
}
void loop() {
    for (pos = 1; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);                   // tell servo to go to position in variable 'pos'
    delay(10);                            // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 1; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);                   // tell servo to go to position in variable 'pos'
    delay(10);                            // waits 15ms for the servo to reach the position
    }
}

//Obstacle avoidance
int trigPin = 5; // Trigger
int echoPin = 4; // Echo
long duration, cm, inches;

void setup() 
{
    //Serial Port begin
    Serial.begin (9600);
    //Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() 

{
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(15);
    digitalWrite(trigPin, LOW);

    // Read the signal from the sensor: a HIGH pulse whose duration is the time (in microseconds) 
    //from the sending of the ping to the reception of its echo off of an object.
    duration = pulseIn(echoPin, HIGH);

    // Convert the time into a distanc
    cm = (duration/2) / 29.1; // Divide by 29.1 or multiply by 0.0343
    inches = (duration/2) / 74; // Divide by 74 or multiply by 0.0135

    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(10);

}


