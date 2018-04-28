#include <stdio.h>
#include <windows.h>
int main(){
	while(1){
		Sleep(1000);
			if(FindWindow(0,"Train Simulator")){ //用法 將要偵測的程式視窗名字貼上
		printf("YES\n");
      }else{
      	printf("NO\n");
	  }
	}

return 0;

}

