int value;
bool upValue = false;
bool blink = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, interrupt, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  ReadSerial();
  
  if(upValue){
    switch(value){
      case '1':
            digitalWrite(13, HIGH);
        break;
      case '2':
            digitalWrite(13, LOW);
            break;
        case '3':
            digitalWrite(12, HIGH);
            break;
        case '4':
            digitalWrite(12, LOW);
            break;
      case '5':
            blink = true;
        upValue= false;
            break;
        case '6':
            blink = false;
        digitalWrite(13, LOW);
          digitalWrite(12, LOW);
        upValue = false;
            break;
    }
}
  
  if(blink){
    Blink();
  }
}


void ReadSerial(){
  if(Serial.available() > 0){
    value = Serial.read();
    upValue = true;
  }
}


void Blink(){
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   delay(1000);
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   delay(1000);
}


void interrupt(){
    blink = !blink;
}
