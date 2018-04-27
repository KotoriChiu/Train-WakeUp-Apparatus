#include <stdio.h>
#include <string.h>
#include <windows.h>
/*  因為每個使用者的Serial port log產生路徑會些許不同
    所以請使用者在設定完下方數據之後自行編譯
*/
int main(){
    int train = 1;
    while(FindWindow(0,/*在此輸入視窗名稱*/)){
        char a ;
        char *filename = /*請在此輸入log位置 用法:X:/XXX/XXX.log*/;
        FILE *fp = fopen(filename,"r");
        char buf[1000];
        int lineCnt = 0;
        while(fgets(buf,1000,fp)) lineCnt++;
        fclose(fp);
        printf(buf);
        Sleep(100);//延遲個100毫秒 防止程式崩潰
        if(buf == 's' && train == 1){ //停車指令條件成立
            train = 0;
            //虛擬鍵盤用法 
            /*keybd_event(鍵碼,0,0,0)//這是按下
              keybd_event(鍵碼,0,KEYEVENTF_KEYUP,0)//這是放掉
              */
             //請注意 如果你的遊戲中的緊急煞車制動不是BackSpace鍵 那麼你得自己改下面的按鍵數據
            keybd_event(8, MapVirtualKey(8, 0), 0, 0);
            Sleep(300);
		    keybd_event(8, MapVirtualKey(8, 0), KEYEVENTF_KEYUP, 0);
        }else if(buf == 'a') train = 0;
    }
 return 0;
}
