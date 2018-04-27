int sp = 11;

void setup(){
    pinMode(sp,OUTPUT);
    pineMode(3,INPUT); //警示音1
    pineMode(4,INPUT); //警示音2
    
}

void loop(){
    if(digitalRead(3)==HIGH){
        tone(sp,710,1000);
        delay(1500);
    }else if(digitalRead(4)==HIGH){
        tone(sp,710,80);
        delay(115);
        tone(sp,710,80);
        delay(115);
        tone(sp,710,80);
        delay(600);
    }
}