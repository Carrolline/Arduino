void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(9, 5);
  delay(1000);
  analogWrite(9, 0);
  delay(1000);
  analogWrite(10, 5);
  delay(1000);
  analogWrite(10, 0);
  delay(1000);
  analogWrite(11, 5);
  delay(1000);
  analogWrite(11, 0);
  delay(1000);

  analogWrite(9, 5);
  analogWrite(10, 5);
  analogWrite(11, 5);
  delay(1000);

  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(1000);
  
}
