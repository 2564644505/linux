/*************************************************************************
    > File Name: 3-1-3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 12 Oct 2020 02:19:51 PM CST
 ************************************************************************/

#include "ch02.h"

int main(void){
  int fd = 0;
  fd = open("./test.txt",O_RDONLY);
  printf("fd = %d\n",fd);
  close(fd);
  return 0;
}
