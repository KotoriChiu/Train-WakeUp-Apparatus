int sw = 7;
int step_on_reciprocal = 20;
int step_up_reciprocal = 10;
unsigned long previousTime = 0;
int uno1 = 2;
int uno2 = 3;


void setup(){
    pinMode(sw,INPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    Serial.begin(9600);
}
void loop(){
    while(digitalRead(sw)==HIGH){
        step_up_reciprocal = 10;
        Serial.println("a");
        unsigned long step_on = millis()/1000;
        if(step_on - previousTime > 1){
            step_on_reciprocal --;
            previousTime++;
        }
        if(step_on_reciprocal <= 10 && step_on_reciprocal > 5){
            digitalWrite(2,HIGH);
            digitalWrite(3,LOW);
        }else if(step_on_reciprocal <= 5 && step_on_reciprocal !=0){
            digitalWrite(2,LOW);
            digitalWrite(3,HIGH);
        }else if(step_on_reciprocal == 0){
            Serial.println("s");
            step_up_reciprocal = 10;
            while(digitalRead(sw)==HIGH){
                digitalWrite(2,LOW);
                digitalWrite(3,HIGH);
                unsigned long a = millis()/1000;
                if(a - previousTime > 1){
                  previousTime++;
              }
            }
        }else{
            digitalWrite(2,LOW);
            digitalWrite(3,LOW);
        }
    }
    while(digitalRead(sw)==LOW){
        step_on_reciprocal = 20;
        Serial.println("a");
        unsigned long step_up = millis()/1000;
        if(step_up - previousTime > 1){
            step_up_reciprocal--;
            previousTime++;
        }
        if(step_up_reciprocal <= 5 && step_up_reciprocal > 0){
            digitalWrite(2,LOW);
            digitalWrite(3,HIGH);
        }else if(step_up_reciprocal == 0 ){
            Serial.println("s");
            step_on_reciprocal = 20;
            while(digitalRead(sw)==LOW){
              unsigned long b = millis()/1000;
                digitalWrite(2,LOW);
                digitalWrite(3,HIGH);
                if(b - previousTime > 1){
                    previousTime ++;
                }
            }
        }else{
            digitalWrite(2,LOW);
            digitalWrite(3,LOW);
        }
    }
}