#include <stdio.h>
#include <stdlib.h>

//including the coustom functions
#include "util.c"
#include "read.c"


int main(){
    //read the header part
    unsigned short *buffer = readHeader("test.txt");
    printf("%d\n",buffer[0]);
    long int size = findSize("test.txt");
    //read first 10 charecters from text file
    unsigned char *text = readText("test.txt",size);
    printf("%s\n",text);
    return 0;
}