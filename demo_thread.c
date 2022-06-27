#include <stdio.h>
#include <windows.h>
#include <pthread.h>


void* func1(void* ptr){

    while(1){
        printf("Return ptr %s\n", (char*)ptr);
        Sleep(500);
    }
}

void main(){

    pthread_t thread1;
    int createThread1 = pthread_create(&thread1, NULL, func1, "Peo");
    printf("Create thread %d\n", createThread1); // Return 0 when ok

    while(1){
        printf("main\n");
        Sleep(1000);
    }
}