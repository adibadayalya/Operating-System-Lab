#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    int a;
    printf("Main Process ID: %d\n",getpid());
    pid_t C1 = fork();
    if(C1==0){
        printf("Address in Child C1 PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    } else {
        printf("Address in Parent PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    }
    pid_t C2 = fork();
    if(C1==0 && C2==0){
        printf("Address in C1 Child, C2 Child PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    } else if(C1==0 && C2!=0){
        printf("Address in C1 Child, C2 Parent PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    } else if(C1!=0 && C2==0){
        printf("Address in C1 Parent, C2 Child PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    } else {
        printf("Address in C1 Parent, C2 Parent PID: %d , PPID: %d = %p\n",getpid(),getppid(),&a);
    }
    while(1){
        //infinite loop
    }
    return 0;
}