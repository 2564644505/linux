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
    pid_t k1,k2;
    pipe(fd);
    pipe(fd1);
    k1 = fork();
    if(k1<0){
        perror("fork error!\n");
        exit(-1);
    }
    else if(k1==0){
        close(fd[1]);
        close(fd1[0]);
        i=read(fd[0],buf,sizeof(buf));
        if(i==0){
            printf("child1 read failed!\n");
            exit(0);
        }
        else {
            printf("%d read from pipe : %s\n",getpid(),buf);
            int count = strlen(buf);
            memset(buf,0,sizeof(buf));
            sprintf(buf,"%d recive %d bytes!",getpid(),count);
            i=write(fd1[1],buf,sizeof(buf));
            if(i==0){
                printf("child1 write failed!\n");
                exit(0);
            }
            else{
                printf("%d write to pipe :%s\n",getpid(),buf);
            }
            exit(1);
        }
    }
    else{
        k2 = fork();
        if(k2< 0){
            perror("fork error!\n");
            exit(-1);
        }
        else if(k2 == 0){
            close(fd[0]);
            close(fd1[1]);
            sprintf(buf,"%d say heallo!",getpid());
            i=write(fd[1],buf,sizeof(buf));
            if(i==0){
                printf("child2 wirte failed!\n");
            }
            else{
                printf("%d write to pipe : %s\n",getpid(),buf);
             }
            i=read(fd1[0],buf,sizeof(buf));
            if(i==0){
                  printf("child2 read failed!\n");
            }
            else{
                  printf("%d read from pipe : %s\n",getpid(),buf);
            }

        }
        else{
	close(fd[0]);
	close(fd[1]);
	close(fd1[0]);
	close(fd1[1]);
        wait(NULL);
        wait(NULL);
        }
        exit(0);

    }
  return 0;
}
