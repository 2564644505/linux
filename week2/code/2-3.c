/*************************************************************************
    > File Name: 2-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 28 Sep 2020 02:11:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(void){

  int ret;
  ret = write(0,"hello world!\n",13);
  printf("ret=%d\n",ret);
  sleep(500);
  return 0;
}
