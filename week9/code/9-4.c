/*************************************************************************
    > File Name: 9-4.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 16 Nov 2020 01:59:06 PM CST
 ************************************************************************/

#include "./ch09.h"
char *env_init[]={"USER=stu","PATH=/tmp",NULL};
int main(void){
    char *args[] = {"./test","hello","world!\n",NULL};
    if(execve("./test",args,env_init) == -1){
        perror("execve!\n");
        exit(EXIT_FAILURE);
    }
    puts("Never geet here\n");
    exit(EXIT_SUCCESS);
  return 0;
}
