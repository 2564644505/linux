/*************************************************************************
    > File Name: 2-5.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 28 Sep 2020 03:06:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <errno.h>
//#include <unstd.h>
#include <sys/utsname.h>
#define MAXHOSTNAMELEN 1000000

int main(void){
  struct utsname uts;
  char hostname[MAXHOSTNAMELEN];
  size_t size = MAXHOSTNAMELEN;
  if(gethostname(hostname,size)!=0){
  perror("Could not get hostname");
  exit(1);
  }
  printf("hostname=%s\n",hostname);
  if(uname(&uts) < 0){
      perror("Could not get host information");
      exit(1);  
  }  
  printf("System is %s on %s hardware\n",uts.sysname,uts.machine);
  printf("Nodename is %s\n",uts.nodename);
  printf("Release is %s,Version is %s\n",uts.release,uts.version);

  exit(0);
}
