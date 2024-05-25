// Declaring constant variable for the switch pin
const int switchPin = 8;

// Time when the previous time of LED was lit
unsigned long previousTime = 0;

// State of switch
int switchState = 0;

// Previous state of switch
int prevSwitchState = LOW;

// A variable that sets where LED starts
int led = 2;

// 10 minutes in milliseconds, interval to light the next LED
long interval = 600000;

void setup() {
  // Open a serial connection to display values
  Serial.begin(9600);

  // Set the LED pins as outputs
  for (int x = 2; x < 8; x++ ) {
    pinMode(x, OUTPUT);
  }

  // Set the tilt sensor as the input
  pinMode(switchPin, INPUT);
}

void loop() {

  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    if (currentTime == 0) {
      Serial.println("Starting hourglass");
    }
    digitalWrite(led, HIGH);
    led++;
    if(led == 7) {
      // Prints if 60 minutes has passed
      Serial.println("60 minutes has passed, tilt the hourglass to restart");
    }
  }

  // Reads the current switch value
  switchState = digitalRead(switchPin);

  // If the tilt switch was changed/tilted then all the LEDs are turned off again
  if(switchState != prevSwitchState) {
    Serial.println("Tilt detected");
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }
    // Resets the LED lights to the first one
    led = 2;

    // Resets the timer
    previousTime = currentTime;
  }

  // Set the previous switch state to the current state
  prevSwitchState = switchState;

}
