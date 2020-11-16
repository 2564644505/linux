/*************************************************************************
    > File Name: 9-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 16 Nov 2020 08:05:46 AM CST
 ************************************************************************/

#include "./ch09.h"
int g = 9;
int main(void){
    pid_t pid;
    int l = 99;
    pid = vfork();
    if(pid < 0){
        perror("Fork failed!\n");
        exit(-1);
    }
    else if(pid == 0){
        printf("child : ppid=%d ,pid=%d\n",getppid(),getpid());
        printf("child : init g=%d,l=%d\n",g,l);
        g--;
        l++;
        printf("child : g = %d,l = %d\n",g,l);
        //return 0;
        _exit(1);
    }
    else{
        wait(NULL);
        printf("parent : child pid = %d,pid=%d\n",pid,getpid());
        printf("parent : init g=%d,l=%d\n",g,l);
        g++,l--;
        printf("parent : g = %d,l = %d\n",g,l);
        return 0;
    }
  return 0;
}
