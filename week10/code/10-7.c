/*************************************************************************
    > File Name: 10-6.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 09:14:39 AM CST
 ************************************************************************/

#include "ch10.h"

int main(void){
    int r1,r2,r3,r4,r5;
    r1 = fork();
    if(r1 == 0){
        printf("child 1:pid = %d,ppid=%d\n",getpid(),getppid());
        exit(0);
    }
    if(r1>0){
        r2 = fork();
        if(r2 == 0){
            printf("child 2:pid = %d,ppid=%d\n",getpid(),getppid());
            exit(0);
        }
        if(r2 > 0){
            r3 = fork();
            if(r3 == 0){
                printf("child 3:pid = %d,ppid = %d\n",getpid(),getppid());
                r4 = fork();
                if(r4 == 0){
                    printf("child 31:pid = %d,ppid = %d\n",getpid(),getppid());
                    exit(0);
                }
                if(r4 > 0){
                    r5 = fork();
                    if(r5 == 0){
                        printf("child 32:pid = %d,ppid = %d\n",getpid(),getppid());
                        exit(0);
                    }
                    if(r5 > 0){
                        wait(NULL);
                        wait(NULL);
                        printf("r3:pid=%d r4=%d,r5=%d\n",getpid(),r4,r5);

                    }
                }
                exit(0);
            }
            if(r3 > 0){
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("parent :pid =%d,r1=%d,r2=%d,r3=%d\n",getpid(),r1,r2,r3);

            }
        }
    }
  return 0;
}
