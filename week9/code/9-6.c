/*************************************************************************
    > File Name: 9-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 16 Nov 2020 08:23:25 AM CST
 ************************************************************************/

#include "ch09.h"

int main(void){
    int fd_out;
    char buf[1024];
    pid_t pid1,pid2;
    memset(buf,0,1024);
    fd_out = open(OUTFILE,O_WRONLY|O_CREAT|O_TRUNC,MODE);
    if(fd_out < 0){
        fprintf(stderr,"failed to open %s,reason(%s)",OUTFILE,strerror(errno));
        return 1;
    }
    pid1 = fork();
    if(pid1 < 0){
        fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
        return 1;
    }
    else if(pid1 == 0){
        pid_t pid11,pid12;
        pid11 = fork();
        if(pid11 < 0){
            fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
            return 1;
        }
        else if(pid11 == 0){
            sprintf(buf,"%d\t",getpid());
            time_t t = time(NULL);
            char* tt = ctime(&t);
            strcat(buf,tt);
            write(fd_out,buf,strlen(buf));
            memset(buf,0,1024);

        }
        else{
            pid12 = fork();
            if(pid12 < 0){
                fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
                return 1;
            }
            else if(pid12 == 0){
                sprintf(buf,"%d\t",getpid());
                time_t t = time(NULL);
                char* tt = ctime(&t);
                strcat(buf,tt);
                write(fd_out,buf,strlen(buf));
                memset(buf,0,1024);

            }
            else{

                wait(NULL);
                wait(NULL);
                sprintf(buf,"%d\t",getpid());
                time_t t = time(NULL);
                char* tt = ctime(&t);
                strcat(buf,tt);
                write(fd_out,buf,strlen(buf));
                memset(buf,0,1024);

            }
        }
       /* while(read(fd_in,buf,2) > 0){
            printf("%d: %s",getpid(),buf);
            sprintf(buf,"%d Hello world!\n",getpid());
            write(fd_out,buf,strlen(buf));
            sleep(1);
            memset(buf,0,1024);
        }*/
    }
    else{
        pid2 = fork();
        if(pid2 < 0){
            fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
            return 1;
        }
        else if(pid2 == 0){
            pid_t pid21,pid22;
            pid21 = fork();
            if(pid21 < 0){
                fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
                return 1;
            }
            else if(pid21 == 0){
                sprintf(buf,"%d\t",getpid());
                time_t t = time(NULL);
                char* tt = ctime(&t);
                strcat(buf,tt);
                write(fd_out,buf,strlen(buf));
                memset(buf,0,1024);

            }
            else{
                pid22 = fork();
                if(pid22 < 0){
                    fprintf(stderr,"failed to fork,reason(%s)\n",strerror(errno));
                    return 1;
                }
                else if(pid22 == 0){
                sprintf(buf,"%d\t",getpid());
                time_t t = time(NULL);
                char* tt = ctime(&t);
                strcat(buf,tt);
                write(fd_out,buf,strlen(buf));
                memset(buf,0,1024);
                }
                else{
                    wait(NULL);
                    wait(NULL);
                    sprintf(buf,"%d\t",getpid());
                    time_t t = time(NULL);
                    char* tt = ctime(&t);
                    strcat(buf,tt);
                    write(fd_out,buf,strlen(buf));
                    memset(buf,0,1024);
                }
            }
        }
        else{
            wait(NULL);
            wait(NULL);
            sprintf(buf,"%d\t",getpid());
            time_t t = time(NULL);
            char* tt = ctime(&t);
            strcat(buf,tt); 
            write(fd_out,buf,strlen(buf));
            memset(buf,0,1024);

        }
    }
  return 0;
}
