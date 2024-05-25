// Holds the state of the button
int buttonState = 0;

void setup() {
  // Open a serial connection to display values
  Serial.begin(9600);

  // Set the LED pins as outputs
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Setting the button as input
  pinMode(2, INPUT);  
}

void loop() {
  // Read value of button
  buttonState = digitalRead(2);

  // If button is not pressed, then the green LED is turned on while the other red LEDs are not
  if (buttonState == LOW) {
    Serial.println("Engaging Hyperdrive");
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }

  // Else if button is pressed, then both of the red LEDs are turned on while the green LED is turned off
  else {
    Serial.println("Firing Lasers");
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);

  }

}
