// Подключение библиотек
#include <SPI.h>
#include <MFRC522.h>
// константы подключения контактов SS и RST
#define RST_PIN 9
#define SS_PIN 10
// Инициализация MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
void setup()
{
Serial.begin(9600); // инициализация последовательного порта
SPI.begin(); // инициализация SPI
mfrc522.PCD_Init(); // инициализация MFRC522
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(2, OUTPUT);
}
void loop()
{
if ( ! mfrc522.PICC_IsNewCardPresent())
return;
// чтение карты
if ( ! mfrc522.PICC_ReadCardSerial())
return;
// показать результат чтения UID и тип метки
Serial.print(F("Card UID:"));
dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
Serial.println();
//Serial.println(mfrc522.uid.uidByte[0]);
Serial.print(F("PICC type: "));
byte piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
Serial.println(mfrc522.PICC_GetTypeName(piccType));


if(mfrc522.uid.uidByte[0] == 192){
digitalWrite(3, HIGH);
digitalWrite(2, HIGH);
delay(1000);
digitalWrite(3, LOW);
digitalWrite(2, LOW);
}


if(mfrc522.uid.uidByte[0] == 197){
digitalWrite(4, HIGH);
digitalWrite(2, HIGH);
delay(1000);
digitalWrite(4, LOW);
digitalWrite(2, LOW);
}


delay(2000);
}
// Вывод результата чтения данных в HEX-виде
void dump_byte_array(byte *buffer, byte bufferSize)
{
for (byte i = 0; i < bufferSize; i++)
{
Serial.print(buffer[i] < 0x10 ? " 0" : " ");
Serial.print(buffer[i], HEX);
}
//Serial.println(buffer);
}
