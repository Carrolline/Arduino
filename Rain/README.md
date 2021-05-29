# Подключение датчика влажности дождя
## Описание
Подключение датчика влажности дождя к микроконтроллеру Ардуино, вывод параметров на lcd-экран 
## Компоненты
* датчик дождя
* соединительные провода
* микроконтроллер Arduino
* lcd-экран
## Схема соединений
![img](https://github.com/Carrolline/Arduino/blob/main/Rain/Rain.png?raw=true)
## Скетч в Arduino IDE
```C++
#include <LCD_1602_RUS.h>
#include <LiquidCrystal_I2C.h>
LCD_1602_RUS LCD(0x27,16,2);
LiquidCrystal_I2C lcd(0x27,16,2); // Указываем I2C адрес (наиболее распространенное значение), а также параметры экрана (в случае LCD 1602 - 2 строки по 16 символов в каждой 

void setup() {
  // put your setup code here, to run once: 
  pinMode(A0, INPUT);
  lcd.init();                      // Инициализация дисплея  
  lcd.backlight();                 // Подключение подсветки
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(2,0);
  LCD.print("Дождь:"); 
  float read_rain = analogRead(A0);
  float rain = ((1023 - read_rain)/1023)*100;
  lcd.print(rain); 
  lcd.print("%");
  delay(3000); 
}
}
```
