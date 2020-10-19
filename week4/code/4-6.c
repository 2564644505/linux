/*************************************************************************
    > File Name: 4-6.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 02:59:28 PM CST
 ************************************************************************/

#include "ch03.h"

int main(void){
  int fd;
  if((fd = open("myoutput",O_WRONLY|O_CREAT,0644)) == -1)
      err_exit("myoutput");
  if(dup2(fd,STDOUT_FILENO) == -1)
      err_exit("redirect standard output fialed");
  printf("this is atest program for redirect\n");
  close(fd);
  return 0;
}
