/*************************************************************************
    > File Name: 7-6.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 02:28:51 PM CST
 ************************************************************************/

#include "ch07.h"

int main(void){
    extern char **environ;
    printf("%s\n",getenv("PATH"));
        for(int i=0;environ[i]!=NULL;i++)
            printf("evn[%d] : %s\n",i,environ[i]);
  return 0;
}
