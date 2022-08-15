int value;
bool blink = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(0, interrupt, FALLING                                                                          );
}

void loop() {
  // put your main code here, to run repeatedly:
  ReadSerial();
    switch(value){
      case '1': // led1 on
         digitalWrite(13, HIGH);
         WriteSerial();
         break;
      case '2': // led1 off 
         digitalWrite(13, LOW);
         WriteSerial();
         break;
      case '3': // led2 on
         digitalWrite(12, HIGH);
         WriteSerial();
         break;
      case '4': // led2 off
         digitalWrite(12, LOW);
         WriteSerial();
         break;
      case '5': // blink on
         blink = true;
         WriteSerial();
         break;
      case '6': // blink off
         blink = false;
         digitalWrite(13, LOW);
         digitalWrite(12, LOW);
         WriteSerial();
         break;
    }
    

  if(blink){
    Blink();
  }
}

void ReadSerial(){
  if(Serial.available()){
    value = Serial.read();
   
  }
}

void WriteSerial(){
  delay(200);
  Serial.println("Islem basarili!");
}

void Blink(){
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   delay(500);
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   delay(500);
}

void interrupt(){
    blink = !blink;
}
