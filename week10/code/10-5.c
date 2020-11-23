/*************************************************************************
    > File Name: 10-5.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 23 Nov 2020 08:57:40 AM CST
 ************************************************************************/
/*验证僵死进程即子进程任务完成，除了pcb未被回收，其他支援都被回收*/
#include "ch10.h"

int main(void){
    pid_t pid;
    pid = fork();
    if(pid < 0){
        perror("error fork!");
        exit(1);
    }else if(pid == 0){
        exit(0);
    }else{
        sleep(300);
        wait(NULL);
    }
  return 0;
}
