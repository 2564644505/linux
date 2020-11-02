/*************************************************************************
    > File Name: 3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 19 Oct 2020 05:38:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <float.h>
int main(void){
  unsigned int a = 1;
  int *p = NULL;
  a = a << sizeof(int)*8 - 1;
  float f = 111.3456f;
  p = (int *)&f;
  double d = 111.34567d;
  printf("%u =  %XH\n",a,a);
  printf("%G = %x\n",f,*p);
  p = (int *)&d;
  printf("%G = %x\n",d,*p);
  /*printf("float类型的最小值=%e\n",FLT_MIN);
  printf("double类型的最大值=%e\n",DBL_MAX);
  printf("double类型的最小值=%e\n",DBL_MIN);*/   
  return 0;
}
