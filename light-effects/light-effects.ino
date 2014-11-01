byte leds[] = {4,5,6,7,8,9,10,11,12,13};
int ledDelay;
int direcao = 1;
int ledAtual = 0;
int potPin = 3;
unsigned long mudarTempo;

void setup(){
  for(int x = 0; x < 10; x++){
    pinMode(leds[x],OUTPUT);
  }
  mudarTempo = millis();
  Serial.begin(9600);
}

void loop(){
  ledDelay = analogRead(potPin);
   Serial.println(analogRead(potPin));
  
  if((millis() - mudarTempo) > ledDelay){
    mudarLed();
    mudarTempo = millis();
  }
}

void mudarLed(){
  for(int x = 0; x < 10; x++){
    digitalWrite(leds[x], LOW);
  }
  
  digitalWrite(leds[ledAtual],HIGH);
  ledAtual += direcao;
  if(ledAtual == 9){ direcao = -1;}
  if(ledAtual == 0){ direcao = 1;}
}


