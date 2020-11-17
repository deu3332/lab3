#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	time_t start_time, end_time;
	float result;
	char msg[3][30] = {{"Hello~"},	{"today weather is nice"},
			{"is it?"}
	};
	char input [3][30];
	system("clear");
	
	int i,j,msgs_leng,input_leng,longer_leng, total, chk=0;
		char c;
	
	start_time = time(NULL);
	for(i=0 ; i<3; i++){
		puts(msg[i]);
		scanf("%[^\n]s", input[i]);
		msgs_leng = strlen(input[i]);
		printf("string len : %d. input len : %d", msgs_leng, input_leng);
		total += input_leng;
		
		if (msgs_leng > input_leng) 
			longer_leng = msg_leng;
		else if (msgs_leng <= input_leng) 
			longer_leng = input_leng;
		
		for (j=0; j<longer_leng; j++){
			if(msg[i][j] != input[i][j]) chk++;
	}
	printf("fail input : %d \n", chk);
	chk=0;
	printf("press enter \n\n");
	getchar();
}
	end_time = time(NULL);
	result = (float)(end_time - start_time);
	printf("Average input time : %2.f \n", result/3);
	printf("m/s input typing : %2.f \n", (60/result)*total);
}
