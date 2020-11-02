/*************************************************************************
    > File Name: 3-1-2.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 12 Oct 2020 08:46:31 AM CST
 ************************************************************************/

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <dlfcn.h>
void err_exit(char *s){
    printf("Usage:%s is failed!\n",s);
    exit(0);
}
