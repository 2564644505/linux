/*************************************************************************
    > File Name: 10-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:00:32 AM CST
 ************************************************************************/

#include "ch11.h"

int main(void){
    printf("10-8 : pid = %d,ppid = %d\n",getpid(),getppid());
    /*system("./test hello world 2020 11 23");*/
    pid_t r1 = 99;
    r1 = fork();
    if(r1 < 0){
        perror("fork failed!\n");
        exit(-1);
    }
    else if(r1 == 0){
        int i = -1;
        i = execle("./test","./test","hello","world",NULL,NULL);
        if(i == -1){
            perror("execle failed!\n");
            exit(1);
        }
        exit(88);
    }else{
        int t1,s1;
        t1 = wait(&s1);
        /*获得进程的终止信号，如果正常退出，返回ture*/
        if(WIFEXITED(s1)){
            printf("t1 = %d,s1=%d\n",t1,WEXITSTATUS(s1));
        }else{
            printf("child process stoped siganl %d!\n",WTERMSIG(s1));
        }
        if(t1 == r1&& WEXITSTATUS(s1))
            printf("after calling\n");
    }
  return 0;
}
