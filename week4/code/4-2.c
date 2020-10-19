/*************************************************************************
    > File Name: 4-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 09:14:49 AM CST
 ************************************************************************/

#include "ch03.h"

int main(void){
  char buf1[] = "abcdefghij";
  char buf2[] = "ABCDEFGHIJ";
  int fd;
  if((fd = open("file.hole",O_WRONLY|O_CREAT,0644))<0){
    printf("create error\n");
    exit(1);
  }
  if(write(fd,buf1,10) != 10){
    printf("buf1 write error\n");
    exit(1);
  }
  if(lseek(fd,40,SEEK_SET) == -1){
   printf("lseek error\n");
   exit(1);
  }
  if(write(fd,buf2,10) != 10){
  printf("buf write error\n");
  exit(1);
  }

  return 0;
}
