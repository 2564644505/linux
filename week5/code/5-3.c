/*************************************************************************
    > File Name: 5-3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 26 Oct 2020 09:11:29 AM CST
 ************************************************************************/

#include "ch05.h"

int main(void){
  char buf[20];
  int ret;
  FILE *fp = fopen("./tmp.txt","w+");
  if(!fp){
    printf("Fail to open file!\n");
    exit(-1);
  }
  ret = fwrite("123",sizeof("123"),1,fp);
  printf("We write %d byte\n",ret);
  memset(buf,0,sizeof(buf));
  ret = fread(buf,1,1,fp);
  printf("We read %s,ret is %d\n",buf,ret);
  fwrite("456",sizeof("456"),1,fp);
  fclose(fp);
  return 0;
}
