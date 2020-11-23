/*************************************************************************
    > File Name: 10-4.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:36:15 AM CST
 ************************************************************************/
/* exit() 函数会执行注册表和清空缓冲区，_exit()函数不会执行注册表和清空缓存区*/
#include "ch10.h"
void foo(){
    fprintf(stderr,"foo says bye.\n");
}
void bar(){
    fprintf(stderr,"bar says bye.\n");
}
int main(int argc,char **argv){
    atexit(foo);
    atexit(bar);
    fprintf(stdout,"Oops ~~~ forgot a newline!");
    sleep(2);
    if(argc > 1 && strcmp(argv[1],"exit") == 0)
        exit(0);
    if(argc > 1 && strcmp(argv[1],"_exit") == 0)
        _exit(0);
  return 0;
}
