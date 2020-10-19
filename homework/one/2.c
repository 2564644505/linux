/*************************************************************************
    > File Name: 2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 05:26:17 PM CST
 ************************************************************************/

#include "ch.h"
struct {
  char buf[10];
  char other[20];
}buf;
int main(void){
  memset(buf.buf,0,sizeof(buf.buf));
  memset(buf.other,0,sizeof(buf.other)); 
  gets(buf.buf);
  printf("buf.buf=%s\n",buf.buf);
  printf("buf.other = %s\n",buf.other);
  return 0;
}
