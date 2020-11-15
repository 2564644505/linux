/*************************************************************************
    > File Name: 8-6.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 09 Nov 2020 02:33:38 PM CST
 ************************************************************************/

#include "ch08.h"

int main(void){
    pid_t p1,f1;
    p1 = getpid();
    f1 = getppid();
    printf("cuurent process pid = %d,ppid = %d\n",p1,f1);
    sleep(10);
  return 0;
}
