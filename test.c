#include <stdio.h>
#include <stdlib.h>

#include "code/linklist.c"

int main(){
    list* l = NULL;
    l = insert(l,'a');
    l = insert(l,'b');
    debug(l);
}