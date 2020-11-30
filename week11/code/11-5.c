/*************************************************************************
    > File Name: 10-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:00:32 AM CST
 ************************************************************************/

#include "ch11.h"
void showTime(int pid,int fd_out,char *buf){
    time_t t = time(NULL);
    char* tt = ctime(&t);
    sprintf(buf,"%d\t",pid);
    strcat(buf,tt);
    write(fd_out,buf,strlen(buf));
    memset(buf,0,1024);

}
void show(char *buf){
    FILE* fd_in;
    int count;
    fd_in =  fopen(INFILE,"r");
    int i = 0;
    while((count=fscanf(fd_in,"%s ",buf))!=EOF){
        printf("%s ",buf);
        i++;
        if(i==6){
            printf("\n");
            i=0;
        }
    }
}
int main(void){
    int fd_out;
    char buf[1024];
    pid_t pid1,pid2;
    memset(buf,0,1024);
    fd_out = open(OUTFILE,O_WRONLY|O_CREAT|O_TRUNC,MODE);
    pid_t r1,r2,r3,r4;
    r1 = fork();
    if(r1 < 0){
        perror("fork failed!\n");
        exit(-1);
    }
    else if(r1 == 0){
        r3 = fork();
        if(r3 < 0){
            perror("fork failed!\n");
            exit(-1);
        }
        if(r3 == 0){
            showTime(getpid(),fd_out,buf);
            exit(0);
        }
        else{
            wait(NULL);
            showTime(getpid(),fd_out,buf);
            exit(88);
        }
    }
    else{
         r2 = fork();
         if(r2 < 0){
            perror("fork failed!\n");
            exit(-1);
        }
        else if(r2 == 0){
            r4 = fork();
            if(r4 < 0){
                perror("fork failed!\n");
                exit(-1);
            }
            if(r4 == 0){
                showTime(getpid(),fd_out,buf);
                exit(0);
            }
            else{
                wait(NULL);
                showTime(getpid(),fd_out,buf);
                exit(88);
            }
         }
        wait(NULL);
        wait(NULL);
        showTime(getpid(),fd_out,buf);
        show(buf);
    }
  return 0;
}
