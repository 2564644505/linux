/*************************************************************************
    > File Name: 8-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 09 Nov 2020 08:01:56 AM CST
 ************************************************************************/

#include "ch08.h"
static int x1 = 0,x2;
int y;
int main(void){
    int x3 = 0xffffffff,x4;
    static int x5 = 0x11111111;
    int a[10];
    int *pt = (int*)malloc(65536*65536*65536*65536*sizeof(int));
    printf("address of y : %x\n",&y);
    printf("address of x1 : %x ,x2 : %x\n",&x1,&x2);
    printf("address of x3 : %x ,x4 : %x\n",&x3,&x4);
    printf("address of x5 : %x ,a  : %x\n",&x5,a);
    printf("address of pt : %x ,&pt: %x\n\n",pt,&pt);
  return 0;
}
