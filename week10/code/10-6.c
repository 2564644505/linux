/*************************************************************************
    > File Name: 10-6.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 09:14:39 AM CST
 ************************************************************************/

#include "ch10.h"

int main(void){
    int r1,r2,r3,r4,r5;
    r1 = fork();
    if(r1 == 0){
        printf("child 1:pid = %d,ppid=%d\n",getpid(),getppid());
        exit(0);
    }
    if(r1>0){
        r2 = fork();
        if(r2 == 0){
            printf("child 2:pid = %d,ppid=%d\n",getpid(),getppid());
            exit(0);
        }
        if(r2 > 0){
            wait(NULL);
            wait(NULL);
            printf("parent :pid =%d,r1=%d,r2=%d\n",getpid(),r1,r2);
        }
    }
  return 0;
}
