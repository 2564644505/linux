/*************************************************************************
    > File Name: 12-5.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 07 Dec 2020 02:41:05 PM CST
 ************************************************************************/

#include "ch12.h"

int main(void){
    pid_t t1,t2;
    int count=100;
    t1 = vfork();
    if(t1 < 0){
        fprintf(stderr,"child1 faild to vfork!\n");
        exit(-1);
    }
    else if(t1==0){
        excelp("./test1"."./test1","hello","world","2020-12-7",NULL);
        exit(0);
    }
    else{
        t2 = vfork();
        if(t2 < 0){
            fprintf(stderr,"child2 faild to vfork!\n");
            exit(-1);
        }
        else if(t2 == 0){
            exit(0);
        }
        else{
            wait(NULL);
            wait(NULL);
        }
    }
  return 0;
}
