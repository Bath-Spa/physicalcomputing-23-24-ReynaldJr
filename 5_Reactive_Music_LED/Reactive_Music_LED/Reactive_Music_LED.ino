// Declaring constant variable for the sound sensor
const int soundPin = A0;

// Pin numbers for LED
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;

void setup() {
  // Open a serial connection to display values
  Serial.begin(9600);

  // Set the LED pins as outputs
  for (int x = 2; x < 8; x++ ) {
    pinMode(x, OUTPUT);
  }

  // Set the sound sensor as the input
  pinMode(soundPin, INPUT);
}

void loop() {
  long sum = 0;

  // Take 100 samples of sound from the sound sensor
  for(int i=0; i < 100; i++)
  {
    sum += analogRead(soundPin);
  }

  // Take average of the 100 samples
  sum = sum/100;

  // Light up LED using the sound level
  if (sum >= 300) {
    digitalWrite(led1, HIGH);
  } 
  
  else {
    digitalWrite(led1, LOW);
  }

  if (sum >= 350) {
    digitalWrite(led2, HIGH);
  }

  else {
    digitalWrite(led2, LOW);
  }

  if (sum >= 400) {
    digitalWrite(led3, HIGH);
  } 
  
  else { 
    digitalWrite(led3, LOW);
  }
  
  if (sum >= 450) { 
    digitalWrite(led4, HIGH);
  } 
  
  else { 
    digitalWrite(led4, LOW);
  }
  
  if (sum >= 500) {
    digitalWrite(led5, HIGH);
  } 
  
  else { 
    digitalWrite(led5, LOW);
  }
  
  if (sum >= 550) { 
    digitalWrite(led6, HIGH); 
  }
  
  else {
    digitalWrite(led6, LOW);
  }

  delay(10); 
}
