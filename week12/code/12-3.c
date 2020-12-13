/*************************************************************************
    > File Name: 12-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 07 Dec 2020 08:05:53 AM CST
 ************************************************************************/

#include "ch12.h"

int main(void){
    int fd[2],fd1[2],i;
    char buf[100];
    memset(buf,0,sizeof(buf));
    pid_t k;
    pipe(fd);
    pipe(fd1);
    k = fork();
    if(k<0){
        perror("fork error!\n");
        exit(-1);
    }
    else if(k==0){
        sleep(1);
        close(fd[1]);
        close(fd1[0]);
        close(0);
        close(1);
        dup(fd[0]);
        dup(fd1[1]);
        execlp("./test","./test","hello",NULL);
    }
    else{
        close(fd[0]);
        close(fd1[1]);
        sprintf(buf,"%d say heallo to %d!",getpid(),k);
        i=write(fd[1],buf,sizeof(buf));
        if(i==0){
            printf("parent wirte failed!\n");
        }
        else{
            printf("parent=%d write to pipe : %s\n",getpid(),buf);
        }
        wait(NULL);
        memset(buf,0,sizeof(buf));
        i=read(fd1[0],buf,sizeof(buf));
        if(i==0){
            printf("parent read failed!\n");
        }
        else{
            printf("parent=%d read from pipe: %s\n",getpid(),buf);
        }

        exit(0);

    }
  return 0;
}
