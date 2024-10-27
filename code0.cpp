const int ledPins[] = {2, 3, 4, 5, 6, 7};
const int buttonPin = 8;
bool lastButtonState = LOW;
bool buttonState = LOW;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 6; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);
  randomSeed(analogRead(0));
}

void loop() {
  buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH && lastButtonState == LOW) {
    int randomNumber = random(1, 7);
   
    Serial.print("Random number: ");
    Serial.println(randomNumber);

    for (int i = 0; i < 6; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    digitalWrite(ledPins[randomNumber - 1], HIGH);
    delay(500);
  }

  lastButtonState = buttonState;