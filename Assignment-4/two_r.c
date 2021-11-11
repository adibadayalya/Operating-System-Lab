#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg {
	long msg_type;
	char msg_text[100];
} msg;

int main()
{
	key_t key = ftok("abc", 65);;
	int msgid = msgget(key, 0666 | IPC_CREAT);
    //wating for the message
	msgrcv(msgid, &msg, sizeof(msg), 1, 0);
	printf("Message: %s \n",msg.msg_text);
    //removing the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}

