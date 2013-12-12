/* Love-o-Meter */

const int sensorPin = A0;
const int ledOne = 2;
const int ledTwo = 3;
const int ledThree = 4;
const int switchButton = 5;

const float baselineTemp = 22.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(switchButton, INPUT);
}

void loop() {
  int deviceStatus = digitalRead(switchButton);

  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;

  if (deviceStatus == 0) {
    loveMeterLed(temperature);
  } else {
    printTemperature(sensorVal, voltage, temperature);
    debugLed(20.0);
    debugLed(23.0);
    debugLed(25.0);
    debugLed(28.0);
  }

  delay(1);
}

void loveMeterLed(float temperature) {
  if (temperature <= 22.0) {
    digitalWrite(ledOne, LOW);
    digitalWrite(ledTwo, LOW);
    digitalWrite(ledThree, LOW);
  }

  if (temperature > 22.0) {
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, LOW);
    digitalWrite(ledThree, LOW);
  }

  if (temperature > 24.0) {
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, HIGH);
    digitalWrite(ledThree, LOW);
  }

  if (temperature > 26.0) {
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, HIGH);
    digitalWrite(ledThree, HIGH);
  }
}

void printTemperature(int sensorVal, float voltage, float temperature) {
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
}

void debugLed(float temperature) {
  loveMeterLed(temperature);
  delay(50);
}
