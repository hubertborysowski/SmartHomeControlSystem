class BasePin{
  public:
  bool check;
  BasePin() : check(true){}
  virtual ~BasePin(){}
  virtual void receiveData() = 0;

  bool operator==(const BasePin& other) const {
    return this == &other;
  }
  bool operator!=(const BasePin& other) const {
    return this != &other; 
  }
};
class DPin2 : public BasePin{
  public:
  uint8_t pinNumber = 2;
  uint8_t pinState = LOW;
  DPin2(){}
  ~DPin2(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('a');
        }
        else if(pinState == HIGH){
          Serial.write('A');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('A');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('a');
        pinState = LOW;
        delay(100);
    }
  }
};
class DPin3 : public BasePin{
  public:
  uint8_t pinNumber = 3;
  uint8_t pinState = LOW;
  DPin3(){}
  ~DPin3(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('b');
        }
        else if(pinState == HIGH){
          Serial.write('B');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('B');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('b');
        pinState = LOW;
        delay(100);
    }
  }
};
class DPin4 : public BasePin{
  public:
  uint8_t pinNumber = 4;
  uint8_t pinState = LOW;
  DPin4(){}
  ~DPin4(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('c');
        }
        else if(pinState == HIGH){
          Serial.write('C');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('C');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('c');
        pinState = LOW;
        delay(100);
    }
  }
};
class DPin5 : public BasePin{
  public:
  uint8_t pinNumber = 5;
  uint8_t pinState = LOW;
  DPin5(){}
  ~DPin5(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('d');
        }
        else if(pinState == HIGH){
          Serial.write('D');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('D');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('d');
        pinState = LOW;
        delay(100);
    }
  }
};
class DPin6 : public BasePin{
  public:
  uint8_t pinNumber = 6;
  uint8_t pinState = LOW;
  DPin6(){}
  ~DPin6(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('e');
        }
        else if(pinState == HIGH){
          Serial.write('E');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('E');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('e');
        pinState = LOW;
        delay(100);
    }
  }
};
class DPin7 : public BasePin{
  public:
  uint8_t pinNumber = 7;
  uint8_t pinState = LOW;
  DPin7(){}
  ~DPin7(){}
  void receiveData(){
      if(check){
        if(pinState == LOW){
          Serial.write('f');
        }
        else if(pinState == HIGH){
          Serial.write('F');
        } 
        check = false;
      }
      else if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('F');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('f');
        pinState = LOW;
        delay(100);
    }
  }
};
BasePin* wsk = nullptr;
static DPin2 pin2;
static DPin3 pin3;
static DPin4 pin4;
static DPin5 pin5;
static DPin6 pin6;
static DPin7 pin7;
void setup() {
  Serial.begin(9600);
  delay(1000);  // Allow time for serial communication to initialize.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}
void resetAllPins() {
  pin2.check = true;
  pin3.check = true;
  pin4.check = true;
  pin5.check = true;
  pin6.check = true;
  pin7.check = true;
}
void resetSinglePin(){
  if (*wsk == pin2) pin2.check = true;
  if (*wsk == pin3) pin3.check = true;
  if (*wsk == pin4) pin4.check = true;
  if (*wsk == pin5) pin5.check = true;
  if (*wsk == pin6) pin6.check = true;
  if (*wsk == pin7) pin7.check = true;
}
char bajt;
bool singlePinCheck;
void loop() {
  if(Serial.available()){
    bajt = Serial.read();
    if(bajt == 'Y'){
      singlePinCheck = true;
      bajt = Serial.read();
    }
    switch(bajt){
      case 'A':
        wsk = &pin2;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'B':
        wsk = &pin3;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'C':
        wsk = &pin4;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'D':
        wsk = &pin5;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'E':
        wsk = &pin6;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'F':
        wsk = &pin7;
        if (wsk != nullptr){
          if(singlePinCheck){
            resetSinglePin();
            singlePinCheck = false;
          }
          wsk->receiveData();
        }
        break;
      case 'Y':
        singlePinCheck = false;
        break;
      case 'Z':
        Serial.write('Z');
        if (wsk != nullptr){
            resetAllPins();
          }
      break;
    }
  }

  delay(100);
}