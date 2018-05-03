#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <iostream>
#include "SerialPort.h"

using namespace std;

char *port_name = "\\\\.\\COM20";
char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
/*  因為每個使用者的Serial port log產生路徑會些許不同
    所以請使用者在設定完下方數據之後自行編譯
*/
int main(){
    SerialPort arduino(port_name);
    int train = 1;
    int aaaa = 1;
    while(1){
    	printf("等待遊戲啟動\n");
    	Sleep(1000);
        if(!arduino.isConnected()){
            printf("Arduino未連接!!!!");
        }else{
            
            while(FindWindow(0,"Train Simulator") && !access("D:/Steam/steamapps/common/RailWorks/Write Cache",0)){ //這裡需要改成 當進入列車任務時
                if(aaaa){
        	        printf("遊戲文件已偵測到 開始執行!!!\n");
        	        aaaa = 0;
		        }
                if(){ //列車時速不是0的時候
                arduino.writeSerialPort("g"); //發送g 當arduino耶收到g時 警醒裝置開始有作用
		        char a ;
                char *filename = "G:/yee/teraterm.log"; //log文件位子 請自行修改
                FILE *fp = fopen(filename,"r");
                char buf[1000];
                int lineCnt = 0;
                while(fgets(buf,1000,fp)) lineCnt++;
                fclose(fp);
                Sleep(100);//延遲個100毫秒 防止程式崩潰
                printf("目前時速"); //這裡將印出遊戲中的列車時速
                printf("\n");
                if(buf[0] == 's' && train == 1){ //停車指令條件成立 
                    printf("停車!!!!\n");
                    //虛擬鍵盤用法 
                    //keybd_event(鍵碼,0,0,0)//這是按下
                    //keybd_event(鍵碼,0,KEYEVENTF_KEYUP,0)//這是放掉
                    //請注意 如果你的遊戲中的緊急煞車制動不是BackSpace鍵 那麼你得自己改下面的按鍵數據
                    //這邊的按鍵動作是先啟動列車的緊急停車制動 再將電門放掉 然後再將電韌開到最大
                    keybd_event(8, MapVirtualKey(8, 0), 0, 0);
                    Sleep(300);
		            keybd_event(8, MapVirtualKey(8, 0), KEYEVENTF_KEYUP, 0);
		            keybd_event(68, MapVirtualKey(68, 0), 0, 0);
                    Sleep(2000);
                    keybd_event(68, MapVirtualKey(68, 0), KEYEVENTF_KEYUP, 0);
                    keybd_event(222, MapVirtualKey(222, 0), 0, 0);
		            Sleep(2000);
                    keybd_event(222, MapVirtualKey(222, 0), KEYEVENTF_KEYUP, 0);
                    train = 0;
                }else if(buf[0] != 's')train = 1;
                }else if(train = 1){
                    arduino.writeSerialPort("k");//當arduino收到k時 警醒裝置不再有作用
                }     
            }
        }
    }
 return 0;
}
