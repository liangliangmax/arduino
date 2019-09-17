int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  
  for(int i = 8;i<12;i++){
    ledOn(i);
    ledOff(i);  
  }
  for(int i = 12;i>7;i--){
    ledOn(i);
    ledOff(i);  
  }
  
}

void ledOn(int port){
    digitalWrite(port,HIGH);
    delay(20);

}

void ledOff(int port){
    digitalWrite(port,LOW);
    delay(20);

}
