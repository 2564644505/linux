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
int main(void){
  FILE *fp = fopen("./ftest1.txt","w");
  char buf[80];
  memset(buf,0,sizeof(buf));
  fgets(buf,sizeof(buf),stdin);
  //fputs(buf,fp);
  time_t nowtime;
  nowtime = time(NULL);
  int count = fwrite(buf,sizeof(buf),1,fp);

  printf("time = %ld,number = %d\n",time(NULL)-nowtime,count );
  nowtime = time(NULL);
  count = fwrite(buf,sizeof(buf)/8,8,fp);
  printf("time = %ld,number = %d\n",time(NULL)-nowtime,count);
  fclose(fp);
  return 0;
}
