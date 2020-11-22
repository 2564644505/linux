/*************************************************************************
    > File Name: test.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 16 Nov 2020 02:03:51 PM CST
 ************************************************************************/

#include "ch09.h"

int main(int argc,char *argv[]){
    int i;
    extern char **environ;
    char **env = environ;
    for(i = 1;i < argc;i++){
        printf("%s",argv[i]);
    }
    while(*env){
        printf("%s\n",*env);
        env++;
    }
  return 0;
}
