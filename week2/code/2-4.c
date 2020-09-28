/*************************************************************************
    > File Name: 2-4.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 28 Sep 2020 02:52:07 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void){
  int fd,i;
  char buf[100];
  fd = open("./test.data",O_CREAT|O_WRONLY,0644);
  for(i=0;i<100;i++)
      buf[i] = i;
  printf("process %d:before wirting i=%d\nfile description=%d\n",getpid(),i,fd);
  i = write(fd,buf,sizeof(buf));
  printf("after i=%d\n",i);
  sleep(500);
  return 0;
}
