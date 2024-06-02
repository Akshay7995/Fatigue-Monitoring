#define Relay A3
#define buzzer 13
static const int sensorPin = 11;  // sensor input pin
int SensorStatePrevious = LOW;    // previous state of the sensor

unsigned long minSensorDuration = 3000;  // Time we wait before the sensor activates for a long time
unsigned long minSensorDuration2 = 6000;
unsigned long SensorLongMillis;    // Time in ms when the sensor was active for a long time
bool SensorStateLongTime = false;  // True if it is a long active

const int intervalSensor = 50;       // Time between two readings of sensor state
unsigned long previousSensorMillis;  // Timestamp of the latest reading

unsigned long SensorOutDuration;  // Time the sensor is active in ms

unsigned long currentMillis;  // Variable to store the number of milliseconds since the Arduino has started

void setup() {
  Serial.begin(9600);  // Initialise the serial monitor

  pinMode(sensorPin, INPUT);  // set sensorPin as input
  Serial.println("Press button");
  pinMode(Relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

// Function for reading the sensor state
void readSensorState() {

  if (currentMillis - previousSensorMillis > intervalSensor) {

    int SensorState = digitalRead(sensorPin);
    if (SensorState == LOW && SensorStatePrevious == HIGH && !SensorStateLongTime) {
      SensorLongMillis = currentMillis;
      SensorStatePrevious = LOW;
    }

    SensorOutDuration = currentMillis - SensorLongMillis;

    if (SensorState == LOW && !SensorStateLongTime && SensorOutDuration >= minSensorDuration) {
      SensorStateLongTime = true;
      digitalWrite(Relay, LOW);
    }
    if (SensorState == LOW && SensorStateLongTime && SensorOutDuration >= minSensorDuration2) {
      SensorStateLongTime = true;
      digitalWrite(buzzer, LOW);
      delay(1000);
    }

    if (SensorState == HIGH && SensorStatePrevious == LOW && SensorOutDuration >= minSensorDuration2) {
      SensorStatePrevious = HIGH;
      SensorStateLongTime = false;
      digitalWrite(Relay, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Drowsiness detected!");
    }

    previousSensorMillis = currentMillis;
  }
}

void loop() {
  currentMillis = millis();  // store the current time
  readSensorState();         // read the sensor state
}