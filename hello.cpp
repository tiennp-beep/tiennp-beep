#include <stdio.h>
#include <windows.h>

DWORD func1(LPVOID lpThread){
    while(true){
        printf("other function %s\n", (char*)lpThread);
        Sleep(500);
    }
}

int main(){

    LPDWORD lpThreadId = 0;
    HANDLE thread1 = CreateThread(NULL, 256,
                    func1, (LPVOID)"Peo", 0, lpThreadId);

    while(true){
        printf("main\n");
        Sleep(1000);
    }
    return 0;
}