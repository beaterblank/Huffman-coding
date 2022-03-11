#include <stdio.h>
#include <stdlib.h>

//including the custom functions
#include "code/util.c"
#include "code/read.c"
#include "code/write.c"



void readTest(){
	//read the header part
	unsigned short *buffer = readHeader("test.txt");
	printf("%d\n",buffer[0]);
	//print size
	long int size = findSize("test.txt");
	printf("%ld\n",size);
	//read first 10 characters from text file
	unsigned char *text = readText("test.txt",size);
	printf("%s\n",text);

}

int main(){
	readTest();
	return 0;
}
