// The time when the sensor outputs a low impulse
long unsigned int lowIn;

// The amount of milliseconds the sensor has to be low before assuming motion has stopped
long unsigned int timePause = 2000;

// Checking if sensor is in its low state 
bool lowLock = true;
bool lowTime;

// Pin number for LEDs
int led1 = 2;
int led2 = 3;
int led3 = 4;

// Pin number for PIR sensor
int pirPin = 8;

void setup() {
  // Open a serial connection to display values
  Serial.begin(9600);

  // Set the LED pins as outputs
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }

  // Set the PIR sensor as the input
  pinMode(pirPin, INPUT);
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    // LED is turned on if motion is detected
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    if (lowLock) {
      // Makes sure we wait for a transition to LOW before any further output is made 
      lowLock = false;
      Serial.println("----");
      Serial.print("Motion is detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec.");
      delay(50);
    }
    lowTime = true;
  }

  if (digitalRead(pirPin) == LOW) {
    // LED is turned off after no motion is detected
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

    if (lowTime) {
      lowIn = millis();  // Save the time of the transition from high to LOW
      lowTime = false;  // Make sure this is only done at the start of a LOW phase
    }

    // If the sensor is low for more than the given pause, assuming that no more motion is going to happen

    if (!lowLock && millis() - lowIn > timePause) {
      // Only executed again after a new motion sequence has been detected
      lowLock = true;
      Serial.print("Motion is ended at ");
      Serial.print((millis() - timePause) / 1000);
      Serial.println(" sec.");
      delay(50);
    }
  }
}
