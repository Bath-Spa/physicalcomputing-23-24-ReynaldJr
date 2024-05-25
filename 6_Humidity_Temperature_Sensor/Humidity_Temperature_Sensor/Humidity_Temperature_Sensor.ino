#include <DHT11.h>

// Connecting temperature & humidity sensor to Digital I/O Pin 7
DHT11 dht11(7); 

void setup() {
  // Open a serial connection to display values
  Serial.begin(9600);
  // Set the LED pins as outputs
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Initialize values for temperature and humidity variables
  int temperature = 0;
  int humidity = 0;

  // Read the temperature and humidity values from the sensor
  int result = dht11.readTemperatureHumidity(temperature, humidity);

  // Check the results of the readings from the sensor
  // Print the temperature and humidity values if reading is successful
  if (result == 0) {
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" °C\tHumidity: ");
      Serial.print(humidity);
      Serial.println(" %");
  // Else print the error message if there are errors
  } else {
      // Print error message based on the error code.
      Serial.println(DHT11::getErrorString(result));
  }

  // If the current temperature is less than 20 °C, it is considered cool or cold and the blue LED will be lit up
  if (temperature < 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  // Else if the current temperature is between 20 °C and 25 °C, it is considered room temperature and the green LED will be lit up
  else if (temperature >= 20 && temperature <= 25) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }

  // Else if the current is temperature is equal to or more than 26 °C, it is considered warm or hot and the red LED will be lit up
  else if (temperature >= 26) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }

  // Set a delay of 1 second
  delay(1000);
}
