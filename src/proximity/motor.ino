#include <Servo.h>

const int servoPin = 7;
const int trigPin = 2;
const int echoPin = 3;

float duration, distance;
int pos = 0;

Servo myServo;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);

}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  if (distance < 20) {

  for (pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);
  }

  for (pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos); 
    delay(15);
  }

  }
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
