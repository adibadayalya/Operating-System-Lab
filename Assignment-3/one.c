//Aditya Badayalya
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

	printf("A Message\n");
	printf("PID: %d\n", getpid());
	
	char *argument[]={"ls", ".", NULL};
	
	if(argv[1]!=NULL){		
		argument[1]=argv[1];
	}
	//printf("%s\n",argument[1]);
	execv("/bin/ls", argument);//needs the address of the function which has to be executed hence '/bin/ls'
	return 0;	
}
