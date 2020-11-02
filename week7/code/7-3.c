/*************************************************************************
    > File Name: 7-3.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 09:13:06 AM CST
 ************************************************************************/

#include "ch07.h"

int main(int argc,char ** argv){
    int index,c,iflg = 0,fflg = 0,sflg = 0;
    char *fvalue = NULL;
    while((c = getopt(argc,argv,":f:is"))!= -1)
        switch(c){
            case 'f':
                fflg = 1,fvalue=optarg;
                break;
            case 'i':
                iflg=1;
                break;
            case 's':
                sflg = 1;
                break;
            case '?':
                printf("Unkown option '-%c'\n",optopt);
                break;
            case ':':
                printf("'-%c' missing option argument\n",optopt);
                break;
            case 1:
                printf("return value = %d,optarg is : %s\n",c,optarg);
                break;
            default:
                printf("Unkown return vaulue:%d\n",c);
        }
    printf("fflg=%d,fvalue=%s,iflg=%d.sflg=%d\n",fflg,fvalue,iflg,sflg);
    for(index = optind;index < argc;index++){
        printf("Non-optin argument:%s\n",argv[index]);
    }
  return 0;
}
