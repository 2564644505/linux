/*************************************************************************
    > File Name: 7-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 08:52:36 AM CST
 ************************************************************************/

#include "ch07.h"

int main(int argc,char **argv,char **env){
    int i;
    for(i=0;i<argc;i++){
        printf("argv[%d]:%s\n",i,argv[i]);
    }
    for(i=0;env[i];i++)
        printf("env[%d]:%s\n",i,env[i]);
    return 0;
   /* if(argc != 3){
        printf("the input is error\n");
        exit(0);
    }
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    printf("the num1 = %d,the num2 = %d,sum=%d\n",num1,num2,num1+num2);
  return 0;*/
}
