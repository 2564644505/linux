/*************************************************************************
    > File Name: 7-4.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 01:53:58 PM CST
 ************************************************************************/

#include "ch07.h"
static void __attribute__ ((destructor))After_Main(){
    printf("--------AfterMain------\n");
}
void callback1(){
    printf("----------CallBack1--------\n");
}
void callback2(){
    printf("----------CallBack2--------\n");
}
void callback3(){
    printf("----------CallBack3--------\n");
}
int main(void){

    atexit(callback1);
    atexit(callback2);
    atexit(callback3);
    while(1){
        printf("-----running now -------\n");
        sleep(1);
    }
    printf("----------Program finished---------\n");
  return 0;
}

