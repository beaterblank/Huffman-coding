#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//including the custom functions
#include "code/util.c"
#include "code/read.c"
#include "code/write.c"
#include "code/search.c"

void readTest(){
	printf("\nREAD TEST\n");
	//read the header part
	unsigned short *buffer = readHeader("test.txt");
	printf("count : %d\n",buffer[0]);
	//print size
	long int size = findSize("test.txt");
	printf("size :%ld\n",size);
	//read first 10 characters from text file
	char *text = readText("test.txt",size);
	printf("text : \n%s\n",text);
}

void hashTableTest(){
	insert(readText("test.txt",findSize("test.txt")));
	debugTable();
}

// void heapTest(){
// 	printf("\nHASH TABLE TEST\n");
// 	hashTableTest();
// 	printf("\nMIN HEAP TEST\n");
// 	countC* arr = arrify();
// 	printf("\n%d",SIZE);
// 	buildHeap(arr);
// 	debugHeap(arr);
// 	countC small = getMin(arr);
// 	printf("\n%d-smmalest :%d - %d\nNew array :",SIZE,small.charecter,small.count);
// 	debugHeap(arr);
// }


void huffmanTreeTest(){
	printf("\nhashTable : ");
	hashTableTest();
	countC* arr = arrify();
	buildHeap(arr);
	printf("\nMinHeap : ");
	debugHeap(arr);
	Hnode* tree = huffmanTree(arr);
	printf("\nhuffmanTree :");
	print2DUtil(tree,0);
	// char* bin = (char*)malloc(sizeof(char)*(search(tree,'a',0)-1));
	// binstream(tree,'a',bin);
	// printf(">%s",bin);
	//printf("%d",search(tree->right,'a',0));
	charFromTree(tree,'i');
}

int main(){
	readTest();
	huffmanTreeTest();
	return 0;
}
