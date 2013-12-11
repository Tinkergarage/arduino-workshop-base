/* Build led control without thermal sensor */

const int ledOne = 2;
const int ledTwo = 3;
const int ledThree = 4;

void setup() {
  Serial.begin(9600);
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
}

void loop() {
  loveMeterLed(20.0);
  delay(500);

  loveMeterLed(23.0);
  delay(500);

  loveMeterLed(25.0);
  delay(500);

  loveMeterLed(28.0);
  delay(500);

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
