#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    int k=0,ptr;
    int piperetn;
    int fileDes[2];
    char fname[100];
    printf("Enter the name of the File:\n");
    scanf("%s",fname);
    piperetn=pipe(fileDes);
    char ch[100];
    printf("filedes[0] = %d\nfiledes[1] = %d\n",fileDes[0],fileDes[1]);
    while(k<1||k>2){
        printf("Press 1 to convert the file to UPPER Case\nPress 2 to convert the file to LOWER case\n");
        scanf("%d",&k);
    }
    pid_t PID;
    PID = fork();
    if(PID==0){
        printf("Inside child process PID: %d",getppid());
        sprintf(ch,"%d\n",fileDes[0]);
        if(k==1){
            execl("./LOWtoUP","LOWtoUP",ch,NULL);
        } else{
            execl("./UPtoLOW","UPtoLOW",ch,NULL);
        }
    } else{
        //wait(&ptr);
        //printf("Inside Parent");
        write(fileDes[1],fname,sizeof(fname));
    }
    return 0;
}