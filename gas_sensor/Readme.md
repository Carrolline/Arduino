# Анализатор качества воздуха с использованием датчика MQ-135
## Описание
Простой газовый анализатор на основе датчика качества воздуха mq135, он реагирует на изменения количества вредных газов в окружающей среде. 
При превышении порога вредных газов в 50% пьезодинамик издаёт звуковой сигнал. Показания снимаются каждую секунду.
## Компоненты
* датчик качества воздуха MQ-135
* соединительные провода
* пьезодинамик
* микроконтроллер Arduino
* lcd-экран
## Схема соединений
![img](https://github.com/Carrolline/Arduino/blob/main/gas_sensor/mq135_pr_bb.png?raw=true)
## Скетч в Arduino IDE
```C++
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  float a = analogRead(A0);
  a = a/255*100;
  Serial.println(a);
  lcd.setCursor(2,0);
  lcd.print("Air: ");
  lcd.print(a);
  lcd.print("%");
  if(a > 50){
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
    }
  delay(1000);
}
```
