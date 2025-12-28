int greenPin = 3;
int yellowPin = 4;
int redPin = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenPin, HIGH);
  delay(5000);

  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(1000);

  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(5000);

  digitalWrite(redPin, LOW);
}
