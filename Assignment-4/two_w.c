#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 100

//message structure
struct msg {
	long msg_type;
	char msg_text[100];
} msg;

int main()
{
	key_t key = ftok("abc", 65);;
	int msgid = msgget(key, 0666 | IPC_CREAT);
	msg.msg_type = 1;
	printf("Message Data : ");
	fgets(msg.msg_text,MAX,stdin);
    //send message 
	msgsnd(msgid, &msg, sizeof(msg), 0);
	printf("Message: %s \n", msg.msg_text);
	return 0;
}

