/*************************************************************************
    > File Name: test1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 02:48:52 PM CST
 ************************************************************************/

#include "ch10.h"

int main(void){
    int r1=99,r2=99;
    r1 = fork();
    if(r1<0){
        perror("fork failed!\n");
        exit(0);
    }
    else if(r1 == 0){
        printf("child 1:pid=%d,ppid=%d\n",getpid(),getppid());
        exit(88);
    }
    else{
        r2 = fork();
        if (r2 < 0){
            perror("fork failed!\n");
            exit(0);
        }
        else if(r2 == 0){
            printf("child 2:pid=%d,ppid=%d\n",getpid(),getppid());
            exit(99);
        }else{
            int t1,t2,s1,s2;
            t1 = wait(&s1);
            t2 = wait(&s2);
            printf("parent : t1=%d,t2=%d,s1=%d,s2=%d\n",t1,t2,WEXITSTATUS(s1),WEXITSTATUS(s2));
            printf("parent : pid = %d,ppid=%d,r1=%d,r2=%d\n",getpid(),getppid(),r1,r2);
            exit(0);
        }
    }
  return 0;
}
