/*************************************************************************
    > File Name: 3-1-3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 12 Oct 2020 02:19:51 PM CST
 ************************************************************************/

#include "ch02.h"

int main(void){
  FILE * fp = NULL;
  fp = fdopen(1,"w+");
  fprintf(fp,"%s\n","hello world");
  fclose(fp);
  return 0;
}
