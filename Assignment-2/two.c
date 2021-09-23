#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(void){
    int PID;
    PID = fork();
    if(PID == 0){
        printf("\nInside Child Process: \n");
        printf("MY ID: %d , PARENT ID: %d\n",getpid(),getppid());
        printf("Child is waiting\n");
        exit(0);
    } else {
        printf("Inside Parent Process: \n");
        printf("MY ID: %d , PARENT ID: %d\n",getpid(),getppid());
        sleep(5);
        printf("Parent is Sleeping\n");
        system("ps -el | grep a.out");
    }
    return 0;
}