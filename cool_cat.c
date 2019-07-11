#include <stdio.h>

int main(int args,char *argv[] ){

	//Stores pointer to a stream representing the open file
	FILE *file;
	//variable to store character for each line
        char str[256];
	//[file.txt] argument is not passed
	if (args ==1){
		//read from stdin since there is no file specified
		file = stdin;
	}
        //if there is second argument for a file
	else if (args == 2){ 
		//open file using fopen. The first parameter of fopen
		//takes the path to a file open the file (argv[1])
		//The second parameter specifies access mode.
		//"r" mean read only. fopen opens the file and returns
		//a pointer to the stream of the open file. It will return
		//NULL if the operations fails.
		file =fopen( argv[1],"r"); 
	}
	//there is more than 2 arguments passed
	else{
		fprintf(stderr,"Incorrect Arguments\n");
		return 0;
	}
	

	if (file){
  		//This call to fgets reads a line from file. 
		//str is an array of characters that stores characters
		//of each line, 256 is the maximum number of characters
		//and file is the path to the file to read from. It returns
		//array of characters and a null pointer if the operation fails.
 		while(fgets(str,256,file)){
                	printf("%s",str);
        	}		
	}
	else{
		//If file points to NULL
		fprintf(stderr,"Error opening file\n");
	}

	return 0;
}
