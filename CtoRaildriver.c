#include <stdio.h>
#include <windows.h>

typedef double (*importFunction)(double);

int main(){
    while(1){
    importFunction tractionDial;
    importFunction accelerometer;
    importFunction current;
    importFunction ammeter;
    importFunction speedometerKPH;
    importFunction ammeterNeedle;
    importFunction tractiveEffort;
    double result[7];

    HINSTANCE hinstLib = LoadLibrary(TEXT("D:/Steam/steamapps/common/RailWorks/plugins/RailDriver.dll")); 
    if (hinstLib == NULL) {  
        printf("ERROR: unable to load DLL\n");  
        system("pause");  
        return 1;  
    } 
    tractionDial = (importFunction)GetProcAddress(hinstLib,"TractionDial");
    accelerometer = (importFunction)GetProcAddress(hinstLib,"Accelerometer");
    current = (importFunction)GetProcAddress(hinstLib,"Current");
    ammeter = (importFunction)GetProcAddress(hinstLib,"Ammeter");
    speedometerKPH = (importFunction)GetProcAddress(hinstLib,"SpeedometerKPH");
    ammeterNeedle = (importFunction)GetProcAddress(hinstLib,"AmmeterNeedle");
    tractiveEffort = (importFunction)GetProcAddress(hinstLib,"Tccelerometer");
    if (tractionDial == NULL || accelerometer == NULL || current == NULL || ammeter == NULL || speedometerKPH == NULL || ammeterNeedle == NULL || tractiveEffort == NULL) {  
        printf("ERROR: unable to find DLL function\n");  
        FreeLibrary(hinstLib);  
        system("pause");  
        return 1;  
    }  
    result[0] = tractionDial(true);
    result[1] = accelerometer(true);
    result[2] = current(true);
    result[3] = ammeter(true);
    result[4] = speedometerKPH(true);
    result[5] = ammeterNeedle(true);
    result[6] = tractiveEffort(true);
    printf("tractionDial=%f accelerometer=%f current=%f ammeter=%f speedometerKPH=%f ammeterNeedle=%f tractiveEffort=%f \r",result[0],result[1],result[2],result[3],result[4],result[5],result[6]);    
    }

    return 0;
}