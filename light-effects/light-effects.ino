byte leds[] = {4,5,6,7,8,9,10,11,12,13};
int ledDelay;
int direction = 1;
int currentLed = 0;
int potPin = 3;
unsigned long timeChange;

void setup(){
  for(int x = 0; x < 10; x++){
    pinMode(leds[x],OUTPUT);
  }
  timeChange = millis();
  Serial.begin(9600);
}

void loop(){
  ledDelay = analogRead(potPin);
  Serial.println(analogRead(potPin));
  
  if((millis() - timeChange) > ledDelay){
    ledChange();
    timeChange = millis();
  }
}

void ledChange(){
  for(int x = 0; x < 10; x++){
    digitalWrite(leds[x], LOW);
  }
  
  digitalWrite(leds[currentLed],HIGH);
  currentLed += direction;
  if(currentLed == 9){ direction = -1;}
  if(currentLed == 0){ direction = 1;}
}


