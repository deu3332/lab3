#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>

int main (int argc, char* argv[]){
	
	struct mq_attr attr;	
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 4;	
	char msg[30];
	int stat;
	mqd_t mfd;
	
	mfd = mq_open ("/Syspro3", O_WRONLY, 0666, &attr);
	if(mfd == -1) {
		perror ("open error");
		exit(0);
	}
	printf("write message : ");
	scanf("%[^\n]s",msg);
	int len;
	len = strlen(msg);
	msg[len] = '\0';

	if((mq_send(mfd,msg,attr.mq_msgsize, 1)) == -1) {
		perror("send error");		
		exit(-1);
	}
	
	printf("Close \n");
}
