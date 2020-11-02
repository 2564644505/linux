/*************************************************************************
    > File Name: 7-8-1.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 02 Nov 2020 02:54:53 PM CST
 ************************************************************************/

#include "ch07.h"
int main(void){
    void *handle_dll =NULL;

    void(* dl_call)();
    handle_dll = dlopen("./libdlib.so",RTLD_LAZY);
    if(handle_dll == NULL){
        printf("libdlib.so not found!\n");
        exit(0);
    }
    dl_call = dlsym(handle_dll,"dynamic_lib_call");
    dl_call();
    dlclose(handle_dll);
    handle_dll = NULL;
  return 0;
}
