/*************************************************************************
    > File Name: 5-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 26 Oct 2020 08:20:43 AM CST
 ************************************************************************/

#include <stdio.h>

int main(void){
   setbuf(stdout,NULL);//sixth way
 //setvbuf(stdout,NULL,_IONBF,0);//fith way
  //printf("hello world\n");//first way
  printf("hello world");
 /* for(int i = 0;i< 1024;i++)
    printf(" ");*/ // third way
  //fflush(stdout);second way
  //fclose(stdout);forth way
  while(1);
  return 0;
}
