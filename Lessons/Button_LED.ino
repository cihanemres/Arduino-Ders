// Hafta 2: Buton Kontrollü LED / Week 2: Button-Controlled LED
// TR: INPUT_PULLUP kullandığımız için buton serbestken HIGH, basılınca LOW okur.
// EN: With INPUT_PULLUP, the button reads HIGH when released and LOW when pressed.

const int ledPin = 13;   // LED pin
const int buttonPin = 2; // Button pin

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up
}

void loop() {
  int buttonState = digitalRead(buttonPin); // HIGH: released, LOW: pressed
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH); // LED ON
  } else {
    digitalWrite(ledPin, LOW);  // LED OFF
  }
}
