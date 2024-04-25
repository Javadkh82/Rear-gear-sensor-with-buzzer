#define BUZZER_PIN 3
#define BTN_PIN 7


void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
}
void loop() {
  if(digitalRead(BTN_PIN))
    {
      analogWrite(BUZZER_PIN, 0);
    }
    else
    {
      analogWrite(BUZZER_PIN, 127);
    }
}
