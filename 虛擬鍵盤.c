#include <stdio.h>
#include <windows.h>

int main(){
	while(1){
		Sleep(1000);
		keybd_event(8, MapVirtualKey(8, 0), 0, 0);
        Sleep(300);
		keybd_event(8, MapVirtualKey(8, 0), KEYEVENTF_KEYUP, 0);
	}
	return 0;
}