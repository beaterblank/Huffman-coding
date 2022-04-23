#include "util.c"
#include "read.c"
#include "write.c"
#include "search.c"

void encode(char* fname,char* ftable,char* fdata){
    long int length = findSize(fname);
    char* data = readText(fname,length);
    insert(data);
    countC* arr = arrify();
    buildHeap(arr);
    Hnode* tree = huffmanTree(arr);
    char* chs = getbin(tree,data,length);
    writeTable(ftable);
    writeText(fdata,chs);
}