const int trigPin = 2;
const int echoPin = 3;

float duration, distance;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

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
    Serial.println("Wow you are close!");
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}
