#include <Servo.h>

Servo myservo;

//初始位置在中间
int pos = 90;

const int echo = 3; //超声波接受
const int trig = 2; //超声波发射

const int rightLight  = 4;    //左转向灯
const int leftLight = 5;   //右转向灯


float cm = 0.0;

void setup(){
    Serial.begin(9600);

    pinMode(echo,INPUT);
    pinMode(trig,OUTPUT);
    pinMode(leftLight,OUTPUT);

    pinMode(rightLight,OUTPUT);

    myservo.attach(6);


}


void loop(){

    go();

}

void go(){
    int front = frontDistance();
    Serial.print("检测到前方距离为 ");
    Serial.print(front);
    Serial.println("cm");
    delay(200);

    //如果距离大于5cm，则继续往前走
    if(front >10.0){
        goFront();

    }else{
        //如果小于5厘米，则需要先停下来，然后旋转舵机，开始找左右两边哪边距离比较大，然后小车转向哪边
        stop();
        servoTurnLeft();

        delay(1000);

        int leftFront = frontDistance();
        Serial.print("检测到左方距离为 ");
        Serial.print(leftFront);
        Serial.println("cm");


        servoReset();

        servoTrunRight();

        delay(1000);

        int rightFront = frontDistance();
        Serial.print("检测到右方距离为 ");
        Serial.print(rightFront);
        Serial.println("cm");

        servoReset();


        if(leftFront > rightFront){
            goLeft();
        }else if (leftFront == rightFront)
        {
            goBack();
        }else
        {
            goRight();
        }


    }
    


}


void goFront(){

    Serial.println("向前走");
    delay(1000);
}

void goBack(){
    Serial.println("向后走");

    delay(1000);
}

void goLeft(){

    lightBlink(leftLight);
    Serial.println("向左");

    delay(1000);

}


void goRight(){

    lightBlink(rightLight);
    Serial.println("向右");

    delay(1000);

}


void stop(){
    Serial.println("停止");

    delay(1000);
}

//测量超声波所对前方的距离
int frontDistance(){

    do{
      digitalWrite(trig,LOW);
      delayMicroseconds(2);
      digitalWrite(trig,HIGH);
      delayMicroseconds(20);
      digitalWrite(trig,LOW);
  
      cm = pulseIn(echo,HIGH) /58.3;
      cm = (int(cm*100)) / 100;
      
    }while(cm <0);
    
    return cm;
}

void servoTurnLeft(){
    for(int i = pos;i<180;i++){
        myservo.write(i);
        delay(15);
    }


}

void servoTrunRight(){


    for(int i = pos;i >= 0;i--){
        myservo.write(i);
        delay(15);
    }

}

void servoReset(){
    myservo.write(pos);
    delay(15);
}


void lightBlink(int port){

    for(int i =0;i<5;i++){
        digitalWrite(port,HIGH);
        delay(1000);
        digitalWrite(port,LOW);
        delay(1000);
    }
}
