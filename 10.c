#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
	int shmid;
	int pid;
	char *shared_txt = (char*)malloc(sizeof(char)*15);
	void *shared_memory = (void *)0;

	shmid = shmget((key_t)1234, sizeof(char), 0666|IPC_CREAT);
	if(shmid == -1){
		perror ("shmget failed :");
		exit(0);
	}
	
	shared_memory = shmat(shmid, (void *)0,0);
	if(shared_memory == (void *)-1){
		perror("shmat fail .. : ");
		exit(0);
	}
	shared_txt = (char *) shared_memory;
	pid = fork();
	if(pid ==0){
		shmid = shmget((key_t)1234,sizeof(char),0);
		if(shmid == -1){
			perror("shmget fail..:");
			exit(0);
		}
		shared_memory = shmat(shmid,(void *)0,0666 | IPC_CREAT);
		if(shared_memory == (void *) -1){
			perror("shmat fail.. :");
			exit(0);
		}
		shared_txt = (char *) shared_memory;
		FILE *f;
		f = fopen("testtest.txt" , "r");
		fscanf(f,"%[^\n]s", shared_txt);
		printf("chiled process read testtest.txt\n");
		fclose(f);
	} 	else if (pid>0){
		FILE *f;
		f = fopen("testtest.txt" , "r");
		fscanf(f,"%[^\n]s", shared_txt);
		printf("parent process copy newtestfile.txt file\n");
		wait(1);		
		fclose(f);
}
}










