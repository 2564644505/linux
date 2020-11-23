/*************************************************************************
    > File Name: 10-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:13:11 AM CST
 ************************************************************************/

#include "ch10.h"

int main(void){
    char *argv[]={"./test","hello","world",NULL};
    printf("10-2 : pid = %d,ppid = %d\n",getpid(),getppid());
    int  i = execve("./test",argv,NULL);
    /*int i = execle("./test","./test","hello","world",NULL,NULL);*/
    if(i == -1){
        perror("execve failed!\n");
        exit(1);
    }
    printf("after calling\n");
  return 0;
}
