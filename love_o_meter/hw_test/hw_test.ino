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
  digitalWrite(ledOne, HIGH);
  digitalWrite(ledTwo, HIGH);
  digitalWrite(ledThree, HIGH);
  
  delay(1);
}

