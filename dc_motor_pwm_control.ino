int startBtn = 2;
int stopBtn = 3;
int motorPin = 9;
int potPin = A0;
int ledPin = 13;

bool motorOn = false;

void setup() {
  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(startBtn) == LOW) {
    motorOn = true;
  }

  if (digitalRead(stopBtn) == LOW) {
    motorOn = false;
  }

  if (motorOn) {
    int speed = analogRead(potPin);
    int pwm = map(speed, 0, 1023, 0, 255);
    analogWrite(motorPin, pwm);
    digitalWrite(ledPin, HIGH);
  } else {
    analogWrite(motorPin, 0);
    digitalWrite(ledPin, LOW);
  }
}
