#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <io.h>
/*  �]���C�ӨϥΪ̪�Serial port log���͸��|�|�ǳ\���P
    �ҥH�ШϥΪ̦b�]�w���U��ƾڤ���ۦ�sĶ
*/
int main(){
    int train = 1;
    int aaaa = 1;
    while(1){
    	printf("���ݹC���Ұ�\n");
    	Sleep(1000);
    while(FindWindow(0,"Train Simulator") && !access("D:/Steam/steamapps/common/RailWorks/Write Cache",0)){ //Write Cache�C������ɲ��ͪ���Ƨ� �ˬd�� �i�H���Υ[
        if(aaaa){
        	printf("�C�����w������ �}�l����!!!\n");
        	aaaa = 0;
		}
		char a ;
        char *filename = "D:/teraterm.log"; //log����l �Цۦ�ק�
        FILE *fp = fopen(filename,"r");
        char buf[1000];
        int lineCnt = 0;
        while(fgets(buf,1000,fp)) lineCnt++;
        fclose(fp);
        Sleep(100);//�����100�@�� ����{���Y��
        printf(buf);
        printf("\n");
        if(buf[0] == 's' && train == 1){ //�������O���󦨥�
            printf("����!!!!\n");
            //������L�Ϊk 
            //keybd_event(��X,0,0,0)//�o�O���U
            //keybd_event(��X,0,KEYEVENTF_KEYUP,0)//�o�O��
              
             //�Ъ`�N �p�G�A���C���������٨���ʤ��OBackSpace�� ����A�o�ۤv��U��������ƾ�
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

