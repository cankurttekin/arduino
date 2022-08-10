void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Input 1 to Turn LED on and 2 to off");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    int state = Serial.parseInt();
    if (state == 1)
    {
      digitalWrite(13, HIGH);
    }
    
    if (state == 2)
    {
      digitalWrite(13, LOW);
    }
    
    if (state == 3)
    {
      digitalWrite(12, HIGH);
    }
    
    if (state == 4)
    {
      digitalWrite(12, LOW);
    }
  }
}
