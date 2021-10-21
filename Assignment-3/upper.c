#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    int fd;
    for(int i=0;i<argc;i++){
        printf("argv[%d] = %s\n",i,argv[i]);
    }
    sscanf(argv[1],"%d",&fd);
    char buffer[100];
    memset(buffer,'\0',sizeof(buffer));
    read(fd,buffer,sizeof(buffer));
    FILE *fp = fopen(buffer,"r+");
    FILE *fpp = fopen("temp.txt","w");
    char buff[255],ch;
    while((ch = fgetc(fp)) != EOF)
    {
        if(isalpha(ch)){
            ch = toupper(ch);
        }
        fputc(ch,fpp);
    }
    fclose(fp);
    fclose(fpp);
    fpp = fopen("temp.txt","r");
    fp = fopen(buffer,"w");
    while((ch=fgetc(fpp))!=EOF){
        fputc(ch,fp);
    }
    fclose(fp);
    fclose(fpp);
    return 0;
}