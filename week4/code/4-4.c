/*************************************************************************
    > File Name: 4-4.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 01:57:40 PM CST
 ************************************************************************/

#include "ch03.h"

int main(void){
  int fd1,fd2;
  char buf[6];
  memset(buf,0,6);
  fd1 = open("./file2.hole",O_RDONLY);
  fd2 = open("./file2.hole",O_RDONLY);
  printf("fd1=%d,fd2=%d\n",fd1,fd2);
  lseek(fd1,4,SEEK_SET);
  read(fd2,buf,5);
  printf("fd2 is %s\n",buf);
  return 0;
}
