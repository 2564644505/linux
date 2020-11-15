/*************************************************************************
    > File Name: 8-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 09 Nov 2020 08:01:56 AM CST
 ************************************************************************/

#include "ch08.h"
int main(void){
    int *pt = NULL;
    int i = 0;
    do{
         free(pt);
         i++;
         pt = (int*)malloc(i*1024*sizeof(int));
         
    }while(pt != NULL);
    printf("system allocate %ikb\n",i*4);
  return 0;
}
