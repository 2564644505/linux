/*************************************************************************
    > File Name: 3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 05:38:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <float.h>
int main(void){
  int a = 1;
  a = a << sizeof(int)*8 - 1;
  printf("int类型的最大值=%d\n",-a-1);
  printf("int类型的最小值=%d\n",a);
  printf("float类型的最大值=%e\n",FLT_MAX);
  printf("float类型的最小值=%e\n",FLT_MIN);
  printf("double类型的最大值=%e\n",DBL_MAX);
  printf("double类型的最小值=%e\n",DBL_MIN);   
  return 0;
}
