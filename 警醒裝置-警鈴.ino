int sp = 11;
int over = 1;
void setup(){
    pinMode(sp,OUTPUT);
    pinMode(3,INPUT); //警示音1
    pinMode(4,INPUT); //警示音2
    
}

void loop(){
    if(digitalRead(3)==HIGH && digitalRead(4)==LOW){
        tone(sp,710,1000);
        delay(1500);
        if(digitalRead(3)==LOW || digitalRead(4)==HIGH){
          tone(sp,550,70);
          over = 0;
        }
    }else if(digitalRead(4)==HIGH && digitalRead(3)==LOW){
        tone(sp,710,80);
        delay(115);
        tone(sp,710,80);
        delay(115);
        tone(sp,710,80);
        delay(600);
        if(digitalRead(4)==LOW || digitalRead(3)==HIGH){
          tone(sp,550,70);
          over = 0;
        }
    }else if(digitalRead(3)==HIGH && digitalRead(4) == HIGH){
        tone(sp,710,80);
        delay(115);
        if(over == 1 && (digitalRead(3)==LOW || digitalRead(4)==LOW)){
          tone(sp,550,70);
          over = 0;
        }
    }
}