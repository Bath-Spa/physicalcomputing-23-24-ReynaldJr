// Pin numbers for ultrasonic sensor
const int echo = 9;
const int trig = 8;

// Storing duration of echo and distance
int duration = 0;
int distance = 0;

// Pin numbers for each LED
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

  // Setting trig as output and echo as input
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  // Sending a trigger to the ultrasonic sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  // Measure duration of echo
  duration = pulseIn(echo, HIGH);

  // Measure distance based of the echo
  distance = (duration/2) / 28.5;

  // Print calculated distance
  Serial.println(distance);

  // Lights up if distance is equal to or less than 8 cm
  if ( distance <= 8 )
  {
    digitalWrite(led6, HIGH);
  }
  else
  {
    digitalWrite(led6, LOW);
  }

  // Lights up if distance is equal to or less than 14 cm
  if ( distance <= 14 )
  {
    digitalWrite(led5, HIGH);
  }
  else
  {
    digitalWrite(led5, LOW);
  }

  // Lights up if distance is equal to or less than 22 cm
  if ( distance <= 22 )
  {
    digitalWrite(led4, HIGH);
  }
  else
  {
    digitalWrite(led4, LOW);
  }

  // Lights up if distance is equal to or less than 28 cm
  if ( distance <= 28 )
  {
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW);
  }

  // Lights up if distance is equal to or less than 34 cm
  if ( distance <= 34 )
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }

  // Lights up if distance is equal to or less than 42 cm
  if ( distance <= 42 )
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }

  // Delay
  delay(10);

}
