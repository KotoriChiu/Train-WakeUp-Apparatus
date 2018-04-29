#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <io.h>
/*  因為每個使用者的Serial port log產生路徑會些許不同
    所以請使用者在設定完下方數據之後自行編譯
*/
int main(){
    int train = 1;
    int aaaa = 1;
    while(1){
    	printf("等待遊戲啟動\n");
    	Sleep(1000);
    while(FindWindow(0,"Train Simulator") && !access("D:/Steam/steamapps/common/RailWorks/Write Cache",0)){ //Write Cache遊戲執行時產生的資料夾 檢查用 可以不用加
        if(aaaa){
        	printf("遊戲文件已偵測到 開始執行!!!\n");
        	aaaa = 0;
		}
		char a ;
        char *filename = "D:/teraterm.log"; //log文件位子 請自行修改
        FILE *fp = fopen(filename,"r");
        char buf[1000];
        int lineCnt = 0;
        while(fgets(buf,1000,fp)) lineCnt++;
        fclose(fp);
        Sleep(100);//延遲個100毫秒 防止程式崩潰
        printf(buf);
        printf("\n");
        if(buf[0] == 's' && train == 1){ //停車指令條件成立
            printf("停車!!!!\n");
            //虛擬鍵盤用法 
            //keybd_event(鍵碼,0,0,0)//這是按下
            //keybd_event(鍵碼,0,KEYEVENTF_KEYUP,0)//這是放掉
              
             //請注意 如果你的遊戲中的緊急煞車制動不是BackSpace鍵 那麼你得自己改下面的按鍵數據
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
        
        }
    }
 return 0;
}

