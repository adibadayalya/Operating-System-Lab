#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	for(int i =0  ;i<4; i++){
	    int id = fork();
	    if(id > 0 ){	
	    printf("PARENT | PID : %d\tPPID : %d\n",getpid(), getppid());
	    int waitid = wait(NULL);
	    printf("child process %d finished execution\n", waitid);
	}
    else{
    	printf("INSIDE CHILD PROCESS => pid : %d\tppid : %d\n",getpid(), getppid());
        exit(0);
    }

    }
	return 0;
}
