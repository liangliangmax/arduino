int in_you_dao = 10; //you-dao
int in_you_zheng = 11; //you-zheng

int in_zuo_zheng = 5; 
int in_zuo_dao = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(in_you_dao,OUTPUT);
  pinMode(in_you_zheng,OUTPUT);

  pinMode(in_zuo_zheng,OUTPUT);
  pinMode(in_zuo_dao,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0;i<=255;i+=50){
    analogWrite(in_you_zheng,i);
    analogWrite(in_zuo_zheng,i);

    delay(500);  
  }

   for(int i = 255;i>=0;i-=50){
    analogWrite(in_you_zheng,i);
    analogWrite(in_zuo_zheng,i);

    delay(500);  
  }
//  digitalWrite(in1,LOW);
//  digitalWrite(in2,HIGH);
//
//  digitalWrite(in3,HIGH);
//  digitalWrite(in4,LOW);
}
