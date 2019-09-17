
int buttonState = 0;

void setup(){
    pinMode(8,OUTPUT);

    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
}

void loop(){
    buttonState = digitalRead(7);
    
    if(buttonState == HIGH){
        digitalWrite(13,LOW);
        digitalWrite(8,LOW);
        
    }else{
        digitalWrite(13,HIGH);
        digitalWrite(8,HIGH);
    }
    
    
}