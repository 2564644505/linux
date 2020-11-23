/*************************************************************************
    > File Name: 10-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:00:32 AM CST
 ************************************************************************/

#include "ch10.h"

int main(void){
    printf("10-1 : pid = %d,ppid = %d\n",getpid(),getppid());
    system("./test hello world 2020 11 23");
    printf("after calling\n");
  return 0;
}
