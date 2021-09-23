#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(void){
    int PID;
    PID = fork();
    if(PID == 0){
        sleep(5);
        printf("\nInside Child Process: \n");
        printf("MY ID: %d , PARENT ID: %d\n",getpid(),getppid());
    } else {
        printf("Inside Parent Process: \n");
        printf("MY ID: %d , PARENT ID: %d\n",getpid(),getppid());
    }
    return 0;
}