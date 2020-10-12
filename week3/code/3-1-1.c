/*************************************************************************
    > File Name: 3-1-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 12 Oct 2020 08:37:39 AM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
int main(void){
  int fd = open("./test.txt",O_CREAT,0644,"test");
   printf("file descriptor = %d \n",fd);
   close(fd);
   return 0;
 }

