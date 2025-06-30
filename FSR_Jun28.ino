#define FORCE_SENSOR_PIN1 A0 // Left force sensor
#define FORCE_SENSOR_PIN2 A1 // Right force sensor

// Store previous readings for comparison
int prevReading1 = -1;
int prevReading2 = -1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogReading1 = analogRead(FORCE_SENSOR_PIN1);
  int analogReading2 = analogRead(FORCE_SENSOR_PIN2);

  // Check if any reading changed
  if (analogReading1 != prevReading1 ||
      analogReading2 != prevReading2) {
        
    Serial.print("Sensor 1: ");
    Serial.print(analogReading1);
    Serial.print(" | Sensor 2: ");
    Serial.println(analogReading2);

    // Update previous readings
    prevReading1 = analogReading1;
    prevReading2 = analogReading2;
  }

  // Optional small delay to reduce CPU load
  delay(100);
}
