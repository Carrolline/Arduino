void setup()
{

  pinMode(9, OUTPUT);
 

  pinMode(A0, INPUT);
}
 
void loop(){
  int rotat, brightn;  

  rotat = analogRead(A0);
 

  brightn = rotat / 10;

  analogWrite(9, brightn);
  analogWrite(10, brightn);
  analogWrite(11, brightn);
}
