bool blink = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  //while(!Serial);
  //Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    int state = Serial.read();
    switch(state){
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
        //break;
      case '6':
        blink = false;
        break;
    }

    if(blink){
      Blink(blink);
    }else{
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
    }
  }
}


void Blink(bool blink){
  while(blink){
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   delay(1000);
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   delay(1000);
  }
  
   digitalWrite(12, LOW);
   digitalWrite(13, LOW);
 }
