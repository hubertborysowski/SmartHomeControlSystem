class BasePin{
  public:
  BasePin(){}
  ~BasePin(){}
  virtual void receiveData() = 0;
};
class DPin13 : public BasePin{
  public:
  uint8_t pinNumber = 13;
  uint8_t pinState = LOW;
  DPin13(){}
  ~DPin13(){}
  void receiveData(){
      if(pinState == LOW){
        digitalWrite(pinNumber, HIGH);
        Serial.write('A');
        pinState = HIGH;
        delay(100);
      }
      else if(pinState == HIGH){
        digitalWrite(pinNumber, LOW);
        Serial.write('A');
        pinState = LOW;
        delay(100);
    }
  }
};
BasePin* wsk = nullptr;
static DPin13 obj13;
void setup() {
  Serial.begin(9600);
  delay(1000);  // Allow time for serial communication to initialize.
  pinMode(13, OUTPUT);    
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case 'A':
        wsk = &obj13;
          if (wsk != nullptr){
            wsk->receiveData();
          }
      break;
      case 'Z':
        //TO-DO Serial.write() All states!
      break;
    }
  }

  delay(100);
}