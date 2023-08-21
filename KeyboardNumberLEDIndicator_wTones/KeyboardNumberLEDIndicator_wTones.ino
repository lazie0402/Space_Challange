int Green = 10; // Green on pin 10
int Yellow = 11; // Yellow LED
int Red = 12; // Red LED
int Buzzer = 13; // sound buzzer

//**************************************

#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'}, //first row
  {'4', '5', '6', 'B'}, //2nd
  {'7', '8', '9', 'C'}, //3rd
  {'*', '0', '#', 'D'}, //4th
};

byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad kp0 = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

int tones[ROWS][COLS] = {   // a frequency tone for each button
    {31, 93, 147, 208},
    {247, 311, 370, 440},
    {523, 587, 698, 880},
    {1397, 2637, 3729, 4978}
};
//*******************************************************************************

void setup() {
  // put your setup code here, to run once:
  pinMode (Green, OUTPUT);   // set Green pin to output
  pinMode (Red ,OUTPUT);
  pinMode (Yellow ,OUTPUT);
  pinMode (Buzzer ,OUTPUT);

  Serial.begin(9600);     // start serial communication
  digitalWrite (Green, LOW); // start with all off
  digitalWrite (Yellow, LOW);
  digitalWrite (Red, LOW);
}

//***********************************************************************************

void loop() {
  // put your main code here, to run repeatedly:
  int toneFreq = 0;

  char result = kp0.getKey();

  if (result) {            // if button pressed, display the character and blink yellow
   
   for (byte j=0; j<ROWS; j++) {
     for (byte i=0; i<COLS; i++) {
        if (result == buttons[j][i]) {   // found it, get the corresponding tone
            toneFreq=tones[j][i];
               }
           
        }  // end i loop
     }  // end j loop
//**********************************************************************
    Serial.print("Key:  "); //send result to serial
    Serial.print(result);
    Serial.print(" Freq:  ");
    Serial.println(toneFreq);

    //********************************************************

    tone(Buzzer, toneFreq, 500);
    digitalWrite (Yellow , HIGH);
    delay(500);           // Green on time (ms)
    noTone(Buzzer);
    digitalWrite (Yellow , LOW);
  }
}
