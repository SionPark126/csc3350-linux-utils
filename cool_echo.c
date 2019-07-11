#include <stdio.h>

int main(int args,char *argv[] ){
	
	//starting from the second argument to the last argument entered
	for (int i =1; i < args; i++)
	{
		//print each argument and add a space in between
		printf("%s", argv[i]);
		printf(" ");
	}	
	
	//print a new line at the end
	printf("\n");

	return 0;
}
