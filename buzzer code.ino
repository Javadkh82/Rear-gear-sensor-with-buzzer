/*
     Ultrasonic Sensor HC-SR05/4 and Arduino
      by Hanie Kiani
   https://electropeak.com/learn
*/
long duration;
int distance;

const int trig = 9;
const int echo = 10;
int buzzer = 3;


void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = calculateDistance();

  if (distance < 10) {
    digitalWrite(buzzer, HIGH);
  }
  else if (distance > 30) {
    digitalWrite(buzzer, LOW);
  }
  else {
    int range = map(distance, 10, 30, 255, 0);
    analogWrite(buzzer, range);
  }

    Serial.print ("distance : ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  int calculateDistance() {
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = (duration * 0.034 / 2);
    return distance;
  }
