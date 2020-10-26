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
struct user{
int id;
char name[8];
char htel[12];
char tel[12];
};
typedef struct user users;
int input(char *filename,char *mode,users user[]);
int output(char *filename,char *mode,users user[]);
