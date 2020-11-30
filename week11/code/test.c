/*************************************************************************
    > File Name: test.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 07:58:22 AM CST
 ************************************************************************/

#include "ch11.h"

int main(int argc,char **argv){
    int i;
    printf("test : pid = %d,ppid = %d\n",getpid(),getppid());
    for(i = 0;i < argc; i++){
        printf("argv[%d] : %s\n",i,argv[i]);
    }
    /*sleep(10);*/
  return 10;
}
