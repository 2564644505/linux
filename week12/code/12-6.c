/*************************************************************************
    > File Name: 12-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 07 Dec 2020 08:05:53 AM CST
 ************************************************************************/

#include "ch12.h"

int main(void){
    int fd[2],fd1[2],fd2[2],fd3[3],i;
    char buf[100];
    memset(buf,0,sizeof(buf));
    pid_t k1,k2;
    pipe(fd);
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    k1 = fork();
    if(k1<0){
        perror("fork error!\n");
        exit(-1);
    }
    else if(k1==0){
        close(fd[1]);
        close(fd1[0]);
        sprintf(buf,"%d say hello!",getpid() );
        i=write(fd1[1],buf,sizeof(buf));
        if(i==0){
            printf("child1 write failed!\n");
            exit(0);
        }
        else {
            printf("%d write to pipe: %s\n",getpid(),buf);
            /*memset(buf,0,sizeof(buf));
            i = read(fd[0],buf,sizeof(buf));
            if(i==0){
                printf("child1 read failed!\n");
                exit(0);
            }
            else{
                printf("%d read from pipe :%s\n",getpid(),buf);
            }*/
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
            sleep(1);
            close(fd2[0]);
            close(fd3[1]);
            /*sprintf(buf,"%d say heallo!",getpid());
            i=write(fd2[1],buf,sizeof(buf));
            if(i==0){
                printf("child2 wirte failed!\n");
            }
            else{
                printf("%d write to pipe : %s\n",getpid(),buf);
             }*/
            i=read(fd3[0],buf,sizeof(buf));
            if(i==0){
                  printf("child2 read failed!\n");
            }
            else{
                  printf("%d read from pipe : %s\n",getpid(),buf);
            }

        }
        else{
	        close(fd[0]);
	        close(fd1[1]);
	        close(fd2[1]);
	        close(fd3[0]);
            printf("11111\n");
            wait(NULL);
            memset(buf,0,sizeof(buf));
            i == read(fd1[0],buf,sizeof(buf));
            printf("%s\n",buf);
            if(i !=0){
                write(fd3[1],buf,sizeof(buf));
            }
            memset(buf,0,sizeof(buf));
            i== read(fd2[0],buf,sizeof(buf));
            if(i !=0){
                write(fd[1],buf,sizeof(buf));
            }
            printf("parent\n");
            wait(NULL);
            memset(buf,0,sizeof(buf));
            i == read(fd1[0],buf,sizeof(buf));
            if(i !=0){
                 write(fd3[1],buf,sizeof(buf));
             }
             memset(buf,0,sizeof(buf));
            i== read(fd2[0],buf,sizeof(buf));
            if(i !=0){
              write(fd[1],buf,sizeof(buf));
           }

        }
        exit(0);

    }
  return 0;
}
