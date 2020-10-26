/*************************************************************************
    > File Name: 5-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 26 Oct 2020 08:49:33 AM CST
 ************************************************************************/

#include "ch05.h"
int y_or_ques(char str[]){
    printf("%s",str);
    int a;
    while(a!=1 && a!=0){
        scanf("%d",&a);
    }
    return a;
}
int main(void){
  int answer;
  printf("1:This is a buffer test program.");
  fflush(stdout);
  fprintf(stderr,"2: --test message\n");
  answer = y_or_ques("3: Hello,Are you a student?");
  if(answer == 1){
    printf("4:hope you have high score.");
  }else{
    printf("4:Hope you hava good salary.");
  }
  fflush(stdout);
  fprintf(stderr,"5:bye!\n");
  return 0;
}
