/*************************************************************************
    > File Name: 10-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:00:32 AM CST
 ************************************************************************/

#include "ch11.h"

int main(void){
    printf("parent : pid = %d,ppid = %d\n",getpid(),getppid());
    pid_t r1 = 99;
    r1 = fork();
    if(r1 < 0){
        perror("fork failed!\n");
        exit(-1);
    }
    else if(r1 == 0){
        printf("child1:pid = %d,ppid = %d\n",getpid(),getppid());
        exit(88);
    }else{
         pid_t r2 = 99,r3;
         r2 = fork();
        if(r2 < 0){
            perror("fork failed!\n");
            exit(-1);
        }
        else if(r2 == 0){
             printf("child2:pid = %d,ppid = %d\n",getpid(),getppid());
             exit(99);
         }
        else{
                r3 = fork();
                 if(r3 < 0){
                  perror("fork failed!\n");
                  exit(-1);
                 }
                 else if(r3 == 0){
                     printf("child3:pid = %d,ppid = %d\n",getpid(),getppid()); 
                     while(1)
                        /*printf("hello\n")*/;
                    exit(100);
                 }

        }
        int t1=0,s1,t2=0,s2,t3=0,s3;
        t1 = waitpid(r1,&s1,0);
        if(WIFEXITED(s1)){
            printf("child1 : t1 = %d,s1=%d\n",t1,WEXITSTATUS(s1));
        }
        else{
            printf("child1 process stoped code %d!\n",WTERMSIG(s1));
        }

        t2 = waitpid(r2,&s2,0);
        if(WIFEXITED(s2)){
            printf("child2 : t2 = %d,s2=%d\n",t2,WEXITSTATUS(s2));
        }
        else{
            printf("child2 process stoped code %d!\n",WTERMSIG(s1));
        }

        t3 = waitpid(r3,&s3,WNOHANG);
        /*获得进程的终止信号，如果正常退出，返回ture*/
        if(WIFEXITED(s3)){
            printf("t3 = %d,s3=%d\n",t3,WEXITSTATUS(s3));
        }
        else{
            printf("child3 process stoped code %d!\n",WTERMSIG(s1));
        }
        printf("parent : process end!\n");
    }
  return 0;
}
