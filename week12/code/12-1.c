/*************************************************************************
    > File Name: 12-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 07 Dec 2020 08:05:53 AM CST
 ************************************************************************/

#include "ch12.h"

int main(void){
    int fd[2],i;
    char buf[100];
    memset(buf,0,sizeof(buf));
    pid_t k;
    pipe(fd);
    k = fork();
    if(k<0){
        perror("fork error!\n");
        exit(-1);
    }
    else if(k==0){
        sleep(3);
        close(fd[1]);
        i=read(fd[0],buf,sizeof(buf));
        if(i==0){
            printf("child read failed!\n");
            exit(0);
        }
        else {
            printf("read from pipe : %s\n",buf);
            exit(1);
        }
    }
    else{
        close(fd[0]);
        sprintf(buf,"%d say heallo to %d!",getpid(),k);
        i=write(fd[1],buf,sizeof(buf));
        if(i==0){
            printf("parent wirte failed!\n");
        }
        else{
            printf("write to pipe : %s\n",buf);
        }
        wait(NULL);
        exit(0);

    }
  return 0;
}
