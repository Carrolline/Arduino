
#include <Keypad.h> // подключаем библиотеку для управление клавиатурой

const byte ROWS = 4; //число строк у нашей клавиатуры
const byte COLS = 4; //число столбцов у нашей клавиатуры
char hexaKeys[ROWS][COLS] = {// здесь мы располагаем названия наших клавиш, как на клавиатуре,для удобства пользования
{'4','8','#','D'}, 
{'3','7','*','C'},
{'2','6','0','B'},
{'1','5','9','A'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; //к каким выводам подключаем управление строками
byte colPins[COLS] = {5, 4, 3, 2}; //к каким выводам подключаем управление столбцами

//передаем все эти данные библиотеке:
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);//запускаем отладочный вывод в монитор порта
}

void loop(){
char customKey = customKeypad.getKey();//записывем нажатый символ

if (customKey){//если что-то нажато
  Serial.println(customKey);//выводим нажатый символ в монитор порта
}

}
