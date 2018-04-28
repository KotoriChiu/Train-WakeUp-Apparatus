int sw = 7;                         //警醒裝置開關腳位
int powersw = 9;                    //電源開關(決定要不要啟用警醒裝置)
int step_on_reciprocal = 90;        //踩著時倒數秒數
int step_up_reciprocal = 90;        //放開時倒數秒數
unsigned long previousTime = 0;     //儲存系統運作時間(故用unsigned long)
int uno1 = 2;                       //傳給音效uno板的訊號線1
int uno2 = 3;                       //傳給音效uno板的訊號線2


void setup(){
    pinMode(sw,INPUT);      //警醒裝置開關設為讀取
    pinMode(2,OUTPUT);      //訊號線1設為輸出
    pinMode(3,OUTPUT);      //訊號線2設為輸出
    pinMode(powersw,INPUT); //電源開關設為讀取
    Serial.begin(9600);     //設定鮑率9600
}
void loop(){
    if(digitalRead(powersw) == HIGH){   //決定要不要啟用警醒裝置
    while(digitalRead(sw)==HIGH){      
        if(digitalRead(powersw) == LOW) break;
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
                digitalWrite(2,HIGH);
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
        if(digitalRead(powersw) == LOW) break;
        step_on_reciprocal = 20;
        Serial.println("a");
        unsigned long step_up = millis()/1000;
        if(step_up - previousTime > 1){
            step_up_reciprocal--;
            previousTime++;
        }
        if(step_up_reciprocal <= 10 && step_up_reciprocal > 5){
            digitalWrite(2,HIGH);
            digitalWrite(3,LOW);
        }else if(step_up_reciprocal <= 5 && step_up_reciprocal != 0){
            digitalWrite(2,LOW);
            digitalWrite(3,HIGH);
        }else if(step_up_reciprocal == 0 ){
            Serial.println("s");
            step_on_reciprocal = 20;
            while(digitalRead(sw)==LOW){
              unsigned long b = millis()/1000;
                digitalWrite(2,HIGH);
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
}