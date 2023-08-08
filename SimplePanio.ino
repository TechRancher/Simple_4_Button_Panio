/*
  Simple 4 button Panio
  To learn more about this project, read the readME.adoc
*/

//Header
//Define
#define Key_C 440 // 440Hz
#define Key_D 494 // 493.883Hz
#define Key_E 554 // 554.365Hz
#define Key_G 659 // 659.255Hz
//Variables
int buzzPin = 9;
int cPin = 2;
int dPin = 3;
int ePin = 4;
int gPin = 5;
boolean _bActiveLow = true;
int bVal;
int dT = 200;
int boardLED = LED_BUILTIN;
//Function
boolean isPressed(int btnPin){
  int btnVal = digitalRead(btnPin);
  if(_bActiveLow && btnVal == LOW){
    digitalWrite(boardLED, HIGH);
    return true;
  }
  return false;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  pinMode(buzzPin, OUTPUT);
  pinMode(cPin, INPUT_PULLUP);
  pinMode(dPin, INPUT_PULLUP);
  pinMode(ePin, INPUT_PULLUP);
  pinMode(gPin, INPUT_PULLUP);
  pinMode(boardLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  bVal = digitalRead(gPin);
  Serial.println(bVal);
  if(isPressed(cPin)){
    tone(buzzPin, Key_C);
  } else if(isPressed(dPin)){
    tone(buzzPin, Key_D);
  } else if (isPressed(ePin)){
    tone(buzzPin, Key_E);
  } else if (isPressed(gPin)){
    tone(buzzPin, Key_G);
  } else {
    noTone(buzzPin);
    digitalWrite(boardLED, LOW);
  }

}
