#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[] ){
	//varaible to store what flag to use
	char flag;
	//pointer to a file stream
	FILE *file;
	if (argc < 4){
		//set file to stdin, reading from the stdin.
		file =stdin;
		//set flag to error flag, if the flag doesn't change to a valid flag,
		//it will print at the end
		flag = 'e';
		//Go through each argument starting from the second argument
		for (int i=1; i< argc; i++){
			//use strcmp to compare argument with flags.
			//strcmp takes in two strings and returns 0 if they are 
			//equal to each other. It returns a value >0 if the first
			//string is greater than the second, and a value < 0 if the 
			//first string is less than the second string.
			//if the argument is not a flag '-c' or '-l',
			//take it as a file path.
			if (strcmp(argv[i],"-c")==0)  flag='c';
			else if (strcmp(argv[i],"-l")==0)  flag ='l';
			//fopen takes a file path given by argv[i] and the access mode
			//"r" which indicates the file is read only. It returns a pointer to 
			//a stream representing the open file. It will return NULL
			//if the operation fails
			else {
				file = fopen(argv[i],"r");	
			}
		}
		//If there is less than three argument, set flag to 'w',
		//which is just printing out the number of words
		if (argc< 3){
			flag = 'w';
		}
	}	
	//If there is more than 3 arguments, output error
	else{
		fprintf(stderr,"Invalid number of arguments\n");
	}

	 //variable to store each character read from file
	 char character;
         //variables to count number of words, lines, and characters
         int  numWord=0;
         int  numLine =0;
         int  numChar =0;
	if (file){
		//fgetc gets the next character from the specified stream
		// and advances the position index for the stream.
		//fgetc is used to get each character from file and it will
		//keep advancing to get next character until it reaches the end of the file.
 		while ((character=fgetc(file))!=EOF){
			//incrememt number of characters
			numChar ++;
			//if there is a space, tab, or new line indicator, increment
			//the number of words
			if((character ==' '||character =='\t'|| character =='\n')){
				numWord ++;
			}
			//if there is a new line indicator, 
			//increment the number of lines
			if (character=='\n'){
				numLine ++;
			}
		}
		//close the file
		fclose(file);
	}
	//if file fails to open, output error
	else{
 		fprintf(stderr,"Error opening file\n");
	}
	
	//based on the flag, output the result. 
	//l flag will output number of lines, c will output number of characters
	//and w will output number of words.
	//if flag is undefined, output error 
	if(flag =='l') printf("\t%d",numLine);	
	else if(flag =='c') printf("\t%d", numChar);
	else if(flag =='w') printf("\t%d", numWord);
	else fprintf(stderr,"Error processing flag");
	

	printf("\n");
	return 0;
}
