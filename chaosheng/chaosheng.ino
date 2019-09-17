
const int echo = 3;

const int trig = 2;


float cm = 0.0;

void setup(){
    Serial.begin(9600);
    pinMode(echo,INPUT);
    pinMode(trig,OUTPUT);
}

void loop(){
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);

    digitalWrite(trig,LOW);

    cm = pulseIn(echo,HIGH) / 58;

    cm = (int(cm*100)) / 100;
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
    delay(1000);


}