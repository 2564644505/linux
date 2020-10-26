/*************************************************************************
    > File Name: myfun.c
    > Author:何孝林
    > Mail: 2564644505@qq.com 
    > Created Time: Mon 26 Oct 2020 01:58:27 PM CST
 ************************************************************************/

int input(){
    users myUser;
    FILE *fp;
    int res = 0;
    printf("input the id:");
    scanf("%d",&myUser.id);
    printf("input the name:");
    scanf("%s",myUser.name);
    printf("input the htel:");
    scanf("%s",myUser.htel);
    printf("input the tel:");
    scanf("%s",myUser.tel);
    fp = fopen("./user.dat","wa+");
    if(!fp){
        printf("open the file failed!\n");
        return -1;
    }
    res = fwrite(&myUser,sizeof(myUser),1,fp);
   /* res = fwrite(&myUser.id,sizeof(int),1,fp);
    res = fwrite("\t",sizeof("\t"),1,fp);
    res = fwrite(myUser.name,sizeof(myUser.name),1,fp);
    res = fwrite("\t",sizeof("\t"),1,fp);
    res = fwrite(myUser.htel,sizeof(myUser.htel),1,fp);
    res = fwrite("\t",sizeof("\t"),1,fp);
    res = fwrite(myUser.tel,sizeof(myUser.tel),1,fp);
    res = fwrite("\n",sizeof("\n"),1,fp);*/ 
    if(res == 0){
        printf("write to file failed!\n");
        return -1;
    }
    fclose(fp);
}
int output(char *filename,char *mode){
    users myUser[100];
    FILE *fp;
    int res = 0;
    fp = fopen(filename,mode);
      if(!fp){
         printf("open the file failed!\n");
         return -1;
     }
    //while((res =  fread(myUser,sizeof(users),1,fp)) != EOF);
      res =  fread(myUser,sizeof(users),1,fp);
    if(res  == 0){
        printf("read file fialed!\n");
        return -1;
    }
    fclose(fp);
    printf("userid  name    htel    tel\n");
    for(int i = 0;i<res;i++){
        printf("%d\t%s\t%s\t%s\n",myUser[i].id,myUser[i].name,myUser[i].htel,myUser[i].tel);
    }
    return 0;
}
