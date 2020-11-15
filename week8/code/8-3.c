/*************************************************************************
    > File Name: 8-3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 09 Nov 2020 09:00:50 AM CST
 ************************************************************************/

#include "ch08.h"
static jmp_buf g_stack_env;
static void func1(void);
static void func2(void);

int main(void){
    if(setjmp(g_stack_env) == 0){
        printf("Normal flow!\n");
        func1();
    }else{
        printf("Longjump flow!\n");

    }
    printf("Leave mian\n");
  return 0;
}
static void func1(void){
    printf("Enter func1!\n");
    func2();
}
static void func2(void){
    printf("Enter func2!\n");
    longjmp(g_stack_env,1);
    printf("Leave func2!\n");
}
