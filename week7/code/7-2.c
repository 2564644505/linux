/*************************************************************************
    > File Name: 7-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 08:46:37 AM CST
 ************************************************************************/

#include "ch07.h"
static void __attribute__ ((destructor))after_main(void)
{
    printf("---------After Main--------------\n");
}
int main(void){
    printf("-------Main Function is Running!------\n");
  return 0;
}
