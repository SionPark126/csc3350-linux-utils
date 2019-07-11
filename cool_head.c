#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char *argv[] ){
	//variable to store number of lines to print	
	int numLine;	
	//variable to store a pointer to file
	FILE *file;
	//variable to store characters of each line
	char line[256];
	
	if (argc ==4|| argc==3){
		//variable to store argument index
		int count =1;
		//go through each command line arguments starting from the second one 
		while(count < argc){
			//Check for flag -n
			//strcmp takes in two strings and returns 0 if they are the same.
			//If the return value >0, then it indicates that the second string
			//is greater than the first string passed in. And if value < 0, it 
			// means the first string > second string.
			if (strcmp(argv[count],"-n")==0){
				//atoi takes in character string and converts into an integer
				//In this case, atoi takes in the command line argument after
				// -n flag, converts it to an integer. If conversion fails,
				//it returns 0. 
				numLine = atoi(argv[count+1]);
				
				//If conversion to integer fails, then output error
				if (numLine == 0){
					fprintf(stderr,"N value followed after -n flag is invalid\n");
					return 0;
				}
				//Since it took care of -n and N argument, add 2 to the count variable
				count += 2;
			}
			else{
				//If there is a file specified, open the file using fopen.
				//fopen takes in the file and "r" as the second parameter,
				//which indicates the file will be in  "read-only" mode.
				//It returns a pointer to a stream representing the open file.
				//It will return NULL if the operation fails. 
				file = fopen(argv[count],"r");
				count ++;
			}		
		}
	 	if (argc ==3){
			  //If there is no file specified, the program will read from stdin
                          file = stdin;
		}		
	}
	else if (argc ==2){
		//If only file is specified, open the file using fopen.
		//It assumes that the second argument argv[1] is a path to the file.		
		file = fopen(argv[1],"r");
		//Default number of lines to print is 5 if -n flag is not set.
		numLine = 5;
	}
	else if (argc ==1){
		//If no agruments are passed but ./cool_head
		//Use fgets to read line from stdin and print until user hits CTRL+D.
		//The parameters of fgets are (string to store array of chars for each line(line), 
		//maximum number of characters to read(256), stream(stdin)).
		// On success, it returns the first parameter (line). 
		//If there's an error, it will return a null pointer. 
		while (fgets(line, 256, stdin)!= NULL){
			printf("%s",line);
		}		
		return 0;
	}
	else{
		//Print error otherwise.
		fprintf(stderr,"Invalid number arguments\n");
		return 0;
	}
	//Variable to keep track of how may lines have been printed.	
	int countLine =0;
	if(file){
		//Print lines using fgets() until it reaches the specified number of 
		//lines or it reaches the end of the file. fgets reads a line from 
		//file specified by the third parameter(file) and stores it into the string(line). 
		//The maximum number of characters per line is 256.   
		while (countLine < numLine && fgets(line,256,file)){
			printf("%s", line);
			countLine ++;			
		}	
		//close the file that was opened
		fclose(file);
		return 0;
	}
	else{
		//print error if file stores a null pointer
		fprintf(stderr,"Error opening file\n");
	}
	
	return 0;
}

